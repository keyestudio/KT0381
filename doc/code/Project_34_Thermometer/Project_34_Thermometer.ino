/*

Keye New RFID Starter Kit

Project 34

Thermometer

Edit By Keyes

*/

#include <LiquidCrystal.h>

// Initialize the GPIO pins: RS, E, D4, D5, D6, D7

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0; // LM35 connected to A0

void setup() {

// Set LCD column and row count

lcd.begin(16, 2);

// Display text on the first line

lcd.print("Temperature:");

}

void loop() {

// Read the analog value from LM35 (0-1023)

int sensorValue = analogRead(sensorPin);

// Convert the analog value to voltage (unit: mV)

float voltage = sensorValue * (5000.0 / 1023.0);

// Calculate the temperature value (unit: Celsius)

float temperatureC = voltage / 10.0;

// Display the temperature value on the LCD second line

lcd.setCursor(0, 1);

lcd.print(temperatureC);

lcd.print(" C ");

// Update every second

delay(1000);

}
