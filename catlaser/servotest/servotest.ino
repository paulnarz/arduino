#include <Servo.h>

Servo x_servo;  
Servo y_servo;

float min_x = 90 - 35;
float max_x = 90 + 35;
float min_y = 90 - 20;
float max_y = 90 + 40;

void setup() {
  y_servo.attach(6);  // attaches the y servo on pin 6 to the servo object
  x_servo.attach(9);  // attaches the x servo on pin 9 to the servo object
  pinMode (12, OUTPUT);
  digitalWrite (12, HIGH);    
  x_servo.write(90); y_servo.write(90); delay(1000);  
}


void loop() {   
  x_servo.write(min_x); y_servo.write(min_y); delay(500);
  x_servo.write(max_x); y_servo.write(min_y); delay(500);
  x_servo.write(max_x); y_servo.write(max_y); delay(500);
  x_servo.write(min_x); y_servo.write(max_y); delay(500);
}
