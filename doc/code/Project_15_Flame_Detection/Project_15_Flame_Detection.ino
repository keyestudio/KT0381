/*

Keye New RFID Starter Kit

Project 15

Flame detection

Edit By Keyes

*/

int flamePin = A1; // connect flame sensor pin to Arduino analog pin

int buzzerPin = 12; // set the buzzer pin

int flameValue = 0; // store the values read by the sensor

void setup() {

pinMode(buzzerPin, OUTPUT); // set buzzer pin to output

pinMode(flamePin, INPUT); // set flame sensor pin to input

Serial.begin(9600); // initialize serial port for debugging

}

void loop() {

flameValue = analogRead(flamePin); // read flame sensor value

Serial.println(flameValue); // print the flame sensor value on the serial monitor

if (flameValue > 50) { // determine whether there is flame

digitalWrite(buzzerPin, HIGH); // flame is detected, and buzzer alarms.

} else {

digitalWrite(buzzerPin, LOW); // no flame is detected, and buzzer stays quiet.

}

delay(100); // delay 100ms

}
