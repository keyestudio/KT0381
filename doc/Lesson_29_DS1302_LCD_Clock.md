### Project 29  DS1302 + LCD Clock Display

#### Description
Let's combine the DS1302 RTC module with a standard 1602 LCD to create a standalone digital desk clock! This project integrates timekeeping and display technologies, resulting in a practical and useful device.

#### Hardware
- UNO R3 development board x1
- DS1302 RTC Module x1
- 1602 LCD Module (Standard Parallel, NOT I2C) x1
- 10k Potentiometer x1 (for LCD contrast)
- Breadboard x1
- Jumper wires

#### Working Principle
The Arduino acts as the central hub, coordinating between the RTC and the LCD. Every second, the Arduino requests the current date and time strings from the DS1302 module using the 3-wire serial interface. Once the data is received, the Arduino formats it and sends it over 6 digital pins to the parallel 1602 LCD. The LCD then updates its display. Because the DS1302 has a backup battery, the clock will maintain the correct time even if you unplug the Arduino from your computer and plug it into a wall adapter later.

#### Specifications
- Display: 16 characters x 2 lines (Parallel Interface)
- Timekeeping: DS1302 RTC with battery backup
- Update Rate: 1 Hz (every second)

#### Library Installation
**The required library files have already been installed. Refer to Lesson 28 if reinstallation is needed.**


#### Wiring Diagram

**1602 LCD Standard 16-Pin Interface:**
| No. | Mark | Pin Description | Connection |
|-----|------|-----------------|------------|
| 1   | VSS  | Power GND       | GND        |
| 2   | VDD  | Power positive  | 5V         |
| 3   | V0   | LCD voltage bias| Potentiometer Middle Pin |
| 4   | RS   | Data/Command    | Digital Pin 12 |
| 5   | R/W  | Read/Write      | GND        |
| 6   | E    | Enable signal   | Digital Pin 11 |
| 7   | D0   | Data I/O        | Not Connected |
| 8   | D1   | Data I/O        | Not Connected |
| 9   | D2   | Data I/O        | Not Connected |
| 10  | D3   | Data I/O        | Not Connected |
| 11  | D4   | Data I/O        | Digital Pin 5 |
| 12  | D5   | Data I/O        | Digital Pin 4 |
| 13  | D6   | Data I/O        | Digital Pin 3 |
| 14  | D7   | Data I/O        | Digital Pin 2 |
| 15  | A    | Backlight (+)   | 5V         |
| 16  | K    | Backlight (-)   | GND        |

*Note: The two outer pins of the 10K potentiometer connect to 5V and GND.*

**DS1302 RTC Module:**
- VCC to 5V

- GND to GND

- CLK to Digital Pin 8

- DAT to Digital Pin 9

- RST to Digital Pin 10

  ![Snipaste_2026-08-11_15-36-16](media\Snipaste_2026-08-11_15-36-16.png)

#### Sample Code
```cpp
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

```

#### Code Explanation
- This code integrates the `ThreeWire`, `RtcDS1302` and `LiquidCrystal` libraries to read real-time clock data and display information on an LCD screen.
- `ThreeWire myWire(9, 8, 10); RtcDS1302<ThreeWire> Rtc(myWire);`: Initialize the DS1302 real-time clock and configure the DAT, CLK and RST pins.
- `LiquidCrystal lcd(12, 11, 5, 4, 3, 2);`: Initialize the 1602 LCD module with assigned pins to avoid pin conflicts with the DS1302 clock module.
- `Rtc.IsDateTimeValid()`: Check whether the RTC time is valid. If the time is invalid, the clock will be automatically initialized using the compile time of the program.
- `lcd.setCursor(0, 0)`: Move the cursor to the start of the first line for displaying year, month and day.
- `lcd.setCursor(0, 1)`: Move the cursor to the start of the second line for displaying hour, minute and second.
- `print2digitLCD()`: A custom function that adds a leading zero to numbers less than 10 to maintain consistent time formatting on the LCD.
- `print2digitSerial()`: A custom function that adds a leading zero to numbers less than 10 to standardize the time format of serial output.
- `delay(1000)`: Refresh data once per second to stabilize the clock display.

#### Project Result
After uploading the code, adjust the potentiometer until the text on the LCD is clearly visible. The LCD will display a startup message for 2 seconds. Then, it will show the current date on the top row and the current time on the bottom row. The seconds will tick up in real-time. You now have a fully functional digital clock!
