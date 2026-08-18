/*

Keye New RFID Starter Kit

Project 5

LED flowing light

Edit By Keyes

*/

int ledPins[] = {2, 3, 4, 5, 6, }; // Define the pin of the LED

int ledCount = 5; // Number of LEDs

int delayTime = 100; // Delay time in ms

void setup() {

for (int i = 0; i < ledCount; i++) {

pinMode(ledPins[i], OUTPUT); // Set the LED pin to output mode

}

}

void loop() {

for (int i = 0; i < ledCount; i++) {

digitalWrite(ledPins[i], HIGH); // Light up the current LED

delay(delayTime); // Delay

digitalWrite(ledPins[i], LOW); // Light off the current LED

}

for (int i = ledCount - 2; i > 0; i--) {

digitalWrite(ledPins[i], HIGH); // Light up the current LED

delay(delayTime); // Delay

digitalWrite(ledPins[i], LOW); // Light off the current LED

}

}

