// LED Blink

const int ledPin = 13; // The Digital (PWM) pin on the Arduino.

void setup() {
  pinMode(ledPin, OUTPUT); // Configures this pin to be used as output.
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn on LED.
  delay(1000); // Pause this program for 1000 milliseconds (1 second), causes the LED to be turned on for this period. 
  digitalWrite(ledPin, LOW); // Turn off LED.
  delay(1000); // Pause for 1000 milliseconds, ensures the LED is turned off for this period.
}
