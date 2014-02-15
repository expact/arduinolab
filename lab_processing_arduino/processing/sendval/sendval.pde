
// Use this with the arduino app "readval".

import ddf.minim.*;
import processing.serial.*;

Minim minim;
AudioInput in;
Serial arduinoPort;

void setup() {
  size(300, 300);
  smooth();

  println(Serial.list());
  int portToUse = 8;

  String portName = Serial.list()[portToUse];
  arduinoPort = new Serial(this, portName, 9600);

  minim = new Minim(this);
  
  // get a line in from Minim, default bit depth is 16
  in = minim.getLineIn(Minim.STEREO, 512);
}

void draw() {
  background(0);
  
  float volume = abs(in.left.get(0) ) * 200;
  int constrainedVolume = int(constrain(volume, 0, 100));
  
  String command = "v" + constrainedVolume;

  arduinoPort.write(command + "\n");
  
  textSize(32);
  textAlign(CENTER);
  text("SPEAK", width / 2, height / 2);
}

void stop() {
  in.close();
  minim.stop();
  super.stop();
}
