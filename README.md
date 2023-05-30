# Arduino code for BHFF Passion Project

## Servo Control for Alphabet Display
This Arduino project controls a set of six servos to display the letters of the alphabet. The servos are controlled based on the state of a switch. When the switch is turned on, the servos start displaying the letters of the alphabet one by one. When the switch is turned off, the servos reset to their original position.

## Hardware Requirements
Arduino board
6 Servo motors
1 Switch
Pin Configuration
The servo motors are connected to the following pins:

Servo 1: Pin 1
Servo 2: Pin 2
Servo 3: Pin 3
Servo 4: Pin 4
Servo 5: Pin 5
Servo 6: Pin 6
The switch is connected to Pin 11.

## Software
The Arduino code controls the servos based on the state of the switch. When the switch is turned on, the servos start moving to display the letters of the alphabet. Each letter is displayed for a duration specified by the pauseTime constant (currently set to 250ms). When the switch is turned off, the servos reset to their original position.

The mapping of servo movements to letters is defined in the servoIndices array. Each row of the array corresponds to a letter of the alphabet (in order from A to Z), and each column corresponds to a servo (from 1 to 6). The value in each cell of the array is the position that the corresponding servo should move to when displaying the corresponding letter.

## Usage
Upload the Arduino code to your Arduino board, and ensure that your servos and switch are connected to the correct pins. Turn on the switch to start displaying the letters, and turn off the switch to reset the servos.
