/*

Keye New RFID Starter Kit

Project 3

PWM

Edit By Keyes

*/

int ledPin = 9; // Define the pin of the LED

int brightness = 0; // Define the brightness variable of the LED

int fadeAmount = 5; // Define the step size of the brightness change

void setup() {

pinMode(ledPin, OUTPUT); // Set LED pin to output mode

}

void loop() {

analogWrite(ledPin, brightness); // Use analogWrite function to output PWM signal

brightness = brightness + fadeAmount; // Adjust brightness variable

if (brightness <= 0 || brightness >= 255) {

fadeAmount = -fadeAmount; // When the brightness reaches the maximum or minimum value, change the direction of the brightness change

}

delay(30); // Delay 30ms to control the speed of brightness change

}

