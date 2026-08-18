/*

Keye New RFID Starter Kit

Project 14

Photoresistor

Edit By Keyes

*/

const int lightSensorPin = A0; // Photoresistor connected to analog pin A0

const int ledPin = 11; // LED connected to digital pin 11

const int threshold = 500; // Light intensity threshold, it can be adjusted according to actual situation

void setup() {

pinMode(ledPin, OUTPUT); // Set the LED pin to output mode

Serial.begin(9600); // initialize serial port

}

void loop() {

int lightValue = analogRead(lightSensorPin); // Read the analog value of the photoresistor

Serial.println(lightValue); // print the light sensor value on the serial monitor

if (lightValue < threshold) {

digitalWrite(ledPin, HIGH); // If the light intensity is less than the threshold, the LED will light up

} else {

digitalWrite(ledPin, LOW); // If the light intensity is greater than the threshold, the LED will light off

}

delay(100); // delay 100ms

}
