const int buzzerPin = 9; // Digital pin that the buzzer is connected to.
const int sensorPin = A0; // Analog pin that the sensor is connected to.

// Initial values for threshold and sensor data.
int sensorData = 0;
int threshold = 950; // Configured threshold.

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorData = analogRead(sensorPin);
  // Print the dara we recieved from the sensor.
  Serial.println(sensorData);

  // If the sensor value is less than the configured threshold, Beep!
  if (sensorData < threshold) {
    beep(); // Calls the beep method.  
  }

  delay(1);
}

// The beep method, causes the piezo to beep once.
void beep() {
  analogWrite(buzzerPin, 20);
  delay(10);
  analogWrite(buzzerPin, 0);
  delay(10);
} 
