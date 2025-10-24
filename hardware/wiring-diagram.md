# Wiring Diagram - Marine GPS Anchor Alarm

## Overview
This document provides detailed wiring instructions for connecting the NEO-6M GPS module and active buzzer to the ESP32 development board.

## Components Connection Table

### NEO-6M GPS Module → ESP32

| NEO-6M Pin | ESP32 Pin | Wire Color (Suggested) | Function |
|------------|-----------|------------------------|----------|
| VCC        | 3.3V      | Red                    | Power supply (3.3V) |
| GND        | GND       | Black                  | Ground |
| TX         | GPIO 16   | Yellow                 | GPS transmit → ESP32 RX2 |
| RX         | GPIO 17   | Green                  | GPS receive → ESP32 TX2 |

### Active Buzzer → ESP32

| Buzzer Pin | ESP32 Pin | Wire Color (Suggested) | Function |
|------------|-----------|------------------------|----------|
| VCC / +    | 3.3V or 5V| Red                    | Power supply |
| GND / -    | GND       | Black                  | Ground |
| I/O / S    | GPIO 25   | Blue                   | Signal (PWM control) |

### Power Supply

| Component | Power Source | Notes |
|-----------|--------------|-------|
| ESP32     | USB (5V) or Battery | Via USB port or VIN pin |
| GPS Module| ESP32 3.3V pin | Max 50mA draw |
| Buzzer    | ESP32 3.3V or 5V | Check buzzer voltage rating |

## Visual Wiring Diagram (ASCII)

```
                        ESP32 Dev Board
                    ┌─────────────────────┐
                    │                     │
         ┌──────────┤ 3.3V           GND  ├──────────┐
         │          │                     │          │
         │      ┌───┤ GPIO 16 (RX2)       │          │
         │      │   │                     │          │
         │      │┌──┤ GPIO 17 (TX2)       │          │
         │      ││  │                     │          │
         │      ││┌─┤ GPIO 25             │          │
         │      │││ │                     │          │
         │      │││ └─────────────────────┘          │
         │      │││                                  │
         │      │││        ┌──────┐                  │
         │      │││        │ USB  │  ← Power Supply  │
         │      │││        └──────┘                  │
         │      │││                                  │
         │      │││                                  │
    ┌────┴──────┴┴┴─────┐              ┌────────────┴──────┐
    │   NEO-6M GPS      │              │   Active Buzzer   │
    ├───────────────────┤              ├───────────────────┤
    │ VCC  (Red)        │              │ VCC  (Red)        │
    │ GND  (Black)      │              │ GND  (Black)      │
    │ TX   (Yellow)     │              │ I/O  (Blue)       │
    │ RX   (Green)      │              └───────────────────┘
    └───────────────────┘
```

## Detailed Connection Steps

### Step 1: Prepare Your Workspace
1. Disconnect ESP32 from power
2. Gather all components and jumper wires
3. Have a multimeter ready for testing (optional but recommended)

### Step 2: Connect NEO-6M GPS Module

**Important Notes:**
- NEO-6M operates at 3.3V - do NOT connect to 5V
- TX/RX connections are crossed (GPS TX → ESP32 RX, GPS RX → ESP32 TX)
- Ensure antenna has clear view of sky

**Connections:**
1. **VCC (GPS) → 3.3V (ESP32)**
   - Use red jumper wire
   - Connect to 3.3V pin (NOT 5V or VIN)

2. **GND (GPS) → GND (ESP32)**
   - Use black jumper wire
   - Connect to any GND pin on ESP32

3. **TX (GPS) → GPIO 16 (ESP32)**
   - Use yellow jumper wire
   - GPIO 16 is UART2 RX on ESP32
   - GPS transmits data to ESP32 receive pin

4. **RX (GPS) → GPIO 17 (ESP32)**
   - Use green jumper wire
   - GPIO 17 is UART2 TX on ESP32
   - ESP32 transmits to GPS receive pin

### Step 3: Connect Active Buzzer

**Important Notes:**
- Check your buzzer's voltage rating (3.3V or 5V)
- Active buzzer has polarity - connect correctly
- Some buzzers have 3 pins; use VCC, GND, and I/O (ignore middle pin if present)

**Connections:**
1. **VCC/+ (Buzzer) → 3.3V or 5V (ESP32)**
   - Use red jumper wire
   - If 3.3V buzzer: connect to 3.3V pin
   - If 5V buzzer: connect to VIN pin (when powered via USB)

2. **GND/- (Buzzer) → GND (ESP32)**
   - Use black jumper wire
   - Connect to any GND pin

3. **I/O/S (Buzzer) → GPIO 25 (ESP32)**
   - Use blue jumper wire
   - GPIO 25 supports PWM for tone control

### Step 4: Power Connection

**Option A: USB Power (Development/Testing)**
- Connect USB cable to ESP32
- Powers ESP32, GPS, and buzzer
- Easiest for initial testing

**Option B: Battery Power (Portable Operation)**
- Use 5V power bank with USB output → ESP32 USB port
- OR use 3.7V LiPo battery → ESP32 battery connector (if available)
- OR use 4x AA batteries (6V) with voltage regulator → ESP32 VIN pin

