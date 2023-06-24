#define soundPin 4
#define trigPin 2
#define echoPin 3

//http://www.micropik.com/PDF/HCSR04.pdf
//Test distance = (high level time×velocity of sound (340M/S) / 2, 
//Formula: 
//uS / 58 = centimeters
//uS / 148 =inch
//the range = high level time * velocity (340M/S) / 2;
//we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal. 

void setup() {
  Serial.begin(9600);
  pinMode(soundPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  digitalWrite(soundPin, LOW);  
}

void loop() {
  long duration;
  long distance;  
  boolean trigger;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  
  distance = duration / 148;

  trigger = duration < 1776; //1 foot

  Serial.print("duration: ");
  Serial.print(duration);
  Serial.print(" trigger: ");
  Serial.print(trigger);
  Serial.print(" distance: ");
  Serial.print(distance);  
  Serial.print(" in");
  Serial.println();

  if (trigger) {
    digitalWrite(soundPin, HIGH);
    delay(500);
    digitalWrite(soundPin, LOW);
    delay(3000);
  }
  else {
    digitalWrite(soundPin, LOW);
    delay(500); 
  }  
}
