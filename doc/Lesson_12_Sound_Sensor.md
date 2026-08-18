### Project 12  Sound Sensor

#### Description
The sound sensor module provides an easy way to detect sound and is generally used for detecting sound intensity. This module typically features two outputs: a Digital Output (DO) and an Analog Output (AO). 
- **DO (Digital Output):** Outputs a HIGH or LOW signal when the sound intensity reaches a certain threshold (adjustable via the onboard potentiometer).
- **AO (Analog Output):** Outputs a real-time voltage signal representing the actual microphone voltage, allowing you to measure the exact sound wave amplitude.

In this project, we will learn how to read both the digital and analog signals from the sound sensor.

#### Hardware
- UNO R3 development board x1
- Sound Sensor Module (with AO and DO pins) x1
- Breadboard x1
- Jumper wires

#### Working Principle
The sound sensor module consists of a microphone, an amplifier, and a comparator (like the LM393). 
1. The microphone converts sound waves into weak electrical signals.
2. These signals are amplified and sent directly to the **AO (Analog Output)** pin.
3. The amplified signal is also fed into the comparator, which compares it against a reference voltage set by the onboard potentiometer. If the sound level exceeds the threshold, the comparator outputs a digital signal to the **DO (Digital Output)** pin. You can adjust the sensitivity by turning the screw on the potentiometer.

#### Specifications
- Operating Voltage: 3.3V to 5V
- Outputs: Digital (DO) and Analog (AO)
- Sensitivity: Adjustable via onboard potentiometer (for DO)
- Main Chip: LM393 comparator

#### Wiring Diagram

| Sound Sensor | UNO R3 development board |
|--------------|----------------|
| VCC (+)      | 5V             |
| GND (-)      | GND            |
| DO (Digital) | Digital Pin 3  |
| AO (Analog)  | Analog Pin A0  |

![Snipaste_2026-08-10_16-20-15](media\Snipaste_2026-08-10_16-20-15.png)

#### Sample Code

```cpp
int digitalPin = 3; // DO connected to digital pin 3
int analogPin = A0; // AO connected to analog pin A0

void setup() {
  Serial.begin(9600);
  pinMode(digitalPin, INPUT);
  Serial.println("Sound Sensor Test (AO & DO)");
}

void loop() {
  int digitalVal = digitalRead(digitalPin); // Read digital threshold
  int analogVal = analogRead(analogPin);    // Read analog amplitude
  
  Serial.print("Analog Value: ");
  Serial.print(analogVal);
  
  // Note: Some sensors output LOW when sound is detected. 
  // Adjust the condition based on your specific module.
  if (digitalVal == HIGH) {
    Serial.println("  |  Status: Sound Detected! (DO Triggered)");
  } else {
    Serial.println("  |  Status: Quiet");
  }
  
  delay(100); // Small delay to prevent flooding the serial monitor
}
```

#### Code Explanation
- `analogRead(analogPin)`: Reads the continuous voltage level from the microphone. This value fluctuates rapidly with sound waves.
- `digitalRead(digitalPin)`: Reads the state of the comparator. It will be either HIGH or LOW based on the potentiometer threshold.
- The Serial Monitor prints both the raw analog value and the digital trigger status side-by-side for easy comparison.

#### Project Result
Open the Serial Monitor. You will see a continuous stream of analog values. Clap your hands or make a loud noise near the microphone. You should see the analog value spike, and the status change to "Sound Detected!". If the digital status doesn't trigger, use a small screwdriver to adjust the potentiometer on the sensor module until the onboard LED flickers when you clap.
