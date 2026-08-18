int soundPin = 3; // DO pin
int ledPin = 4;
boolean ledState = false; // Keep track of whether the LED is on or off

void setup() {
  pinMode(soundPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // Ensure LED is off at startup
  digitalWrite(ledPin, LOW);
}

void loop() {
  int val = digitalRead(soundPin);
  
  // If sound is detected (Change to LOW if your sensor is active-low)
  if (val == HIGH) {
    ledState = !ledState; // Toggle the state (true becomes false, false becomes true)
    digitalWrite(ledPin, ledState); // Apply the new state to the LED
    
    // Debounce delay: wait half a second to avoid multiple triggers from one clap
    delay(500); 
  }
}