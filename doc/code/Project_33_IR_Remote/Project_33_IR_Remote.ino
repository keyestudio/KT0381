/*

Keye New RFID Starter Kit

Project 33

IR Remote

Edit By Keyes

*/

#include <IRremote.h> // import IRremote library

const int RECV_PIN = 2; // IR Remote receiver pin

IRrecv irrecv(RECV_PIN); // create IRrecv object

decode_results results; // An object that stores the decoded result

void setup() {

Serial.begin(9600); // initialize serial port

irrecv.enableIRIn(); // enable IR Remote receiver

}

void loop() {

if (irrecv.decode(&results)) { // If an infrared signal is received

Serial.println(results.value, HEX); // Print the received infrared code

irrecv.resume(); // Receive the next value

}

delay(100); // delay 100ms

}
