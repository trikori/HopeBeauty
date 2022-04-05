/*
  Adapted code from:
    Servo Moto Basics with Arduino
    https://docs.arduino.cc/learn/electronics/servo-motors

    SIK Experiment Guide for Arduino - V3.2
    https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v32/experiment-9-using-a-flex-sensor
*/

#include <Servo.h> 

Servo Rwing;  //right wing
Servo Lwing;  //left wing

const int flexpin = A0; //pin A0 for flex sensor to be read as analog input

void setup() 
{
  Serial.begin(9600);

  Rwing.attach(9);    //pin 9 with PWN
  Lwing.attach(10);   //pin 10 with PWN
} 

//Adapted code from: SIK Experiment Guide for Arduino - V3.2
void loop()
{ 
  int flexposition;    // Input value from the analog pin.
  int servoposition;   // Output value to the servo.

  // Read the position of the flex sensor (0 to 1023):

  flexposition = analogRead(flexpin);

  // Because the voltage divider circuit only returns a portion
  // of the 0-1023 range of analogRead(), we'll map() that range
  // to the servo's range of 0 to 180 degrees. The flex sensors
  // we use are usually in the 600-900 range:

  servoposition = map(flexposition, 600, 900, 0, 180);
  servoposition = constrain(servoposition, 0, 180);

  if(flexposition >= 770)
  {
    //Adapted code from: Servo Moto Basics with Arduino
    for(servoposition = 0; servoposition < 70; servoposition += 1)  // goes from 0 degrees to 70 degrees 
    {                                  // in steps of 1 degree 
      Rwing.write(servoposition);              
      Lwing.write(servoposition);
      delay(15);                       // waits 15ms for the servo to reach the position  
    }

    //Adapted code from: Servo Moto Basics with Arduino
    for(servoposition = 70; servoposition >=1; servoposition -= 1)  // goes from 70 degrees to 0 degrees 
    {
      Rwing.write(servoposition);
      Lwing.write(servoposition);             
      delay(15);                       // waits 15ms for the servo to reach the position                             
    }
  }
} 
