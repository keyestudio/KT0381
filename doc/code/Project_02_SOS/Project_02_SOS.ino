/*

Keye New RFID Starter Kit

Project 2

SOS

Edit By Keyes

*/

int ledPin = 9; // Define the digital pin to which the LED is connected

// Define the duration of the dot signal '.' and the dash signal '-' in ms

int dotDuration = 200;

int dashDuration = 600;

// Set the pause time between two characters in ms

int pauseDuration = 200;

void setup() {

pinMode(ledPin, OUTPUT); // Set the pin to output mode

}

void loop() {

// S ···

for (int i = 0; i < 3; i++) {

digitalWrite(ledPin, HIGH);

delay(dotDuration);

digitalWrite(ledPin, LOW);

delay(pauseDuration);

}

delay(pauseDuration);

// O ---

for (int i = 0; i < 3; i++) {

digitalWrite(ledPin, HIGH);

delay(dashDuration);

digitalWrite(ledPin, LOW);

delay(pauseDuration);

}

delay(pauseDuration);

// S ···

for (int i = 0; i < 3; i++) {

digitalWrite(ledPin, HIGH);

delay(dotDuration);

digitalWrite(ledPin, LOW);

delay(pauseDuration);

}

delay(3000); // SOS cycle interval is 3 s

}
