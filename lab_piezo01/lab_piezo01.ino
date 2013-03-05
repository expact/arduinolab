
const int buzzerPin = 9;

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
  analogWrite(buzzerPin, 20);
  delay(200);
  analogWrite(buzzerPin, 0);
  delay(200);
} 
