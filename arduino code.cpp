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

  executeLetter('F');
  resetServos();
  delay(1000);

  executeLetter('G');
  resetServos();
  delay(1000);

  executeLetter('H');
  resetServos();
  delay(1000);

  executeLetter('I');
  resetServos();
  delay(1000);

  executeLetter('J');
  resetServos();
  delay(1000);

  executeLetter('K');
  resetServos();
  delay(1000);

  executeLetter('L');
  resetServos();
  delay(1000);

  executeLetter('M');
  resetServos();
  delay(1000);

  executeLetter('N');
  resetServos();
  delay(1000);

  executeLetter('O');
  resetServos();
  delay(1000);

  executeLetter('P');
  resetServos();
  delay(1000);

  executeLetter('Q');
  resetServos();
  delay(1000);

  executeLetter('R');
  resetServos();
  delay(1000);

  executeLetter('S');
  resetServos();
  delay(1000);

  executeLetter('T');
  resetServos();
  delay(1000);

  executeLetter('U');
  resetServos();
  delay(1000);

  executeLetter('V');
  resetServos();
  delay(1000);

  executeLetter('W');
  resetServos();
  delay(1000);

  executeLetter('X');
  resetServos();
  delay(1000);

  executeLetter('Y');
  resetServos();
  delay(1000);

  executeLetter('Z');
  resetServos();
  delay(1000);

  while (true) {
    // needs to loop forever
  }
}


