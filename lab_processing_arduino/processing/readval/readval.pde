// Use this with the arduino app "sendval".

import processing.serial.*;

Serial arduinoPort;  // Create object from Serial class
int val = 0; // Data received from the serial port
StringBuilder serialStringBuilder = new StringBuilder();  // Buffer to store read data to.

void setup()  {
  size(600, 600);

  // We need to select which port to read data from.
  // A simple way is to do this is to first list the available ports using the code below.
  println(Serial.list());
  // We can then look at the log output of this processing sketch, the number shown to the left
  // is the number we will add below for the variable portToUse.
  int portToUse = 8;

  String portName = Serial.list()[portToUse];
  arduinoPort = new Serial(this, portName, 9600);
}

void draw() {
  background(val);
}

void serialEvent(Serial port) {
  char c = arduinoPort.readChar();
  if (c == '\n') {
    String sentVal = serialStringBuilder.toString();
    println("-->" + sentVal + "<---");
    //val = Integer.parseInt(sentVal); //int(sentVal);
    val = int(trim(sentVal));
    serialStringBuilder = new StringBuilder();
  } else {
    serialStringBuilder.append(c);
  }  
}

