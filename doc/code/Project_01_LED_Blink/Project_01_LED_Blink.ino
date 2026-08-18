/*

Keye New RFID Starter Kit

Project 1

LED Blink

Edit By Keyes

*/

void setup() {

pinMode(9, OUTPUT); // Set digital pin 9 as an output

}

void loop() {

digitalWrite(9, HIGH); // Set digital pin 9 to high, turning on the LED

delay(1000); // Wait for 1000 milliseconds (1 second)

digitalWrite(9, LOW); // Set digital pin 9 to low, turning off the LED

delay(1000); // Wait for 1000 milliseconds (1 second)

}

