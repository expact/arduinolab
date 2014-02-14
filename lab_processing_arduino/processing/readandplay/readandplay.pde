/**
 * Read value from Arduino
 *
 * Use the value as input to control a sound using minim.
 */

import processing.serial.*;
import ddf.minim.*;

Minim minim;
AudioPlayer player;

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

  // We pass this to Minim so that it can load files from the data directory
  minim = new Minim(this);

  // loadFile will look in all the same places as loadImage does.
  // this means you can find files that are in the data folder and the 
  // sketch folder. you can also pass an absolute path, or a URL.
  player = minim.loadFile("marcus_kellis_theme.mp3");
  // play the file
  player.pause();

}

int time = 0;
int passedTime = 0;

void draw() {
  background(val);

  if (val < 100) {
    player.play();
  } else {
    player.pause();
  }
}

void serialEvent(Serial port) {
  char c = arduinoPort.readChar();
  if (c == '\n') {
    String sentVal = serialStringBuilder.toString();
    println("-->" + sentVal + "<---");  // Debug print, uncomment to see the passed value.
    val = int(trim(sentVal));
    serialStringBuilder = new StringBuilder();
  } else {
    serialStringBuilder.append(c);
  }  
}

