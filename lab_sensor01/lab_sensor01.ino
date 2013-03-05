/*
 Read input from a sensor.

 Circuit:
 * Photo resistor to analog input 0.
 * one side to +5v.
 * other side attached to ground.
 * resistor attached from analog in 0 to ground.
*/


const int sensorPin = A0; // The analog pin on the Arduino that the sensor is connected to.
int sensorData = 0; // Variable of where the sensor data is collected.

void setup() { 
  Serial.begin(9600); // Allows us to use the Serial Monitor to watch the values.
}

void loop() {
  sensorData = analogRead(sensorPin); // Read the data from tne sensor.
  Serial.println(sensorData); // Print the data to the Serial Monitor so that we can watch it.
  delay(100); // Pause to make it easier to read the values.
}