void executeLetter(char letter) {

  // initialize all to -1
  int servoIndices[servoCount] = {-1, -1, -1, -1, -1, -1}; 

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
    case 'F':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      servoIndices[2] = 2;
      break;
    case 'G':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      servoIndices[2] = 2;
      servoIndices[3] = 3;
      break;
    case 'H':
      servoIndices[0] = 0;
      servoIndices[2] = 2;
      servoIndices[3] = 3;
      break;
    case 'I':
      servoIndices[1] = 1;
      servoIndices[2] = 2;
      break;
    case 'J':
      servoIndices[1] = 1;
      servoIndices[2] = 2;
      servoIndices[3] = 3;
      break;
    case 'K':
      servoIndices[0] = 0;
      servoIndices[4] = 4;
      break;
    case 'L':
      servoIndices[0] = 0;
      servoIndices[2] = 2;
      servoIndices[4] = 4;
      break;
    case 'M':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      servoIndices[4] = 4;
      break;
    case 'N':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      servoIndices[3] = 3;
      servoIndices[4] = 4;
      break;
    case 'O':
      servoIndices[0] = 0;
      servoIndices[3] = 3;
      servoIndices[4] = 4;
      break;
    case 'P':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      servoIndices[2] = 2;
      servoIndices[4] = 4;
      break;
    case 'Q':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      servoIndices[2] = 2;
      servoIndices[3] = 3;
      servoIndices[4] = 4;
      break;
    case 'R':
      servoIndices[0] = 0;
      servoIndices[2] = 2;
      servoIndices[3] = 3;
      servoIndices[4] = 4;
      break;
    case 'S':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      servoIndices[3] = 3;
      servoIndices[4] = 4;
      break;
    
    case 'T':
      servoIndices[0] = 0;
      servoIndices[3] = 3;
      servoIndices[4] = 4;
      break;
    
    case 'U':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      servoIndices[5] = 5;
      break;
    
    case 'V':
      servoIndices[0] = 0;
      servoIndices[2] = 2;
      servoIndices[5] = 5;
    break;
    
    case 'W':
      servoIndices[1] = 1;
      servoIndices[3] = 3;
      servoIndices[4] = 4;
      servoIndices[5] = 5;
      break;
      
    case 'X':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      servoIndices[2] = 2;
      servoIndices[5] = 5;
      break;
      
    case 'Y':
      servoIndices[0] = 0;
      servoIndices[3] = 3;
      servoIndices[5] = 5;
      break;
      
    case 'Z':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      servoIndices[3] = 3;
      servoIndices[5] = 5;
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


        case 'F':
            if (servoIndex == 0 || servoIndex == 2) {
                return 0;
            } else if (servoIndex == 1 || servoIndex == 3) {
                return 90;
            }
            break;


        case 'G':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 3) {
                return 0;
            } else if (servoIndex == 2) {
                return 90;
            } else if (servoIndex == 4) {
                return 90;
            }
            break;


        case 'H':
          if (servoIndex == 0 || servoIndex == 1 || servoIndex == 2 || servoIndex == 3) {
            return 0;
          } else if (servoIndex == 4) {
            return 180;
          }
          break;


        case 'I':
            if (servoIndex == 1) {
                return 90;
            }
            break;


        case 'J':
            if (servoIndex == 0 || servoIndex == 2) {
                return 0;
            }   
            else if (servoIndex == 1 || servoIndex == 3) {
                return 90;
            } else if (servoIndex == 4) {
                return 180;
            }
            break;   


        case 'K':
            if (servoIndex == 0 || servoIndex == 2) {
                return 0;
            } else if (servoIndex == 1) {
                return 180;
            }
            break;
            

        case 'L':
            if (servoIndex == 0 || servoIndex == 1) {
                return 0;
            } else if (servoIndex == 2) {
                return 180;
            }
            break;
            

        case 'M':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 3) {
                return 0;
            } else if (servoIndex == 2) {
                return 90;
            } else if (servoIndex == 4) {
                return 90;
            }
            break;
            

        case 'N':
            if (servoIndex == 0 || servoIndex == 3) {
                return 0;
            } else if (servoIndex == 1 || servoIndex == 4) {
                return 90;
            }
            break;
            

        case 'O':
            if (servoIndex == 0 || servoIndex == 2 || servoIndex == 3) {
                return 0;
            } else if (servoIndex == 1 || servoIndex == 4) {
                return 90;
            }
            break;
            

        case 'P':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 2) {
                return 0;
            } else if (servoIndex == 3) {
                return 180;
            }
            break;
            

        case 'Q':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 2 || servoIndex == 4) {
                return 0;
            } else if (servoIndex == 3) {
                return 180;
            }
            break;
            

        case 'R':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 3) {
                return 0;
            } else if (servoIndex == 2 || servoIndex == 4) {
                return 90;
            }
            break;
            

        case 'S':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 2 || servoIndex == 4) {
                return 0;
            } else if (servoIndex == 3) {
                return 180;
            }
            break;
            

        case 'T':
            if (servoIndex == 0 || servoIndex == 3 || servoIndex == 4) {
                return 0;
            } else if (servoIndex == 1 || servoIndex == 2) {
                return 90;
            }
            break;
            

        case 'U':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 3 || servoIndex == 4) {
              return 0;
            } else if (servoIndex == 2) {
              return 180;
            }
            break;


        case 'V':
          if (servoIndex == 0 || servoIndex == 2 || servoIndex == 5) {
            return 90;
          }
          break;


        case 'W':
          if (servoIndex == 1 || servoIndex == 2 || servoIndex == 4 || servoIndex == 5) {
            return 90;
          }
          break;


        case 'X':
          if (servoIndex == 0 || servoIndex == 1 || servoIndex == 3 || servoIndex == 4) {
            return 90;
          }
          break;


        case 'Y':
          if (servoIndex == 0 || servoIndex == 1 || servoIndex == 3 || servoIndex == 5) {
            return 90;
          }
          break;


        case 'Z':
          if (servoIndex == 0 || servoIndex == 3 || servoIndex == 4 || servoIndex == 5) {
            return 90;
          }
          break;

    }

    // return original position if no position was returned earlier
    return servoOriginalPositions[servoIndex];
}




// reset servos to 90 degree angle (default position)
void resetServos() {
  for (int i = 0; i < servoCount; i++) {
    servos[i].write(90); 
  }
}

