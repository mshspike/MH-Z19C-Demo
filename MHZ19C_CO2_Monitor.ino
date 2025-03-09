#include <SoftwareSerial.h>

// Define pins for software serial communication
#define RX_PIN 2  // Connect to TX pin of MH-Z19C
#define TX_PIN 3  // Connect to RX pin of MH-Z19C

SoftwareSerial mhzSerial(RX_PIN, TX_PIN);  // Create software serial object

byte cmd[9] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
unsigned char response[9];  // Array to store the response

void setup() {
  Serial.begin(9600);      // Start hardware serial for debugging
  mhzSerial.begin(9600);   // Start software serial for sensor communication
  
  Serial.println("MH-Z19C CO2 Sensor Initialization...");
  delay(2000);  // Warm up time for the sensor
}

void loop() {
  int CO2ppm = readCO2();
  
  if (CO2ppm > 0) {
    Serial.print("CO2 Concentration: ");
    Serial.print(CO2ppm);
    Serial.println(" ppm");
  } else {
    Serial.println("Failed to read from sensor");
  }
  
  delay(5000);  // Wait 5 seconds before next reading
}

int readCO2() {
  // Send command to read CO2
  mhzSerial.write(cmd, 9);
  
  // Wait for response
  if (mhzSerial.available() >= 9) {
    for (int i = 0; i < 9; i++) {
      response[i] = mhzSerial.read();
    }
    
    // Verify checksum
    byte check = getChecksum(response);
    if (response[8] != check) {
      Serial.println("Checksum error!");
      return -1;
    }
    
    // Calculate CO2 concentration
    int responseHigh = (int) response[2];
    int responseLow = (int) response[3];
    int ppm = (responseHigh << 8) + responseLow;
    
    return ppm;
  }
  
  return -1;
}

byte getChecksum(unsigned char* packet) {
  byte checksum = 0;
  for (int i = 1; i < 8; i++) {
    checksum += packet[i];
  }
  checksum = 0xff - checksum;
  checksum += 1;
  return checksum;
} 