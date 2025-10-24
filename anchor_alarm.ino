#include <TinyGPSPlus.h>
#include <HardwareSerial.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <BluetoothSerial.h>

// USER CONFIGURATION
const char* WIFI_SSID     = "YOUR_WIFI_SSID";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";
const char* IFTTT_URL     = "https://maker.ifttt.com/trigger/boat_drift_alert/with/key/YOUR_IFTTT_KEY";

const float ALARM_RADIUS_METERS = 50.0;   // Drift threshold
#define GPS_RX_PIN 16      // ESP32 RX2
#define GPS_TX_PIN 17      // ESP32 TX2
#define BUZZER_PIN 25      // PWM-capable pin

#define GPS_UPDATE_INTERVAL 2000
#define ALARM_CHECK_INTERVAL 5000
#define BUZZER_CHANNEL 0
#define BUZZER_FREQUENCY 2000

// OBJECTS & VARIABLES
TinyGPSPlus gps;
HardwareSerial gpsSerial(2);     // Use UART2 for GPS
BluetoothSerial SerialBT;

double anchorLat = 0.0;
double anchorLon = 0.0;
bool anchorSet = false;
bool alarmActive = false;
unsigned long lastGPSCheck = 0;
unsigned long lastAlarmCheck = 0;
int notificationMethod = 0; // 0=WiFi, 1=Bluetooth, 2=IFTTT

// FUNCTION PROTOTYPES
void setupWiFi();
void setupBluetooth();
void setupBuzzer();
void setAnchorPosition();
float calculateDistance(double lat1, double lon1, double lat2, double lon2);
void checkDrift();
void activateAlarm(float distance);
void deactivateAlarm();
void soundBuzzer(int duration);
void sendWiFiNotification(float distance);
void sendBluetoothNotification(float distance);
void sendIFTTTNotification(float distance);

// SETUP
void setup() {
  Serial.begin(115200);
  gpsSerial.begin(9600, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);

  Serial.println("==== Marine GPS Anchor Alarm ====");

  setupBuzzer();
  soundBuzzer(150);

  // Select notification method
  Serial.println("\n0 = WiFi HTTP POST | 1 = Bluetooth | 2 = IFTTT");
  Serial.println("Select method using Serial Monitor (within 10s):");
  unsigned long startTime = millis();
  while (millis() - startTime < 10000) {
    if (Serial.available()) {
      notificationMethod = Serial.parseInt();
      break;
    }
  }
  Serial.print("Using notification method: ");
  Serial.println(notificationMethod);

  if (notificationMethod == 0 || notificationMethod == 2)
    setupWiFi();
  else if (notificationMethod == 1)
    setupBluetooth();

  Serial.println("Waiting for GPS fix...");
  while (!gps.location.isValid()) {
    while (gpsSerial.available() > 0) gps.encode(gpsSerial.read());
    delay(200);
  }
  setAnchorPosition();
  Serial.println("==== Ready! Monitoring for drift ====");
}

// ===== MAIN LOOP =====
void loop() {
  while (gpsSerial.available() > 0) gps.encode(gpsSerial.read());
  if (millis() - lastAlarmCheck >= ALARM_CHECK_INTERVAL) {
    lastAlarmCheck = millis();
    if (gps.location.isValid() && anchorSet) checkDrift();
    else {
      Serial.println("WARNING: GPS FIX LOST!");
      soundBuzzer(100);
    }
  }
  if (millis() - lastGPSCheck >= GPS_UPDATE_INTERVAL) {
    lastGPSCheck = millis();
    if (gps.location.isValid()) {
      Serial.print("Satellites: "); Serial.print(gps.satellites.value());
      Serial.print(" | Position: "); Serial.print(gps.location.lat(), 6);
      Serial.print(", "); Serial.println(gps.location.lng(), 6);
    }
  }
}

// SETUP UTILS
void setupWiFi() {
  Serial.print("Connecting WiFi: "); Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  int tries = 0;
  while (WiFi.status() != WL_CONNECTED && tries < 20) {
    delay(500); Serial.print(".");
    tries++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi Connected!"); Serial.print("IP: "); Serial.println(WiFi.localIP());
  } else Serial.println("\nWiFi FAILED. No network alerts.");
}

void setupBluetooth() {
  if (!SerialBT.begin("ESP32_AnchorAlarm")) Serial.println("Bluetooth failed!");
  else Serial.println("Bluetooth ON: ESP32_AnchorAlarm");
}

