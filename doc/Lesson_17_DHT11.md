### Project 17  DHT11 Temperature & Humidity Sensor

#### Description

The DHT11 is a basic, ultra low-cost digital temperature and humidity sensor. It uses a capacitive humidity sensor and a thermistor to measure the surrounding air, and spits out a digital signal on the data pin (no analog input pins needed). It's fairly simple to use, but requires careful timing to grab data. The only real downside of this sensor is you can only get new data from it once every 2 seconds. In this project, we will learn how to read temperature and humidity data from the DHT11 sensor and print it to the Serial Monitor.

#### Hardware

- UNO R3 development board x1
- DHT11 Sensor Module x1
- Breadboard x1
- Jumper wires

#### Working Principle

The DHT11 sensor consists of a capacitive humidity sensing element and a thermistor for sensing temperature. The humidity sensing capacitor has two electrodes with a moisture holding substrate as a dielectric between them. Change in capacitance value occurs with the change in humidity levels. The IC measure, process this changed resistance values and change them into digital form.

For measuring temperature this sensor uses a Negative Temperature Coefficient thermistor, which causes a decrease in its resistance value with increase in temperature. To get larger resistance value even for the smallest change in temperature, this sensor is usually made up of semiconductor ceramics or polymers.

The temperature and humidity data from the sensor is transmitted to the Arduino using a single-wire, two-way communication protocol.

#### Specifications

- Operating Voltage: 3.3V to 5V
- Temperature Range: 0°C to 50°C (±2°C accuracy)
- Humidity Range: 20% to 90% RH (±5% accuracy)
- Sampling Rate: 1Hz (one reading every second)

#### Library Installation

This project requires the `dht` library.

1. Open the Arduino IDE.

2. Go to **Sketch** -> **Include Library** -> **Manage Libraries...**

   ![Snipaste_2026-08-11_08-48-39](media\Snipaste_2026-08-11_08-48-39.png)

3. In the Library Manager search bar, type `DHT sensor library`.

   ![Snipaste_2026-08-11_08-51-47](media\Snipaste_2026-08-11_08-51-47.png)

4. Find the library by **Adafruit** and click **Install**. (If prompted to install dependencies like Adafruit Unified Sensor, click "Install All").
![Snipaste_2026-08-11_08-55-37](media\Snipaste_2026-08-11_08-55-37.png)

#### Wiring Diagram

| DHT11 Module | UNO R3 development board |
| ------------ | ------------------------ |
| VCC (+)      | 5V                       |
| GND (-)      | GND                      |
| DATA (OUT)   | Digital Pin 2            |

![Snipaste_2026-08-10_17-57-13](media\Snipaste_2026-08-10_17-57-13.png)

#### Sample Code

```cpp
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


```

#### Code Explanation

```
#include <DHT.h>
```

Includes the official DHT library, which implements the precise one-wire timing protocol required to communicate with the DHT11 sensor.

```
#define DHT11_PIN 2
DHT dht(DHT11_PIN, DHT11);
```

Defines the digital pin connected to the DHT11 data wire. Creates a DHT object and declares the pin number and sensor model (DHT11).

```
void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHT11 Test Program");
  Serial.println("------------------");
}
```

`Serial.begin(9600)` initializes serial communication at a baud rate of 9600 for outputting sensor data. `dht.begin()` initializes the DHT object and establishes communication with the physical sensor.

```
void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.println(humidity);
  
  delay(2000);
}
```

`dht.readTemperature()` reads the temperature value in Celsius and stores it as a floating-point variable. `dht.readHumidity()` reads the relative humidity value in percentage and stores it as a floating-point variable. Serial related functions output temperature and humidity information to the Serial Monitor for real-time viewing. `delay(2000)` sets a 2-second interval between measurements. The DHT11 hardware needs at least a 2-second gap between readings to ensure stable and valid measurement results.

#### Project Result

After uploading the code, open the Serial Monitor and set the baud rate to 9600. You will see the current temperature (in Celsius) and humidity (in percentage) printed every 2 seconds. If you breathe on the sensor or hold it in your hand, you should see the humidity and temperature values increase.
