/*

Keye New RFID Starter Kit

Project 23

1-digit LED Segment Display

Edit By Keyes

*/

// define the pins of each segments

const int a = 6;

const int b = 7;

const int c = 5;

const int d = 10;

const int e = 11;

const int f = 8;

const int g = 9;

const int dp = 4;

// Define the segment combination of number 0 to 9

const int num[10][7] = {

{1, 1, 1, 1, 1, 1, 0}, // 0

{0, 1, 1, 0, 0, 0, 0}, // 1

{1, 1, 0, 1, 1, 0, 1}, // 2

{1, 1, 1, 1, 0, 0, 1}, // 3

{0, 1, 1, 0, 0, 1, 1}, // 4

{1, 0, 1, 1, 0, 1, 1}, // 5

{1, 0, 1, 1, 1, 1, 1}, // 6

{1, 1, 1, 0, 0, 0, 0}, // 7

{1, 1, 1, 1, 1, 1, 1}, // 8

{1, 1, 1, 1, 0, 1, 1} // 9

};

void setup() {

// set pins to output

pinMode(a, OUTPUT);

pinMode(b, OUTPUT);

pinMode(c, OUTPUT);

pinMode(d, OUTPUT);

pinMode(e, OUTPUT);

pinMode(f, OUTPUT);

pinMode(g, OUTPUT);

pinMode(dp, OUTPUT);

}

void loop() {

// show number 0 to 9 in loop

for (int i = 0; i < 10; i++) {

displayNumber(i);

delay(1000);

}

}

// show numbers

void displayNumber(int n) {

// set the on and off of each segment

digitalWrite(a, num[n][0]);

digitalWrite(b, num[n][1]);

digitalWrite(c, num[n][2]);

digitalWrite(d, num[n][3]);

digitalWrite(e, num[n][4]);

digitalWrite(f, num[n][5]);

digitalWrite(g, num[n][6]);

digitalWrite(dp, LOW); // Decimal point is off

}
