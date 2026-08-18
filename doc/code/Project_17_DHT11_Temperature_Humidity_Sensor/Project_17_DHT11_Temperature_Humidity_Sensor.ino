/*

Keye New RFID Starter Kit

Project 17

DHT11 Temperature & Humidity Sensor

Edit By Keyes

*/
#include <DHT.h>

#define DHT11_PIN 2
DHT dht(DHT11_PIN, DHT11);   

void setup() {
  Serial.begin(9600);
  dht.begin();               
  Serial.println("DHT11 Test Program");
  Serial.println("------------------");
}

void loop() {
  // Read data from the sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  // Print the results to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  // Wait 2 seconds before the next reading
  delay(2000);
}
