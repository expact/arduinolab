// Building upon the ldrpiezo example we are now using a potentiometer
// to configure the threshhold value.

const int buzzerPin = 9; // Digital pin that the buzzer is connected to.
const int sensorPin = A0; // Analog pin that the sensor is connected to.
const int potPin = A1; // Analog pin that the pot is connected to.

// Initial values for threshold and sensor data.
int sensorData = 0;
int threshold = 0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorData = analogRead(sensorPin);
  threshold = analogRead(potPin); // Read data from the pot into the threshold variable.

  // Print the data we recieved from the pot.
  Serial.print("Treshhold: ");
  Serial.println(threshold, DEC);

  // If the sensor value is less than the configured threshold, Beep!
  if (sensorData < threshold) {
    beep();
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
