# Arduino Weather Station with GPS

## Overview
This Arduino project is a compact weather station that combines environmental sensing with GPS capabilities. The system is designed to measure and display real-time data including Humidity, Temperature, Latitude, Longitude, Date, Time, and the number of Satellites in View and in Use. The information is presented on a 0.96-inch OLED display, providing a user-friendly interface for quick access to relevant weather and location data.

## Components Used
- Arduino (compatible with the Adafruit GFX and Adafruit SSD1306 libraries)
- DHT11 or similar Humidity and Temperature Sensor
- U-Blox NEO-M8N GPS Module
- 0.96-inch OLED Display
- Connecting wires
- Arduino Mega 2560

## Wiring Connections

### Arduino Mega 2560 Pinout

- **DHT11 Sensor:**
  - Connect the data pin of the DHT11 sensor to digital pin 2 on the Arduino Mega 2560.

- **NEO-6M GPS Module:**
  - Connect the RX pin of the U-Blox NEO-M8N GPS module to digital pin 18 (TX1) on the Arduino Mega 2560.
  - Connect the TX pin of the U-Blox NEO-M8N GPS module to digital pin 19 (RX1) on the Arduino Mega 2560.

- **OLED Display:**
  - Connect the SDA pin of the OLED display to digital pin 20 (SDA) on the Arduino Mega 2560.
  - Connect the SDL pin of the OLED display to digital pin 21 (SCL) on the Arduino Mega 2560.

## Features
1. **Environmental Sensing:**
   - Humidity and Temperature readings are captured using a DHT11 sensor, providing accurate and up-to-date information about the surrounding environment.

2. **GPS Positioning:**
   - The U-Blox NEO-M8N GPS module is utilized to determine the current Latitude and Longitude coordinates, enabling location tracking.

3. **Date and Time Display:**
   - The system retrieves and displays the current Date and Time, ensuring that users have access to timely information.

4. **Satellite Information:**
   - The number of Satellites in View and in Use is monitored and displayed, offering insights into the GPS signal strength and accuracy.

5. **OLED Display:**
   - All collected data is presented on a clear and concise 0.96-inch OLED screen, providing a compact and visually appealing user interface.

## Dependencies
This project relies on the Adafruit GFX and Adafruit SSD1306 libraries for interfacing with the OLED display. Make sure to install these libraries in your Arduino IDE before uploading the code.

## Usage
1. Connect the DHT11 sensor, U-Blox NEO-M8N GPS module, and OLED display to the Arduino board as per the provided wiring diagram.
2. Upload the provided Arduino code to your board using the Arduino IDE.
3. Open the serial monitor to view real-time data readings and confirm proper operation.
4. The OLED display will show the collected data in a user-friendly format, providing valuable insights into the current environmental conditions and GPS information.

Feel free to customize the code or expand the project with additional features to suit your specific requirements. Enjoy your Arduino Weather Station with GPS!
