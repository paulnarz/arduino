#include <Servo.h>

Servo x_servo;  
Servo y_servo;

void setup() {
  y_servo.attach(6);  // attaches the y servo on pin 6 to the servo object
  x_servo.attach(9);  // attaches the x servo on pin 9 to the servo object
  //TURN EVERYTHING OFF
  pinMode (12, OUTPUT);
  digitalWrite (12, LOW);
  digitalWrite (12, HIGH);
  x_servo.write(90); y_servo.write(10); 

  Serial.begin(9600);
  Serial.print("Hello");
}

char incomingChar = 0;
void loop() {   
  int x = x_servo.read();
  int y = y_servo.read();
  int d = 5;

  while (Serial.available() > 0) {
    incomingChar = (char)Serial.read();
    Serial.println(incomingChar);
    if (incomingChar == 'w') {
      move(x, y + d);
    }
    else if (incomingChar == 's') {
      move(x, y - d);
    }
    else if (incomingChar == 'a') {
      move(x + d, y);
    }
    else if (incomingChar == 'd') {
      move(x - d, y);
    }        
  }
}

void move(int x, int y) {
  if (x < 0)
    x = 0;
  else if (x > 180)
    x = 180;
  if (y < 0)
    y = 0;
  else if (y > 180)
    y = 180;

  Serial.print("move (");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(")");
  Serial.println();  

  y_servo.attach(6);  // attaches the y servo on pin 6 to the servo object
  x_servo.attach(9);  // attaches the x servo on pin 9 to the servo object
  x_servo.write(x); y_servo.write(y); 
  delay(100);
  y_servo.detach();
  x_servo.detach();  
}

