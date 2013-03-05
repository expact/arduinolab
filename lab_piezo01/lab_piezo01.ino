
int buzzerPin = 9;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  beep(); // Calls the beep method.
  delay(1000);
}

// The beep method, causes the piezo to beep once.
void beep() {
  analogWrite(buzzerPin, 20); // The value here can be anything between 0 and 255, test a few.
  delay(200); // Test with various values for delay.
  analogWrite(buzzerPin, 0); // This turns of the buzzer.
  delay(200); // Change here to.
} 
