// Read a value sent from Processing.

// Use this demo with the Processing app "sendval".

int ledPin = 13;
int val = 0;

void setup() {
  startSerial();
  
  pinMode(ledPin, OUTPUT);
}

void loop() {
  loopSerial();

  // Volume is sent as 0 to 100, we need to map this to 0 to 255.
  int brightness = map(val, 0, 100, 0, 255);
  analogWrite(ledPin, brightness);
}

// Called when we have something to read from the serial port.
void onSerialData(char command) {
  switch(command) {
    // Format: v[value], where value is an integer. Example v42
    case 'v':
      val = decode(1);
      break;
  }
}


