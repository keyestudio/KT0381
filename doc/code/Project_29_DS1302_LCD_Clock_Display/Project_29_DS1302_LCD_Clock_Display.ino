/*

Keye New RFID Starter Kit

Project 29

DS1302 LCD Clock Display

Edit By Keyes

*/
#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <LiquidCrystal.h>

// ========== DS1302 Pin Definition ==========
ThreeWire myWire(9, 8, 10);   // DAT=9, CLK=8, RST=10
RtcDS1302<ThreeWire> Rtc(myWire);

// ========== LCD Pin Definition ==========
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);

  // 1. Initialize RTC
  Rtc.Begin();
  if (!Rtc.IsDateTimeValid()) {
    Serial.println("⏰ RTC time invalid, initializing with compile time...");
    Rtc.SetDateTime(RtcDateTime(__DATE__, __TIME__));
  }

  // 2. Initialize LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Digital Clock  ");
  delay(1500);
  lcd.clear();
}

void loop() {
  RtcDateTime now = Rtc.GetDateTime();

  // ----- Display on LCD -----
  lcd.setCursor(0, 0);
  lcd.print(now.Year());
  lcd.print("-");
  print2digitLCD(now.Month());
  lcd.print("-");
  print2digitLCD(now.Day());

  lcd.setCursor(0, 1);
  print2digitLCD(now.Hour());
  lcd.print(":");
  print2digitLCD(now.Minute());
  print2digitLCD(now.Second());

  // ----- Output to Serial Monitor
  Serial.print(now.Year()); Serial.print("-");
  print2digitSerial(now.Month()); Serial.print("-");
  print2digitSerial(now.Day()); Serial.print(" ");
  print2digitSerial(now.Hour()); Serial.print(":");
  print2digitSerial(now.Minute()); Serial.print(":");
  print2digitSerial(now.Second()); Serial.println();

  delay(1000);
}

// Zero-padding function for LCD output
void print2digitLCD(uint8_t num) {
  if (num < 10) lcd.print("0");
  lcd.print(num);
}

// Zero-padding function for Serial output
void print2digitSerial(uint8_t num) {
  if (num < 10) Serial.print("0");
  Serial.print(num);
}