## Pin Reference Chart

### ESP32 DevKit V1 Pin Layout

```
                     ┌──────────┐
                     │   USB    │
                     └──────────┘
                          │
        ┌─────────────────┴─────────────────┐
        │                                   │
    GND │●                               ●  │ VIN (5V in)
    3.3V│●  ← GPS & Buzzer Power        ●  │ GND
     EN │●                               ●  │ GPIO 13
     VP │●                               ●  │ GPIO 12
     VN │●                               ●  │ GPIO 14
  GPIO34│●                               ●  │ GPIO 27
  GPIO35│●                               ●  │ GPIO 26
  GPIO32│●                               ●  │ GPIO 25  ← Buzzer Signal
  GPIO33│●                               ●  │ GPIO 33
  GPIO25│●                               ●  │ GPIO 32
  GPIO26│●                               ●  │ GPIO 35
  GPIO27│●                               ●  │ GPIO 34
  GPIO14│●                               ●  │ GPIO 39
  GPIO12│●                               ●  │ GPIO 36
    GND │●                               ●  │ EN
  GPIO13│●                               ●  │ 3.3V
    SD2 │●                               ●  │ GND
    SD3 │●                               ●  │ GPIO 15
    CMD │●                               ●  │ GPIO 2
     5V │●                               ●  │ GPIO 0
        │                                   │
  GPIO17│●  ← GPS RX                  ●    │ GPIO 4
  GPIO16│●  ← GPS TX                  ●    │ GPIO 16
        │                                   │
        └───────────────────────────────────┘
```

## Testing Connections

### Test 1: Power Test
1. Connect only power and ground to GPS
2. Power on ESP32
3. GPS LED should light up (may blink after ~30 seconds)
4. If no LED: check VCC/GND connections

### Test 2: GPS Data Test
1. Upload this test sketch:
```
void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
}
void loop() {
  while (Serial2.available()) {
    Serial.write(Serial2.read());
  }
}
```
2. Open Serial Monitor at 115200 baud
3. You should see NMEA sentences (starting with $GP...)
4. If nothing: check TX/RX connections

### Test 3: Buzzer Test
1. Upload this test sketch:
```
#define BUZZER_PIN 25
void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}
void loop() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
  delay(500);
}
```
2. Buzzer should beep every second
3. If silent: check buzzer polarity and GPIO 25 connection

## Troubleshooting

### GPS Not Working
| Problem | Possible Cause | Solution |
|---------|----------------|----------|
| No LED on GPS | No power | Check 3.3V and GND connections |
| No data in Serial | Wrong pins | Verify GPIO 16/17 connections |
| Garbage data | Wrong baud rate | Ensure 9600 baud for NEO-6M |
| No GPS fix | No sky view | Move outdoors, wait 30-60 seconds |

### Buzzer Issues
| Problem | Possible Cause | Solution |
|---------|----------------|----------|
| No sound | Wrong voltage | Check buzzer voltage rating |
| Continuous sound | Wrong buzzer type | Ensure "active" buzzer, not passive |
| Weak sound | Insufficient power | Connect to 5V instead of 3.3V |
| No sound | Wrong polarity | Swap VCC and GND connections |

### Power Issues
| Problem | Possible Cause | Solution |
|---------|----------------|----------|
| ESP32 won't boot | Insufficient power | Use quality USB cable/power supply |
| Random resets | Power fluctuations | Add capacitor between 3.3V and GND |
| GPS not locking | Weak power | Use dedicated power supply, not PC USB |

## Wire Management Tips

1. **Use color-coded wires** for easy troubleshooting
2. **Keep wires short** to reduce interference
3. **Separate power and signal wires** when possible
4. **Label connections** with tape or heat shrink
5. **Use a breadboard** for prototyping before soldering

## Enclosure Considerations

When mounting in an enclosure:
- **GPS antenna** must face upward with clear sky view
- **Buzzer** should face outward or have sound holes
- **ESP32** should have ventilation for heat dissipation
- **Waterproof** for marine environment (IP65+ rated box)
- **Access** to USB port for programming/charging

## Safety Notes

⚠️ **Important Safety Information:**
- Never connect GPS to 5V (it requires 3.3V)
- Double-check polarity before powering on
- Avoid ESD (electrostatic discharge) damage - touch ground before handling
- Don't exceed ESP32's 3.3V output current limit (combined ~1A max)
- Use marine-grade waterproof enclosure for boat installation
- Ensure buzzer volume is appropriate (not too loud in confined spaces)

## Next Steps

After completing wiring:
1. ✅ Verify all connections match this diagram
2. ✅ Run test sketches for each component
3. ✅ Upload main anchor_alarm.ino
4. ✅ Test outdoors for GPS fix
5. ✅ Configure WiFi/Bluetooth settings
6. ✅ Install in waterproof enclosure

---
**Last Updated:** October 24, 2025  
**Tested With:** ESP32 DevKit V1, NEO-6M GPS, 5V Active Buzzer
