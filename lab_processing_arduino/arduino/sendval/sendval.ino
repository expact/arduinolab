int sensorPin = A0; // Analog pin that the sensor is connected to.

// Initial values for threshold and sensor data.
int sensorData = 0;
int threshold = 950; // Configured threshold.

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorData = analogRead(sensorPin);
  // Print the dara we recieved from the sensor.

  //int val = map(analogRead(sensorData), 0, 1023, 0, 255); 
  Serial.println(map(sensorData, 0, 1023, 0, 255));
  //Serial.print(map(sensorData, 0,1023,0,1000) / 100.0);

  // If the sensor value is less than the configured threshold, Beep!
  if (sensorData < threshold) {
    beep(); // Calls the beep method.  
  }

  delay(10);
}

// The beep method, causes the piezo to beep once.
void beep() {
  //Serial.println("beep");
  //analogWrite(buzzerPin, 20);
  //delay(10);
  //analogWrite(buzzerPin, 0);
  //delay(10);
} 
