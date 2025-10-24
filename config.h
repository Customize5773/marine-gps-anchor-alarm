#ifndef CONFIG_H
#define CONFIG_H

// WIFI CONFIGURATION
// Replace with your WiFi network credentials
const char* WIFI_SSID     = "YOUR_WIFI_SSID";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

// WiFi connection settings
#define WIFI_TIMEOUT_MS         20000    // 20 seconds to connect
#define WIFI_RECONNECT_INTERVAL 30000    // Try reconnect every 30 seconds

// GPS CONFIGURATION
// Hardware serial pins for NEO-6M GPS module
#define GPS_RX_PIN              16       // ESP32 GPIO 16 (RX2) connects to GPS TX
#define GPS_TX_PIN              17       // ESP32 GPIO 17 (TX2) connects to GPS RX
#define GPS_BAUD_RATE           9600     // NEO-6M default baud rate

// GPS timing settings
#define GPS_UPDATE_INTERVAL     2000     // Update GPS display every 2 seconds (ms)
#define GPS_FIX_TIMEOUT         300000   // Wait max 5 minutes for initial GPS fix (ms)

// ALARM CONFIGURATION
// Drift detection settings
#define ALARM_RADIUS_METERS     50.0     // Alert if boat drifts more than 50 meters
#define ALARM_CHECK_INTERVAL    5000     // Check drift every 5 seconds (ms)

// Buzzer settings
#define BUZZER_PIN              25       // ESP32 GPIO for buzzer (PWM-capable)
#define BUZZER_CHANNEL          0        // LEDC PWM channel (0-15)
#define BUZZER_FREQUENCY        2000     // Buzzer tone frequency in Hz
#define BUZZER_RESOLUTION       8        // PWM resolution (8-bit = 0-255)

// Alarm behavior
#define ALARM_BEEP_COUNT        5        // Number of beeps when alarm triggers
#define ALARM_BEEP_DURATION     200      // Duration of each beep in ms
#define ALARM_BEEP_INTERVAL     150      // Pause between beeps in ms

// NOTIFICATION CONFIGURATION
// Notification method (set during runtime via Serial Monitor)
// 0 = WiFi HTTP POST
// 1 = Bluetooth Serial
// 2 = IFTTT Webhook
#define DEFAULT_NOTIFICATION_METHOD  0

// Selection timeout
#define NOTIFICATION_SELECT_TIMEOUT  10000  // 10 seconds to select via Serial

// WIFI NOTIFICATION SETTINGS
// Custom HTTP POST endpoint (for notification method 0)
const char* HTTP_POST_URL = "http://192.168.1.100/anchor_alert";  // Replace with your server
#define HTTP_POST_TIMEOUT     5000       // HTTP request timeout in ms

// IFTTT NOTIFICATION SETTINGS 
// IFTTT Webhook configuration (for notification method 2)
// Get your key from: https://ifttt.com/maker_webhooks/settings
const char* IFTTT_EVENT_NAME = "boat_drift_alert";
const char* IFTTT_KEY        = "YOUR_IFTTT_KEY_HERE";
const char* IFTTT_URL        = "https://maker.ifttt.com/trigger/boat_drift_alert/with/key/YOUR_IFTTT_KEY_HERE";

// BLUETOOTH CONFIGURATION
// Bluetooth device name (for notification method 1)
const char* BLUETOOTH_DEVICE_NAME = "ESP32_AnchorAlarm";

// SERIAL CONFIGURATION
#define SERIAL_BAUD_RATE        115200   // Serial monitor baud rate
#define SERIAL_DEBUG            true     // Enable/disable debug messages

// GPS ACCURACY SETTINGS
#define MIN_SATELLITES          4        // Minimum satellites for reliable fix
#define MAX_HDOP                5.0      // Maximum acceptable HDOP (Horizontal Dilution of Precision)

// POWER MANAGEMENT
// Enable deep sleep when no movement detected (future feature)
#define ENABLE_DEEP_SLEEP       false
#define DEEP_SLEEP_DURATION     60       // Sleep duration in seconds

// ADVANCED SETTINGS
// GPS warm-up time
#define GPS_WARMUP_TIME         1000     // Wait 1 second for GPS module to stabilize

