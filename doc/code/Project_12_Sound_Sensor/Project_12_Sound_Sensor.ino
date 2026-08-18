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
