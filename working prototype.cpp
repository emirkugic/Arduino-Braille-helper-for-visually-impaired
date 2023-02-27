#include <Servo.h>


const int servo1Pin = 1;
const int servo2Pin = 2;
const int servo3Pin = 3;
const int servo4Pin = 4;
const int servo5Pin = 5;
const int servo6Pin = 6;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

const int servoCount = 6;
Servo servos[servoCount] = {servo1, servo2, servo3, servo4, servo5, servo6};
int servoPins[servoCount] = {servo1Pin, servo2Pin, servo3Pin, servo4Pin, servo5Pin, servo6Pin};
int servoOriginalPositions[servoCount];

const int letterDelay = 1500;

void setup() {
  for (int i = 0; i < servoCount; i++) {
    servos[i].attach(servoPins[i]);
    servoOriginalPositions[i] = servos[i].read(); // store original servo positions
  }
}


void loop() {
  executeLetter('A');
  resetServos();
  delay(1000);

  executeLetter('B');
  resetServos();
  delay(1000);

  executeLetter('C');
  resetServos();
  delay(1000);

  executeLetter('D');
  resetServos();
  delay(1000);

  executeLetter('E');
  resetServos();
  delay(1000);

  while (true) {
    // loop forever
  }
}


void executeLetter(char letter) {
  int servoIndices[servoCount] = {-1, -1, -1, -1, -1, -1}; // initialize all to -1




  switch (letter) {
    case 'A':
      servoIndices[0] = 0;
      break;
    case 'B':
      servoIndices[0] = 0;
      servoIndices[2] = 2;
      break;
    case 'C':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      break;
    case 'D':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      servoIndices[3] = 3;
      break;
    case 'E':
      servoIndices[0] = 0;
      servoIndices[3] = 3;
      break;
  }

  for (int i = 0; i < servoCount; i++) {
    int servoIndex = servoIndices[i];
    if (servoIndex >= 0) {
      int servoPosition = getServoPositionForLetter(letter, i);
      servos[servoIndex].write(servoPosition);
    }
  }

  delay(letterDelay);
}

int getServoPositionForLetter(char letter, int servoIndex) {
    switch (letter) {

    case 'A':
    if (servoIndex == 0) {
        return 0;
    }
    break;

    case 'B':
    if (servoIndex == 0 || servoIndex == 2) {
        return 0;
    } else if (servoIndex == 1) {
    return 180;
    }
    break;

    case 'C':
    if (servoIndex == 0 || servoIndex == 1) {
        return 0;
    } else if (servoIndex == 2) {
        return 180;
    }
    break;

    case 'D':
    if (servoIndex == 0 || servoIndex == 1 || servoIndex == 3) {
        return 0;
    } else if (servoIndex == 2) {
        return 90;
    } else if (servoIndex == 4) {
        return 90;
    }
    break;

    case 'E':
    if (servoIndex == 0 || servoIndex == 3) {
        return 0;
        } else if (servoIndex == 1 || servoIndex == 4) {
        return 90;
    }
    break;
    }

    // return original position if no position was returned earlier
    return servoOriginalPositions[servoIndex];
    }



void resetServos() {
  for (int i = 0; i < servoCount; i++) {
    servos[i].write(90); // reset servos to zero degree angle
  }
}


