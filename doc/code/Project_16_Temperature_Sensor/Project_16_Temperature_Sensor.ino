/*

Keye New RFID Starter Kit

Project 16

Temperature detection

Edit By Keyes

*/

// Define the pin of LM35

const int sensorPin = A0;

void setup() {

// Initialize serial communication, and baud rate is 9600

Serial.begin(9600);

}

void loop() {

// Read the analog value of the LM35 output

int sensorValue = analogRead(sensorPin);

// Convert analog value to voltage value (unit: mV)

float voltage = sensorValue * (5000.0 / 1023.0);

// Convert voltage value to temperature value (unit: ℃)

float temperature = voltage / 10.0;

// Display temperature value on serial monitor

Serial.print("Temperature: ");

Serial.print(temperature);

Serial.println(" °C");

// delay 1s

delay(1000);

}
