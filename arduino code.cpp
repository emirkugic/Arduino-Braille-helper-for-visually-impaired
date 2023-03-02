#include <Servo.h>

//connection pins
const int servo1Pin = 1;
const int servo2Pin = 2;
const int servo3Pin = 3;
const int servo4Pin = 4;
const int servo5Pin = 5;
const int servo6Pin = 6;
const int LED_PIN = 7;


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


//moves all the servos
void loop() {
  String letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (int i = 0; i < 26; i++) {
    executeLetter(letters[i]);
    turnOnLED();
    resetServos();
    delay(1000);
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
      servoIndices[1] = 1;
      servoIndices[2] = 2;
      servoIndices[4] = 4;
      break;
    
    case 'T':
      servoIndices[1] = 1;
      servoIndices[2] = 2;
      servoIndices[3] = 3;
      servoIndices[4] = 4;
      break;
    
    case 'U':
      servoIndices[0] = 0;
      servoIndices[4] = 4;
      servoIndices[5] = 5;
      break;
    
    case 'V':
      servoIndices[0] = 0;
      servoIndices[2] = 2;
      servoIndices[4] = 4;
      servoIndices[5] = 5;
    break;
    
    case 'W':
      servoIndices[1] = 1;
      servoIndices[2] = 2;
      servoIndices[3] = 3;
      servoIndices[5] = 5;
      break;
      
    case 'X':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      servoIndices[4] = 4;
      servoIndices[5] = 5;
      break;
      
    case 'Y':
      servoIndices[0] = 0;
      servoIndices[1] = 1;
      servoIndices[3] = 3;
      servoIndices[4] = 4;
      servoIndices[5] = 5;
      break;
      
    case 'Z':
      servoIndices[0] = 0;
      servoIndices[3] = 3;
      servoIndices[4] = 4;
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

//this function moves the servos to their position
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
            }
            break;


        case 'C':
            if (servoIndex == 0 || servoIndex == 1) {
                return 0;
            }
            break;


        case 'D':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 3) {
                return 0;
            }
            break;


        case 'E':
            if (servoIndex == 0 || servoIndex == 3) {
                return 0;
            }
            break;


        case 'F':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 2) {
                return 0;
            }
            break;


        case 'G':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 2 || servoIndex == 3) {
                return 0;
            }
            break;


        case 'H':
          if (servoIndex == 0 || servoIndex == 1 || servoIndex == 2 || servoIndex == 3) {
            return 0;
          }
          break;


        case 'I':
            if (servoIndex == 1 || servoIndex == 2) {
                return 0;
            }
            break;


        case 'J':
            if (servoIndex == 1 || servoIndex == 2 || servoIndex == 3) {
                return 0;
            }
            break; 


        case 'K':
            if (servoIndex == 0 || servoIndex == 4) {
                return 0;
            }
            break;
            
            

        case 'L':
            if (servoIndex == 0 || servoIndex == 2 || servoIndex == 4) {
                return 0;
            }
            break;
            

        case 'M':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 4) {
                return 0;
            }
            break;

        case 'N':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 3 || servoIndex == 4) {
                return 0;
            }
            break;
            

        case 'O':
            if (servoIndex == 0 || servoIndex == 3 || servoIndex == 4) {
                return 0;
            }
            break;
            

        case 'P':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 2 || servoIndex == 4) {
                return 0;
            }
            break;
            

        case 'Q':
            if (servoIndex == 0 || servoIndex == 1 || servoIndex == 2 || servoIndex == 3 || servoIndex == 4) {
                return 0;
            }
            break;
            

        case 'R':
            if (servoIndex == 0 || servoIndex == 2 || servoIndex == 3 || servoIndex == 4) {
                return 0;
            }
            break;
            

        case 'S':
            if (servoIndex == 1 || servoIndex == 2 || servoIndex == 4) {
                return 0;
            }
            break;
            

        case 'T':
            if (servoIndex == 1 || servoIndex == 2 || servoIndex == 3 || servoIndex == 4) {
                return 0;
            }
            break;
            

        case 'U':
            if (servoIndex == 0 || servoIndex == 4 || servoIndex == 5) {
              return 0;
            }
            break;


        case 'V':
          if (servoIndex == 0 || servoIndex == 2 || servoIndex == 4 || servoIndex == 5) {
            return 0;
          }
          break;


        case 'W':
          if (servoIndex == 1 || servoIndex == 2 || servoIndex == 3 || servoIndex == 4 || servoIndex == 5) {
            return 0;
          }
          break;


        case 'X':
          if (servoIndex == 0 || servoIndex == 1 || servoIndex == 4 || servoIndex == 5) {
            return 0;
          }
          break;


        case 'Y':
          if (servoIndex == 0 || servoIndex == 1 || servoIndex == 3 || servoIndex == 4 || servoIndex == 5) {
            return 0;
          }
          break;


        case 'Z':
          if (servoIndex == 0 || servoIndex == 3 || servoIndex == 4 || servoIndex == 5) {
            return 0;
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

//turn the LED for 1 sec
void turnOnLED() {
  digitalWrite(LED_PIN, HIGH);   
  delay(1000);                   
  digitalWrite(LED_PIN, LOW);    
}