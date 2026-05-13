# Arduino-Uno-Radar
Radar with customisable scan range using a 5V stepper motor, a joystick, buttons and an ultrasonic sensor.

PARTS LIST:

1 x Arduino Uno

1 x Breadboard 

1 x 28BYJ-48 5V stepper motor

1 x ULN2003 module

1 x HC-SR04 ultrasonic sensor

1 x HW-504 joystick

2 x Push buttons/tact switches 

A load of wires

<img width="400" height="500" alt="IMG_5003" src="https://github.com/user-attachments/assets/766c05da-cb17-445e-8d31-244d762f09e5" />

WIRING:

Computer USB                     ->            Arduino

Arduino 5V                       ->            Breadboard + rail

Arduino GND                      ->            Breadboard - rail

28BYJ-48 5V stepper motor        ->            ULN2003

ULN2003 +5v                      ->            Breadboard + rail

ULN2003 -5v                       ->           Breadboard - rail

ULN2003 IN1                      ->            Arduino pin 8

ULN2003 IN2                      ->            Arduino pin 9

ULN2003 IN3                      ->            Arduino pin 10

ULN2003 IN4                      ->            Arduino pin 11

HC-SR04 VCC                      ->            Breadboard + rail

HC-SR04 GND                      ->            Breadboard - rail

HC-SR04 Trig                     ->            Arduino pin 6

HC-SR04 Echo                     ->            Arduino pin 7

HW-504 +5v                       ->            Breadboard + rail

HW-504 GND                       ->            Breadboard - rail

HW-504 VRx                       ->            Arduino pin A0

Left button +                    ->            Arduino pin 2

Left button -                    ->            Breadboard - rail

Right button +                   ->            Arduino pin 3

Right button -                   ->            Breadboard - rail


<img width="350" height="500" alt="IMG_5004" src="https://github.com/user-attachments/assets/8610b138-93f3-4bad-b3fb-f5f39f0eb9e1" />


HOW TO USE:

1. Make sure everything is wired up correctly as instructed above
2. Open Arduino IDE
3. Download and open the file named 'StepMotorRadarSetLimitsArduino.ino'
4. Upload that code to your Arduino Uno via Arduino IDE
5. Test the code uploaded correctly:
   Move the joystick left and right - the radar should move.
   Set your max angle for the left
   Press the left button
   Set your max angle for the right
   Press the right button
   The radar should now start to sweep at the set range.

   
6. *IMPORTANT* - Close Arduino IDE
7. Install & open Processing
8. Download and open the file named 'Radar_Working.pde'
9. Click on 'run'
10. Set your range for the left using the joystick
11. Press the button on the left
12. Set your range for the right using the joystick
13. Press the button on the right
14. The radar is now monitoring at your set range!
