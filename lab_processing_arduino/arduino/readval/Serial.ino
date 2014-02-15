// Helper to read commands sent over serial.
// Adapted from https://github.com/trinamic/TMC26XStepper/

#define INPUT_BUFFER_LENGTH 32
#define SERIAL_SPEED 9600

char inputBuffer[INPUT_BUFFER_LENGTH + 1];
unsigned char inputBufferPosition;

void startSerial() {
  for (unsigned char i=0; i< INPUT_BUFFER_LENGTH+1; i++) {
    inputBuffer[i]=0;
  }
  inputBufferPosition=0;
}

void loopSerial() {
  if (Serial.available() > 0 && inputBufferPosition < INPUT_BUFFER_LENGTH) {
    char c = Serial.read();
    inputBuffer[inputBufferPosition] = c;
    inputBufferPosition++;
    inputBuffer[inputBufferPosition] = 0;
    if (c=='\n') {
      readSerial();   
    }
  }
}

void readSerial() {
  Serial.print("Executing ");
  Serial.println(inputBuffer);

  onSerialData(inputBuffer[0]);

  inputBufferPosition = 0;
  inputBuffer[0] = 0;
}

int decode(unsigned char startPosition) {
  int result=0;
  boolean negative = false;
  if (inputBuffer[startPosition]=='-') {
    negative=true;
    startPosition++;
  }
  for (unsigned char i=startPosition; i< (INPUT_BUFFER_LENGTH+1) && inputBuffer[i]!=0; i++) {
    char number = inputBuffer[i];
    if (number <= '9' && number >='0') {
      result *= 10;
      result += number - '0';
    } else {
      break;
    }
  }
  if (negative) {
    return -result;
  } 
  else {
    return result;
  }
}

