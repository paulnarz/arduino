#include <Servo.h>

Servo x_servo;  
Servo y_servo;

void setup() {
  y_servo.attach(6);  // attaches the y servo on pin 6 to the servo object
  x_servo.attach(9);  // attaches the x servo on pin 9 to the servo object
  //TURN EVERYTHING OFF
  pinMode (12, OUTPUT);
  digitalWrite (12, LOW);
  x_servo.write(90); y_servo.write(0);
  delay(500);
  y_servo.detach();
  x_servo.detach();
}


void loop() {   
}
