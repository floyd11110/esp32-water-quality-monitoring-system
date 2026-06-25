# esp32-water-quality-monitoring-system
ESP32 water quality monitoring prototype with pH sensor, DS18B20 temperature sensor, pump, heater, and Peltier control.

# ESP32 Water Quality Monitoring and Temperature Control System

This repository documents my ESP32-based water quality monitoring prototype.

The project starts with individual sensor tests, then expands into a complete system with pH monitoring, temperature monitoring, water circulation, heater control, and Peltier cooling.

## Project Status

- ✅ pH sensor test using ESP32 analog input
- ✅ DS18B20 waterproof temperature sensor test
- ⬜ Water pump control
- ⬜ DC heater control
- ⬜ Peltier cooling control
- ⬜ Full automatic water quality system

## Hardware Used

- ESP32 development board
- pH sensor module with BNC probe
- DS18B20 waterproof temperature sensor
- recommended use temp sensor driver
- DC water pump
- DC heater
- Peltier module
- MOSFET or relay driver modules
- External power supply

## Wiring Notes

### pH Sensor

| pH Sensor Board | ESP32 |
|---|---|
| V+ | 3.3V |
| G | GND |
| PO | GPIO34 |

The pH sensor uses analog output. In this test, normal water was used as the reference voltage and vinegar was used as the acidic test liquid.

### DS18B20 Temperature Sensor

| DS18B20 Wire | ESP32 |
|---|---|
| Red | 3.3V |
| Black | GND |
| Data | GPIO4 |

A 4.7kΩ pull-up resistor is connected between DATA and 3.3V.

## Test Results

### pH Sensor

Normal water reference:

```text
Around 2.4V to 2.5V
