# Arduino code for BHFF Passion Project

This code is written in the Arduino language and is designed to control a robotic arm that uses six servos. It uses the Servo library to control the servos and the digitalRead function to read the state of a switch that turns the device on and off.

The connection pins for the six servos are defined as constants servo1Pin through servo6Pin, with their values set to 1 through 6, respectively.

The setup() function initializes the servos by attaching them to their corresponding pins using the attach() method of the Servo library. The current position of each servo is stored in an array servoOriginalPositions for later use.

The loop() function repeatedly calls the powerSwitch() function, which reads the state of the switch using the digitalRead() function and either turns the device on or off. When the device is turned on, the runDevice() function is called to execute a sequence of movements using the six servos. The sequence of movements is determined by the executeLetter() function, which takes a letter as input and moves the servos accordingly. The sequence of letters to be executed is the string "ABCDEFGHIJKLMNOPQRSTUVWXYZ". If the switch is turned off during the sequence of movements, the function resetServos() is called to reset the position of all the servos to their original positions.

The executeLetter() function uses a two-dimensional array servoIndices to map each letter to the indices of the servos that should be moved for that letter. The first index of the array corresponds to the letter, with 'A' represented as 0, 'B' represented as 1, and so on. The second index of the array corresponds to the servo, with 0 representing the first servo, 1 representing the second servo, and so on. If the value in the array is -1, that means the servo should not move for that letter. If the value is 0 or greater, it represents the index of the servo that should move. The getServoPositionForLetter() function is called to determine the position that each servo should move to for the given letter. The positions are stored in an array servoPositions.
