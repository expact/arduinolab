// Read input from a sensor

const int sensorPin = A0; // The analog pin that the sensor is connected to.
const int ledPin = 11; // The pin where the led is connected, needs to be one of the PWMs.
int sensorData = 0; // Variable of where the sensor data is collected.
int brightness = 0; // Brightness of the LED, 255 is full brigthness and 0 is completly off.

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Allows us to use the Serial Monitor to watch the values.
}

void loop() {
  sensorData = analogRead(sensorPin); // Read the data from tne sensor.
  // Re-map the sensor value from the range 0, 1023 to 0, 255.
  // Adjust the values depending on resistors being used.
  brightness = map(1023 - sensorData, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);

  delay(100);
}
