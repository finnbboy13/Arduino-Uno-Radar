# Arduino-Uno-Radar
Radar with customisable scan range, using a 5V stepper motor and an ultrasonic sensor.

PARTS LIST:

1 x Arduino Uno

1 x Breadboard 

1 x 28BYJ-48 5V stepper motor

1 x ULN2003 module

1 x HC-SR04 Ultrasonic sensor

1 x Joystick

2 x Push buttons/Tact switches 

A load of wires


WIRING:

USB                              ->            Arduino

Arduino 5V                       ->            Breadboard + rail

Arduino GND                      ->            Breadboard - rail

28BYJ-48 5V stepper motor        ->            ULN2003 module

ULN2003 module 5v +              ->            Breadboard + rail

ULN2003 module 5v -              ->            Breadboard - rail

TO BE CONTINUED.........





HOW TO USE:

1. Make sure everything is wired up correctly as instructed above
2. Open Arduino IDE
3. Download and open the file named 'StepMotorRadarSetLimitsArduino'
4. Upload that code to your Arduino Uno via Arduino IDE
5. Test the code uploaded correctly:
   Move the joystick left and right - the radar should move.
   Set your max angle for the left
   Press the left button
   Set your max angle for the right
   Press the right button
   The radar should now start to sweep at the set range.

6. *IMPORTANT* Close Arduino IDE *IMPORTANT*
7. Install & open Processing
8. Download and open the file named 'Radar_Working.pde'
9. Click on 'run'
10. Set your range for both the left and the right and you should now have a fully working radar!
