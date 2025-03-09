# MH-Z19C CO2 Sensor with Arduino UNO R4 WiFi

This project implements a CO2 monitoring system using the MH-Z19C sensor and Arduino UNO R4 WiFi board. MH-Z19C uses UART communication protocol via digital pins 2 and 3.

## Hardware Requirements

- Arduino UNO board
- MH-Z19C CO2 Sensor

## Wiring

![MH-Z19C Wiring Diagram](./images/MH-Z19C%20Wiring.png)


## Pin Connections

| MH-Z19C Pin | Arduino Pin |
|-------------|-------------|
| VCC         | 5V          |
| GND         | GND         |
| TX          | D2 (RX)     |
| RX          | D3 (TX)     |

### Hardware Setup
1. The sensor requires 5V DC power supply
2. Allow proper ventilation around the sensor for accurate readings

### Required Libraries:
1. SoftwareSerial (included in Arduino IDE)

## Installation

1. Clone this repository or download the source code
2. Open the `MHZ19C_CO2_Monitor.ino` file in Arduino IDE
3. Connect your Arduino UNO R4 WiFi to your computer
4. Select the correct board and port in Arduino IDE
5. Upload the code to your board

## Important Notes

1. **Warm-up Time**: The MH-Z19C sensor requires a warm-up time of about 3 minutes for accurate readings.

2. **Calibration**:
   - The sensor has automatic baseline correction
   - For manual calibration, expose the sensor to fresh air (400ppm CO2) for 20 minutes
   - Avoid using in enclosed spaces for long periods without ventilation

3. **Measurement Range**:
   - Standard measuring range: 400-5000ppm
   - Accuracy: ±50ppm +5% reading value
   - Response time: <120 seconds

4. **Operating Conditions**:
   - Temperature range: 0-50°C
   - Humidity range: 0-95% RH (non-condensing)

## Troubleshooting

1. If no readings are displayed:
   - Check all wire connections
   - Verify power supply voltage
   - Ensure TX/RX pins are correctly connected

2. If readings are inconsistent:
   - Allow proper warm-up time
   - Check for proper ventilation
   - Verify power supply stability