// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
String value = "";
void setup() {
  Wire.begin();        // join I2C bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(0x1E,12);    // request 12 bytes from slave device #8
  value = "";
  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
             // print the character
    value = value +c;
  }
Serial.println(value);

  delay(100);
}
