/*

Keye New RFID Starter Kit

Project 19

Water level sensor

Edit By Keyes

*/

// Define the pin for the water level sensor

const int waterSensorPin = A0;

void setup() {

// Initialize serial communication at a baud rate of 9600

Serial.begin(9600);

}

void loop() {

// Read the analog value from the water level sensor

int waterLevel = analogRead(waterSensorPin);

// Convert the analog value to a voltage value

float voltage = waterLevel * (5.0 / 1023.0);

// Output water level information to the Serial Monitor

Serial.print("Water Level: ");

Serial.print(waterLevel);

Serial.print(" (Analog Value), ");

Serial.print(voltage);

Serial.println(" V (Voltage)");

// Read once per second

delay(1000);

}
