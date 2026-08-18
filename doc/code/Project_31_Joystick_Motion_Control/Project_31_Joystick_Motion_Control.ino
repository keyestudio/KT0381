/*

Keye New RFID Starter Kit

Project 31

Joystick Motion Control

Edit By Keyes

*/

#include <Stepper.h>

#include <Servo.h>

const int stepsPerRevolution = 2038; // Define the number of steps per rotation

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

Servo myservo;

int currentPos = 0;

bool shouldRotate = false;

int targetPos = 0;

void setup() {

myservo.attach(6);

myservo.write(0);

}

void loop() {

Control_X();

Control_Y();

}

void Control_X(){

int xValue = analogRead(A0);

if (xValue < 300) {

myStepper.setSpeed(10);

for (int i = 0; i < 10; i++) {

myStepper.step(1);

delay(10);

}

}

else if (xValue > 800) {

myStepper.setSpeed(10);

for (int i = 0; i < 10; i++) {

myStepper.step(-1);

delay(10);

}

} else {

digitalWrite(8, LOW);

digitalWrite(9, LOW);

digitalWrite(10, LOW);

digitalWrite(11, LOW);

}

}

void Control_Y(){

int y = analogRead(A1);

// Set target position based on y value

if (y < 300) {

targetPos = 180;

shouldRotate = (currentPos < targetPos);

} else if (y > 800) {

targetPos = 0;

shouldRotate = (currentPos > targetPos);

} else {

// If y is between 300 and 800, do not rotate

shouldRotate = false;

}

// If should rotate, move towards the target position step by step

if (shouldRotate) {

if (currentPos < targetPos) {

currentPos++;

} else {

currentPos--;

}

myservo.write(currentPos);

delay(15); // Delay added for smooth movement

// Stop rotating if the target position is reached

if (currentPos == targetPos) {

shouldRotate = false;

}

}

}
