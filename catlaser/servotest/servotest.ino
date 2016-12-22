/*
Into Robotics
*/
 
#include <Servo.h>
 
int servoPin = 9;
 
Servo servo;  
 
int servoAngle = 0;   // servo position in degrees
 
void setup()
{
  Serial.begin(9600);  
  servo.attach(servoPin);
}
 
 
void loop()
{ 
   //servo.write(45);      
   delay(1000);          
   //servo.write(90);      
   delay(1000);          
}
