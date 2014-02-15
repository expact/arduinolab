
// Send a value from Arduino and read that value from a processing app.

// Use this demo together with the Processing sketches.
// readAndPlay
// readVal

int sensorPin = A0; // Analog pin that the sensor is connected to.

int sensorData = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorData = analogRead(sensorPin);

  Serial.println(map(sensorData, 0, 1023, 0, 255));

  delay(10);
}

