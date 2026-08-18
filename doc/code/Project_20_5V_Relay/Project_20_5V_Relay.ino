
/*

Keye New RFID Starter Kit

Project 20

5V Relay

Edit By Keyes

*/

const int relayPin = 3; // set relay pin

void setup() {

pinMode(relayPin, OUTPUT); // set pin to output

}

void loop() {

digitalWrite(relayPin, HIGH); // output high to trigger the relay

delay(1000); // delay 1s

digitalWrite(relayPin, LOW); //output low to disable the relay

delay(1000); // delay 1s

}
