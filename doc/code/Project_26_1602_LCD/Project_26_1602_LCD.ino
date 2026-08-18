/*

Keye New RFID Starter Kit

Project 26

1602 LCD

Edit By Keyes

*/

#include <LiquidCrystal.h>

// Initialize 1602 LCD and set the Arduino pin

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

// set the numbers of row and column of 1602 LCD

lcd.begin(16, 2);

// Print character strings on 1602 LCD

lcd.print("Hello, world!");

}

void loop() {

// set the the cursor to row 2 column 0

lcd.setCursor(0, 1);

// Print the current operating time in ms

lcd.print(millis() / 1000);

}
