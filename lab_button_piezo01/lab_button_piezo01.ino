
int buzzerPin = 9;
int buttonPin = 2;

int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);  
  
  Serial.println(buttonState);
  if (buttonState == HIGH) {
    beep(); // Calls the beep method.  
  }
  
  delay(100);
}

// The beep method, causes the piezo to beep once.
void beep() {
  analogWrite(buzzerPin, 20);
  delay(10);
  analogWrite(buzzerPin, 0);
  delay(10);
} 
