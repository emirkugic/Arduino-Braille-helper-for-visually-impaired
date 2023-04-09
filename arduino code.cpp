#include <Servo.h>

//connection pins
const int servo1Pin = 1;
const int servo2Pin = 2;
const int servo3Pin = 3;
const int servo4Pin = 4;
const int servo5Pin = 5;
const int servo6Pin = 6;

//switch pin
int switchPin = 11;



//settings constants and instances for electronics, etc
const int pauseTime = 250;
Servo servo1, servo2, servo3, servo4, servo5, servo6;
const int servoCount = 6;
Servo servos[servoCount] = {servo1, servo2, servo3, servo4, servo5, servo6};
int servoPins[servoCount] = {servo1Pin, servo2Pin, servo3Pin, servo4Pin, servo5Pin, servo6Pin};
int servoOriginalPositions[servoCount];
//delay between letters
const int letterDelay = pauseTime;


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
bool shouldStop = false;
bool switchState = false;

//function for the on and off switch
void powerSwitch() {
  while (true) {
    bool switchState = digitalRead(switchPin);

    // Turn on the device
    if (switchState == LOW && !deviceOn) {
      deviceOn = true;
      shouldStop = false;
      runDevice();
    }
    // Turn off the device
    else if (switchState == HIGH && deviceOn) {
      deviceOn = false;
      shouldStop = true;
      resetServos();
    }
  }
}




// runs the device
void runDevice() {
  String letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (int i = 0; i < 26; i++) {
    executeLetter(letters[i]);
    resetServos();
    delay(pauseTime);
    if (digitalRead(switchPin) == HIGH) {
      break;
    }
    if (i>26){
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
      int servoPosition = getServoPositionForLetter(letter, i);
      servos[servoIndex].write(servoPosition);
    }
  }
  delay(letterDelay);
}


//this function tells the arduino which servo to move for which letter
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



