/* 
Making a LED Blink by periodically turning it on and off.

Circuit:
* Connect LED to pin 13 through a resistor. (long leg on the LED)
* Connect GND to the other leg.
*/

int ledPin = 13; // The pin on the Arduino.

void setup() {
  // Code here is run once.
  pinMode(ledPin, OUTPUT); // Configures this pin to be used as output.
} // End of setup.

void loop() {
  // Code put here is run repeatedly.
  digitalWrite(ledPin, HIGH); // Turn on LED.
  delay(1000); // Pause this program for 1000 milliseconds (1 second), causes the LED to be turned on for this period. 
  digitalWrite(ledPin, LOW); // Turn off LED.
  delay(1000); // Pause for 1000 milliseconds, ensures the LED is turned off for this period.
} // End of loop.