// Startup beep pattern
#define STARTUP_BEEP_COUNT      2        // Number of beeps at startup
#define STARTUP_BEEP_DURATION   150      // Duration of startup beeps

// Anchor set confirmation
#define ANCHOR_BEEP_COUNT       3        // Number of beeps when anchor is set
#define ANCHOR_BEEP_DURATION    100      // Duration of anchor beeps
#define ANCHOR_BEEP_INTERVAL    80       // Pause between anchor beeps

// Alarm deactivation beep
#define DEACTIVATE_BEEP_DURATION 400     // Single long beep when back in radius

// GPS data validity check
#define GPS_CHARS_THRESHOLD     10       // Minimum chars processed to confirm GPS connection

// DISTANCE CALCULATION
// Earth radius for Haversine formula (meters)
#define EARTH_RADIUS_METERS     6371000.0

// FEATURE FLAGS
// Enable/disable specific features
#define ENABLE_WIFI_NOTIFICATION    true
#define ENABLE_BT_NOTIFICATION      true
#define ENABLE_IFTTT_NOTIFICATION   true
#define ENABLE_LED_INDICATOR        false  // Future feature
#define ENABLE_OLED_DISPLAY         false  // Future feature

// LED INDICATOR (Optional - Future Feature)
#define LED_STATUS_PIN          2        // ESP32 built-in LED (GPIO 2)
#define LED_GPS_BLINK_INTERVAL  1000     // Blink every second when GPS active
#define LED_ALARM_BLINK_INTERVAL 250     // Fast blink when alarm active

// OLED DISPLAY (Optional - Future Feature)
#define OLED_SCREEN_WIDTH       128      // OLED display width in pixels
#define OLED_SCREEN_HEIGHT      64       // OLED display height in pixels
#define OLED_I2C_ADDRESS        0x3C     // I2C address for OLED
#define OLED_SDA_PIN            21       // I2C SDA pin
#define OLED_SCL_PIN            22       // I2C SCL pin

// EMAIL NOTIFICATION (Optional - Future Feature)
#define SMTP_HOST               "smtp.gmail.com"
#define SMTP_PORT               465
const char* SMTP_USER     = "your_email@gmail.com";
const char* SMTP_PASSWORD = "your_app_password";
const char* RECIPIENT_EMAIL = "recipient@example.com";

// DEBUGGING MACROS
#if SERIAL_DEBUG
  #define DEBUG_PRINT(x)     Serial.print(x)
  #define DEBUG_PRINTLN(x)   Serial.println(x)
  #define DEBUG_PRINTF(...)  Serial.printf(__VA_ARGS__)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
  #define DEBUG_PRINTF(...)
#endif

// VERSION INFORMATION
#define FIRMWARE_VERSION        "1.0.0"
#define BUILD_DATE              __DATE__
#define BUILD_TIME              __TIME__

// HARDWARE BOARD DETECTION
// Automatically detect ESP32 board type (optional)
#ifdef ARDUINO_ESP32_DEV
  #define BOARD_TYPE "ESP32 Dev Module"
#elif defined(ARDUINO_ESP32S3_DEV)
  #define BOARD_TYPE "ESP32-S3"
#elif defined(ARDUINO_ESP32C3_DEV)
  #define BOARD_TYPE "ESP32-C3"
#else
  #define BOARD_TYPE "ESP32"
#endif

// SAFETY CHECKS
// Compile-time validation
#if ALARM_RADIUS_METERS < 10
  #warning "ALARM_RADIUS_METERS is very small (<10m). GPS accuracy may cause false alarms."
#endif

#if ALARM_RADIUS_METERS > 1000
  #warning "ALARM_RADIUS_METERS is very large (>1000m). Consider reducing for better sensitivity."
#endif

#if GPS_UPDATE_INTERVAL > ALARM_CHECK_INTERVAL
  #error "GPS_UPDATE_INTERVAL cannot be greater than ALARM_CHECK_INTERVAL"
#endif

// CREDENTIAL OVERRIDE
// If you create config_local.h, it will override settings above
// This keeps your credentials out of version control
#if __has_include("config_local.h")
  #include "config_local.h"
  #define USING_LOCAL_CONFIG true
  #warning "Using config_local.h - credentials are customized"
#endif

#endif // CONFIG_H
