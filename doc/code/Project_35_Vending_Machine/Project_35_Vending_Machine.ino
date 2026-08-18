/*

Keye New RFID Starter Kit

Project 35

Vending machine

Edit By Keyes

*/

#include <LiquidCrystal.h>

#include <Servo.h>

// Initialize LCD1602

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Initialize servo motor

Servo myservo;

// Define button pins

const int button1Pin = 6;

const int button2Pin = 7;

const int button3Pin = 8;

// Item selection variable

int selectedItem = 0;

void setup() {

// Set button pin modes

pinMode(button1Pin, INPUT);

pinMode(button2Pin, INPUT);

pinMode(button3Pin, INPUT);

// Initialize LCD

lcd.begin(16, 2);

lcd.print("Select Item:");

// Initialize servo motor

myservo.attach(10);

myservo.write(0); // Initial position

}

void loop() {

// Read button states

int button1State = digitalRead(button1Pin);

int button2State = digitalRead(button2Pin);

int button3State = digitalRead(button3Pin);

// Detect button 1 (select previous item)

if (button1State == HIGH) {

selectedItem--;

if (selectedItem < 0) {

selectedItem = 2; // Assume there are 3 items

}

updateLCD();

delay(200); // Debounce delay

}

// Detect button 2 (select next item)

if (button2State == HIGH) {

selectedItem++;

if (selectedItem > 2) {

selectedItem = 0;

}

updateLCD();

delay(200); // Debounce delay

}

// Detect button 3 (confirm purchase)

if (button3State == HIGH) {

dispenseItem();

delay(200); // Debounce delay

}

}

void updateLCD() {

lcd.clear();

lcd.print("Select Item:");

lcd.setCursor(0, 1);

lcd.print("Item ");

lcd.print(selectedItem + 1); // Display item number

}

void dispenseItem() {

lcd.clear();

lcd.print("Dispensing...");

myservo.write(180); // Rotate servo to release item

delay(1000); // Wait for item to be released

myservo.write(0); // Reset servo

lcd.clear();

lcd.print("Select Item:");

}
