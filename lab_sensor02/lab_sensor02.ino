/* 
 Read input from a sensor
 Use the input to trigger something.

 Circuit:
 * Photo resistor to analog input 0.
 * one side to +5v.
 * other side attached to ground.
 * resistor attached from analog in 0 to ground.
 * LED connected to pin 13.
 * anode (long leg) attached to digital output 13
 * cathode (short leg) attached to ground
*/

const int sensorPin = A0; // The analog pin that the sensor is connected to.
const int ledPin = 13; // The pin where the LED is connected.
int sensorData = 0; // Variable of where the sensor data is collected.

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Allows us to use the Serial Monitor to watch the values.
}

void loop() {
  sensorData = analogRead(sensorPin); // Read the data from tne sensor.
  Serial.println(sensorData); // Print the data to the Serial Monitor so that we can watch it.

  if (sensorData < 600) { // If the sensor value is lower than 600, turn on the LED. 
    digitalWrite(ledPin, HIGH);
  } else { // If the sensor value is above 600 turn off the LED.
    digitalWrite(ledPin, LOW); 
  }
}
