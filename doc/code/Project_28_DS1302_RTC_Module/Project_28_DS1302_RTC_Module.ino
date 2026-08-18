/*

Keye New RFID Starter Kit

Project 28

DS1302 RTC Module

Edit By Keyes

*/
#include <ThreeWire.h>  
#include <RtcDS1302.h>

// Wiring: IO -> 6, SCLK -> 5, CE(RST) -> 7
ThreeWire myWire(6, 5, 7);
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {
  Serial.begin(115200);
  Rtc.Begin();

  // Check if RTC works properly
  if (!Rtc.IsDateTimeValid()) {
    Serial.println("⚠️ RTC time invalid, initializing with compile time...");
    // This line sets the time to the computer time when the code is compiled and uploaded
    Rtc.SetDateTime(RtcDateTime(__DATE__, __TIME__));
  }

  // Uncomment this line to set custom time.
  // Comment it out again after setting, otherwise the time will reset to this value every power-up.
  // Rtc.SetDateTime(RtcDateTime(2026, 8, 14, 15, 30, 0));
}

void loop() {
  RtcDateTime now = Rtc.GetDateTime();

  // Print date and time
  Serial.print(now.Year());
  Serial.print("-");
  printWithZero(now.Month());
  Serial.print("-");
  printWithZero(now.Day());
  Serial.print(" ");
  printWithZero(now.Hour());
  Serial.print(":");
  printWithZero(now.Minute());
  Serial.print(":");
  printWithZero(now.Second());
  Serial.println();

  delay(1000);
}

// Helper function: add leading zero for single-digit numbers
void printWithZero(uint8_t num) {
  if (num < 10) Serial.print("0");
  Serial.print(num);
}
