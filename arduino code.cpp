#include <Servo.h>

//connection pins
const int servoPins[] = {1, 2, 3, 4, 5, 6};
const int servoCount = sizeof(servoPins) / sizeof(servoPins[0]);

//switch pin
const int switchPin = 11;

//settings constants and instances for electronics, etc
const int pauseTime = 250;
Servo servos[servoCount];
int servoOriginalPositions[servoCount];

//setup function
void setup() {
  for (int i = 0; i < servoCount; i++) {
    servos[i].attach(servoPins[i]);
    servoOriginalPositions[i] = servos[i].read(); // store original servo positions
  }
  pinMode(switchPin, INPUT_PULLUP);
}

//main function
void loop(){
  powerSwitch();
}

bool deviceOn = false;

//function for the on and off switch
void powerSwitch() {
  while (true) {
    bool switchState = digitalRead(switchPin);

    // Turn on the device
    if (switchState == LOW && !deviceOn) {
      deviceOn = true;
      runDevice();
    }
    // Turn off the device
    else if (switchState == HIGH && deviceOn) {
      deviceOn = false;
      resetServos();
    }
  }
}

// runs the device
void runDevice() {
  String letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (int i = 0; i < letters.length(); i++) {
    executeLetter(letters[i]);
    resetServos();
    delay(pauseTime);
    if (digitalRead(switchPin) == HIGH) {
      break;
    }
  }
}

const int servoIndices[26][6] = {
  {0, -1, -1, -1, -1, -1}, // A
  {0, -1, 2, -1, -1, -1}, // B
  {0, 1, -1, -1, -1, -1}, // C
  {0, 1, -1, 3, -1, -1}, // D
  {0, -1, -1, 3, -1, -1}, // E
  {0, 1, 2, -1, -1, -1}, // F
  {0, 1, 2, 3, -1, -1}, // G
  {0, -1, 2, 3, -1, -1}, // H
  {-1, 1, 2, -1, -1, -1}, // I
  {-1, 1, 2, -1, -1, -1}, // J
  {0, -1, -1, -1, -1, 5}, // K
  {0, -1, 2, -1, 4, -1}, // L
  {0, 1, -1, -1, 4, -1}, // M
  {0, 1, -1, 3, 4, -1}, // N
  {0, -1, -1, 3, 4, -1}, // O
  {0, 1, 2, -1, 4, -1}, // P
  {0, 1, 2, 3, 4, -1}, // Q
  {0, -1, 2, 3, 4, -1}, // R
  {-1, 1, 2, -1, 4, -1}, // S
  {-1, 1, 2, 3, 4, -1}, // T
  {0, -1, -1, -1, 4, 5}, // U
  {0, -1, 2, -3, 4, 5}, // V
  {-1, 1, 2, 3, -1, 5}, // W
  {0, 1, -1, -1, 4, 5}, // X
  {0, 1, -1, 3, 4, 5}, // Y
  {0, -1, -1, 3, 4, 5} // Z
};

void executeLetter(char letter) {
  int* servoIndicesForLetter = servoIndices[letter - 'A'];
  for (int i = 0; i < servoCount; i++) {
    int servoIndex = servoIndicesForLetter[i];
    if (servoIndex >= 0) {
      servos[servoIndex].write(0);
    }
  }
  delay(pauseTime);
}

// reset servos to 90 degree angle (default position)
void resetServos() {
  for (int i = 0; i < servoCount; i++) {
    servos[i].write(90); 
  }
}