void setupBuzzer() {
  ledcSetup(BUZZER_CHANNEL, BUZZER_FREQUENCY, 8); // channel, freq, res
  ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL);
}

// ANCHOR
void setAnchorPosition() {
  if (gps.location.isValid()) {
    anchorLat = gps.location.lat();
    anchorLon = gps.location.lng();
    anchorSet = true;
    Serial.println("\n*** ANCHOR SET ***");
    Serial.print("Lat: "); Serial.println(anchorLat, 6);
    Serial.print("Lon: "); Serial.println(anchorLon, 6);
    for (int i=0; i<3; i++) { soundBuzzer(100); delay(80);}
  }
}

// DISTANCE CALCULATION
float calculateDistance(double lat1, double lon1, double lat2, double lon2) {
  // Haversine formula
  const float R = 6371000.0;
  double dLat = (lat2-lat1) * DEG_TO_RAD;
  double dLon = (lon2-lon1) * DEG_TO_RAD;
  double a = sin(dLat/2)*sin(dLat/2) +
    cos(lat1*DEG_TO_RAD)*cos(lat2*DEG_TO_RAD)*sin(dLon/2)*sin(dLon/2);
  double c = 2*atan2(sqrt(a), sqrt(1-a));
  return R * c;
}

// DRIFT CHECK
void checkDrift() {
  double currLat = gps.location.lat();
  double currLon = gps.location.lng();
  float distance = calculateDistance(anchorLat, anchorLon, currLat, currLon);

  Serial.print("Distance: ");
  Serial.print(distance, 1); Serial.println(" m");

  if (distance > ALARM_RADIUS_METERS) {
    if (!alarmActive) activateAlarm(distance);
  } else {
    if (alarmActive) deactivateAlarm();
  }
}

// ALARM LOGIC
void activateAlarm(float distance) {
  alarmActive = true;
  Serial.println("\n!!! DRIFT ALARM !!!");
  Serial.print("Drifted: "); Serial.print(distance,1); Serial.println("m");
  for (int i=0; i<5; i++) { soundBuzzer(200); delay(150);}
  if (notificationMethod == 0) sendWiFiNotification(distance);
  else if (notificationMethod == 1) sendBluetoothNotification(distance);
  else if (notificationMethod == 2) sendIFTTTNotification(distance);
}

void deactivateAlarm() {
  alarmActive = false;
  Serial.println("*** Alarm deactivated; within safe radius ***");
  soundBuzzer(400);
}

void soundBuzzer(int duration) {
  ledcWriteTone(BUZZER_CHANNEL, BUZZER_FREQUENCY);
  delay(duration);
  ledcWriteTone(BUZZER_CHANNEL, 0);
}

// NOTIFICATIONS
void sendWiFiNotification(float distance) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "http://YOUR_SERVER_IP/anchor_alert"; // Replace as needed
    http.begin(url);
    http.addHeader("Content-Type","application/json");
    String payload = "{\"alert\":\"drift_detected\",\"distance\":" +
      String(distance,2)+",\"lat\":"+String(gps.location.lat(),6)+",\"lon\":"+String(gps.location.lng(),6)+"}";
    int code = http.POST(payload);
    Serial.print("WiFi Notification response: "); Serial.println(code);
    http.end();
  } else Serial.println("WiFi not connected; can't send alert.");
}

void sendBluetoothNotification(float distance) {
  if (SerialBT.connected()) {
    String msg = "ANCHOR DRIFT ALERT!\nDistance: " + String(distance,1) +
      " meters\nLat: " + String(gps.location.lat(),6) +
      "\nLon: " + String(gps.location.lng(),6);
    SerialBT.println(msg);
    Serial.println("Alert sent via Bluetooth.");
  } else Serial.println("Bluetooth not connected; can't alert.");
}

void sendIFTTTNotification(float distance) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    WiFiClient client;
    http.begin(client, IFTTT_URL);
    http.addHeader("Content-Type","application/json");
    String data = "{\"value1\":\"" + String(distance,1) +
      "\",\"value2\":\"" + String(gps.location.lat(),6) +
      "\",\"value3\":\"" + String(gps.location.lng(),6) + "\"}";
    int code = http.POST(data);
    Serial.print("IFTTT Notification response: "); Serial.println(code);
    http.end();
  } else Serial.println("WiFi not connected; can't use IFTTT.");
}
