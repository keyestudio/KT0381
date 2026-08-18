/*

Keye New RFID Starter Kit

Project 32

Matrix Keypad

Edit By Keyes

*/

#include <Keypad.h>

const byte ROWS = 4; //four rows

const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {

{'4','8','C','*'},

{'3','7','B','#'},

{'2','6','A','0'},

{'1','5','9','D'}

};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad

byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//Create an object of keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){

Serial.begin(9600);

}

void loop(){

char key = keypad.getKey();// Read the key

// Print if key pressed

if (key){

Serial.print("Key Pressed : ");

Serial.println(key);

}

}