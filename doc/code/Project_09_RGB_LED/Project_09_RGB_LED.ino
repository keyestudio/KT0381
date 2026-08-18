/*

Keye New RFID Starter Kit

Project 9

RGB LED

Edit By Keyes

*/

int redPin = 9; // red pin

int greenPin = 10; // green pin

int bluePin = 11; // blue pin

void setup() {

pinMode(redPin, OUTPUT);

pinMode(greenPin, OUTPUT);

pinMode(bluePin, OUTPUT);

}

void loop() {

// red gradient

for (int i = 0; i <= 255; i++) {

analogWrite(redPin, i);

delay(10);

}

for (int i = 255; i >= 0; i--) {

analogWrite(redPin, i);

delay(10);

}

// green gradient

for (int i = 0; i <= 255; i++) {

analogWrite(greenPin, i);

delay(10);

}

for (int i = 255; i >= 0; i--) {

analogWrite(greenPin, i);

delay(10);

}

// blue gradient

for (int i = 0; i <= 255; i++) {

analogWrite(bluePin, i);

delay(10);

}

for (int i = 255; i >= 0; i--) {

analogWrite(bluePin, i);

delay(10);

}

}
