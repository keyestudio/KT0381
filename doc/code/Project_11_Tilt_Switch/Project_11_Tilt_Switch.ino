/*

Keye New RFID Starter Kit

Project 11

Tilt Switch

Edit By Keyes

*/

const int tiltPin = 4; // Define the digital pin of the tilt switch

void setup() {

pinMode(tiltPin,INPUT); // Set the tilt switch pin to input mode

Serial.begin(9600); // Initialize serial communication, and set baud rate to 9600

}

void loop() {

int tiltState = digitalRead(tiltPin); // Read tilt switch status

if (tiltState == LOW) { // If the tilt switch is closed (tilt)

Serial.println("Tilt switch is triggered！");

} else { // If the tilt switch is disconnected (vertical)

Serial.println("Tilt switch is not triggered");

}

delay(500); // delay 500ms

}
