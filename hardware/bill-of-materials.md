# Bill of Materials (BOM) - Marine GPS Anchor Alarm

## Complete Parts List

This document lists all components needed to build the Marine GPS Anchor Alarm system.

## Essential Components

### 1. Microcontroller

| Item | Specification | Qty | Unit Price | Total | Where to Buy |
|------|--------------|-----|------------|-------|--------------|
| ESP32 Development Board | ESP32-WROOM-32 DevKit V1 or compatible<br>• Dual-core 240MHz<br>• WiFi + Bluetooth<br>• 30 GPIO pins<br>• USB programming | 1 | $6-8 | $6-8 | [AliExpress](https://www.aliexpress.com/wholesale?SearchText=esp32+devkit)<br>[Amazon](https://www.amazon.com/s?k=esp32+development+board)<br>[Adafruit](https://www.adafruit.com/product/3405) |

**Recommended Models:**
- ESP32 DevKit V1 (most common)
- ESP32-WROOM-32 DevKit
- DOIT ESP32 DevKit V1
- Any ESP32 board with at least 30 pins

### 2. GPS Module

| Item | Specification | Qty | Unit Price | Total | Where to Buy |
|------|--------------|-----|------------|-------|--------------|
| NEO-6M GPS Module | U-blox NEO-6M with ceramic antenna<br>• Accuracy: ±2.5m<br>• Update rate: 1-10Hz<br>• Operating voltage: 3.3-5V<br>• UART interface<br>• Includes antenna | 1 | $8-12 | $8-12 | [AliExpress](https://www.aliexpress.com/wholesale?SearchText=neo+6m+gps)<br>[Amazon](https://www.amazon.com/s?k=neo+6m+gps+module)<br>[Banggood](https://www.banggood.com/search/neo-6m-gps.html) |

**What's Included:**
- NEO-6M GPS module (GY-GPS6MV2)
- Ceramic patch antenna (25×25mm)
- 4-pin header
- Sometimes includes battery backup

### 3. Audio Output

| Item | Specification | Qty | Unit Price | Total | Where to Buy |
|------|--------------|-----|------------|-------|--------------|
| Active Buzzer Module | 5V Active Buzzer<br>• Voltage: 3.3-5V compatible<br>• Type: Active (built-in oscillator)<br>• Sound: 85dB typical<br>• Frequency: ~2kHz | 1 | $1-2 | $1-2 | [AliExpress](https://www.aliexpress.com/wholesale?SearchText=5v+active+buzzer)<br>[Amazon](https://www.amazon.com/s?k=5v+active+buzzer+module)<br>[SparkFun](https://www.sparkfun.com/products/7950) |

**Note:** Ensure you get "ACTIVE" buzzer, not passive. Active buzzers have built-in oscillator.

### 4. Wiring & Connectors

| Item | Specification | Qty | Unit Price | Total | Where to Buy |
|------|--------------|-----|------------|-------|--------------|
| Jumper Wires | Female-to-Female, 20cm length<br>• 40pcs per pack<br>• 22 AWG<br>• Color-coded | 1 pack | $2-3 | $2-3 | [AliExpress](https://www.aliexpress.com/wholesale?SearchText=dupont+jumper+wires)<br>[Amazon](https://www.amazon.com/s?k=dupont+jumper+wires) |
| Micro USB Cable | USB-A to Micro-USB<br>• 1m length minimum<br>• Data + Power capable | 1 | $2-3 | $2-3 | Any electronics store |

**You'll Need:**
- 4× Female-to-Female wires for GPS
- 3× Female-to-Female wires for buzzer
- Total: 7 wires minimum

---

## Power Options

Choose ONE of the following power options based on your use case:

### Option A: USB Power Bank (Recommended for Testing)

| Item | Specification | Qty | Unit Price | Total | Where to Buy |
|------|--------------|-----|------------|-------|--------------|
| USB Power Bank | 10,000mAh capacity<br>• 5V / 2A output<br>• Dual USB ports<br>• Runtime: ~8-12 hours | 1 | $10-15 | $10-15 | [Amazon](https://www.amazon.com/s?k=10000mah+power+bank)<br>Any electronics store |

**Pros:** Easy, rechargeable, long runtime  
**Cons:** Bulky for permanent installation

### Option B: LiPo Battery with Charging Circuit

| Item | Specification | Qty | Unit Price | Total | Where to Buy |
|------|--------------|-----|------------|-------|--------------|
| 18650 LiPo Battery | 3.7V 2500-3000mAh<br>• Rechargeable<br>• Protected cell | 1-2 | $5-8 each | $10-16 | [18650 Battery Store](https://www.18650batterystore.com/)<br>[AliExpress](https://www.aliexpress.com/wholesale?SearchText=18650+battery) |
| 18650 Battery Holder | 1× or 2× cell holder<br>• With JST connector<br>• On/off switch | 1 | $2-3 | $2-3 | [AliExpress](https://www.aliexpress.com/wholesale?SearchText=18650+holder+jst) |
| TP4056 Charging Module | LiPo charger with protection<br>• Micro-USB input<br>• 1A charging current | 1 | $1-2 | $1-2 | [AliExpress](https://www.aliexpress.com/wholesale?SearchText=tp4056) |
| 5V Boost Converter | 3.7V to 5V step-up<br>• 1A output minimum | 1 | $2-3 | $2-3 | [AliExpress](https://www.aliexpress.com/wholesale?SearchText=5v+boost+converter) |

**Pros:** Compact, rechargeable, good runtime  
**Cons:** Requires assembly, need voltage regulation

### Option C: AA Battery Pack

| Item | Specification | Qty | Unit Price | Total | Where to Buy |
|------|--------------|-----|------------|-------|--------------|
| 4× AA Battery Holder | 6V output (4×1.5V)<br>• With barrel jack or JST connector<br>• On/off switch | 1 | $3-5 | $3-5 | [Amazon](https://www.amazon.com/s?k=4+aa+battery+holder)<br>[Adafruit](https://www.adafruit.com/product/830) |
| AA Batteries | Alkaline or NiMH rechargeable<br>• 1.5V each | 4 | $0.50-1 | $2-4 | Any store |
| 5V Voltage Regulator | LM7805 or buck converter<br>• 6V input, 5V output<br>• 1A minimum | 1 | $1-2 | $1-2 | [AliExpress](https://www.aliexpress.com/wholesale?SearchText=lm7805) |

**Pros:** Easy to find batteries, simple  
**Cons:** Need replacement, shorter runtime

---

## Optional Components

### Display & Indicators

| Item | Specification | Qty | Unit Price | Total | Purpose |
|------|--------------|-----|------------|-------|---------|
| 0.96" OLED Display | I2C interface, 128×64 pixels<br>• SSD1306 driver | 1 | $3-5 | $3-5 | Show GPS status, distance |
| 5mm LED | Red or green<br>• With 220Ω resistor | 2 | $0.25 each | $0.50 | Status indicator |

### Enclosure & Protection

| Item | Specification | Qty | Unit Price | Total | Purpose |
|------|--------------|-----|------------|-------|---------|
| Waterproof Box | IP65 or IP67 rated<br>• 100×68×50mm (min)<br>• Clear lid (for LED visibility) | 1 | $8-15 | $8-15 | Protect electronics from water |
| Cable Glands | PG7 or PG9 size<br>• Waterproof cable entry | 2 | $1 each | $2 | GPS antenna cable, power cable |
| Silica Gel Packets | Desiccant for moisture control | 2-3 | $0.50 | $1 | Prevent condensation |

### Mounting & Hardware

| Item | Specification | Qty | Unit Price | Total | Purpose |
|------|--------------|-----|------------|-------|---------|
| Velcro Strips | Self-adhesive, marine-grade | 1 pack | $3-5 | $3-5 | Mount enclosure to boat |
| Toggle Switch | SPST, waterproof rated | 1 | $2-3 | $2-3 | Power on/off |
| Heat Shrink Tubing | Assorted sizes | 1 pack | $3-5 | $3-5 | Protect solder connections |

### Solar Option (Advanced)

| Item | Specification | Qty | Unit Price | Total | Purpose |
|------|--------------|-----|------------|-------|---------|
| 5V Solar Panel | 5W, 1A output<br>• Weatherproof | 1 | $10-15 | $10-15 | Continuous power/charging |
| Solar Charge Controller | 5V USB output<br>• LiPo battery management | 1 | $5-8 | $5-8 | Regulate solar charging |

---

## Tools Required

### Essential Tools

| Tool | Purpose | Estimated Cost |
|------|---------|----------------|
| Soldering Iron | Solder headers (if needed) | $15-30 (one-time) |
| Solder Wire | 0.8mm rosin-core | $5 |
| Wire Strippers | Strip wire insulation | $10-15 |
| Side Cutters | Cut wires to length | $5-10 |
| Multimeter | Test connections, voltage | $10-20 |
| Hot Glue Gun | Secure components | $5-10 |
| Phillips Screwdriver | Mount components in enclosure | $5 |

### Optional Tools

| Tool | Purpose | Estimated Cost |
|------|---------|----------------|
| Helping Hands | Hold components while soldering | $10-15 |
| Heat Gun | Shrink heat-shrink tubing | $15-25 |
| Drill + Bits | Make holes in enclosure | $20-40 |
| Desoldering Pump | Fix mistakes | $5-10 |

---

## Total Cost Breakdown

### Minimal Setup (Buzzer Only, USB Power)
| Component | Price |
|-----------|-------|
| ESP32 Dev Board | $6-8 |
| NEO-6M GPS Module | $8-12 |
| Active Buzzer | $1-2 |
| Jumper Wires | $2-3 |
| Micro USB Cable | $2-3 |
| USB Power Bank | $10-15 |
| **Total** | **$29-43** |

### Standard Setup (With Enclosure)
| Component | Price |
|-----------|-------|
| Minimal Setup | $29-43 |
| Waterproof Enclosure | $8-15 |
| Cable Glands | $2 |
| Mounting Hardware | $3-5 |
| **Total** | **$42-65** |

### Advanced Setup (Display + Solar)
| Component | Price |
|-----------|-------|
| Standard Setup | $42-65 |
| OLED Display | $3-5 |
| LED Indicators | $0.50 |
| Solar Panel | $10-15 |
| Solar Charge Controller | $5-8 |
| LiPo Batteries | $10-16 |
| **Total** | **$71-109** |

---

## Purchasing Recommendations

### Where to Buy

#### Budget Option (Lowest Cost, Longer Shipping)
- **AliExpress**: Best prices, ships from China, 2-4 weeks delivery
- **Banggood**: Similar to AliExpress

#### Balanced Option (Good Price, Faster Shipping)
- **Amazon**: Prime shipping available, slightly higher cost
- **eBay**: Mix of local and international sellers

#### Premium Option (Fastest, Best Quality)
- **Adafruit**: High-quality components, US-based, excellent support
- **SparkFun**: Similar to Adafruit
- **DigiKey**: Huge selection, fast shipping, professional-grade

### Money-Saving Tips

1. **Buy kits**: Many sellers offer ESP32 + sensors starter kits
2. **Bulk purchase**: Get 2-3× components for future projects
3. **Local electronics stores**: No shipping costs
4. **Reuse components**: Old projects may have usable parts
5. **Wait for sales**: Black Friday, Prime Day, etc.

### Quality Considerations

✅ **What to Look For:**
- ESP32 boards with CP2102 or CH340 USB chip (reliable)
- NEO-6M with included antenna
- Active buzzer with at least 80dB rating
- Quality jumper wires (not too flimsy)

❌ **What to Avoid:**
- ESP32 clones without proper labeling
- GPS modules without antenna included
- Passive buzzers (won't work with this code)
- Very cheap power banks (poor battery quality)

---

## Component Alternatives

### ESP32 Alternatives
- **ESP32-S3**: Newer, more powerful (fully compatible)
- **ESP32-C3**: Budget option (requires minor code changes)
- **ESP32-WROOM-32U**: With external antenna connector

### GPS Alternatives
- **NEO-M8N**: Better accuracy (±2m), slightly more expensive
- **Beitian BN-880**: Includes compass, larger antenna
- **GT-U7**: Cheaper alternative, similar performance

### Buzzer Alternatives
- **Piezo Speaker**: Louder, more annoying (good for alarms!)
- **3V Active Buzzer**: Lower power consumption
- **12V Marine Horn**: Very loud (requires relay and 12V power)

---

## Compatibility Notes

### ESP32 Board Compatibility
This project works with:
- ✅ ESP32 DevKit V1 (most common)
- ✅ ESP32-WROOM-32
- ✅ NodeMCU-32S
- ✅ DOIT ESP32
- ✅ ESP32-S2/S3 (newer variants)

May require pin changes for:
- ⚠️ ESP32-CAM (limited GPIO)
- ⚠️ ESP32-C3 (different GPIO layout)

### GPS Module Compatibility
Works with:
- ✅ NEO-6M (tested)
- ✅ NEO-7M, NEO-8M, NEO-M9N (better accuracy)
- ✅ Any GPS with UART output (NMEA sentences)

---

## Storage & Organization

Recommended storage:
- **Component organizer box**: Keep small parts sorted
- **Anti-static bags**: Store ESP32 when not in use
- **Labeled containers**: Mark each component type
- **Spare parts**: Keep extra wires, resistors

---

## Warranty & Support

- **ESP32**: Usually no warranty, but very reliable
- **GPS modules**: 30-90 days seller warranty typical
- **Power banks**: 6-12 months manufacturer warranty
- **Keep receipts**: For returns/exchanges

---

## Last Updated
**Date:** October 24, 2025  
**Prices:** Based on October 2025 market rates (USD)  
**Tested Configuration:** ESP32 DevKit V1 + NEO-6M + 5V Active Buzzer

---
