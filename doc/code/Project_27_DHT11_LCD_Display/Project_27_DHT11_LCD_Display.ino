#include <LiquidCrystal.h>
#include <DHT.h>

// Initialize the LCD with the numbers of the interface pins
// LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define DHT11_PIN 8
DHT dht(DHT11_PIN, DHT11);   // DHT dht;

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  dht.begin();   // This library must be initialized.

  // Print a welcome message
  lcd.setCursor(0, 0);
  lcd.print("Temp & Humidity");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read data from the sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Display Temperature on the first line
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1); // Print with 1 decimal place
  lcd.print(" C");
  
  // Display Humidity on the second line
  lcd.setCursor(0, 1);
  lcd.print("Hum:  ");
  lcd.print(humidity, 1);    // Print with 1 decimal place
  lcd.print(" %");
  
  // Wait 2 seconds before the next reading
  delay(2000);
}