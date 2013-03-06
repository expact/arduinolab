/*
PIR Sensor

Reference, http://bildr.org/2011/06/pir_arduino/
*/


int pirPin = 2;

void setup(){
 Serial.begin(9600); 
 pinMode(pirPin, INPUT);
}

void loop(){
  int pirVal = digitalRead(pirPin);

  if(pirVal == LOW) {
    Serial.println("Motion Detected"); 
    delay(2000); 
  } else {
    Serial.println("No Motion"); 
    delay(500);
  }

}
