//http://www.micropik.com/PDF/HCSR04.pdf
//Test distance = (high level time×velocity of sound (340M/S) / 2, 
//Formula: 
//uS / 58 = centimeters
//uS / 148 =inch
//the range = high level time * velocity (340M/S) / 2;
//we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal. 

#define soundPin 4
#define trigPin 2
#define echoPin 3
#define ledPin 13

#define STATE_TESTING 0
#define STATE_ARMED 1
#define STATE_TRIGGERED 2

int state;

void setup() {
  Serial.begin(9600);
  
  pinMode(soundPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  digitalWrite(soundPin, LOW);
  digitalWrite(ledPin, LOW);
  
  state = STATE_TESTING;
  delay(5000);  
}

void loop() {
  if (state == STATE_TESTING) {
    state = STATE_ARMED;
  }
  else if (state == STATE_ARMED) {
    if (checkTrigger()) {
      state = STATE_TRIGGERED;
      digitalWrite(soundPin, HIGH);           
      digitalWrite(ledPin, LOW);      
    }
    else {
      digitalWrite(soundPin, LOW);
      digitalWrite(ledPin, HIGH);
      delay(1000);
    }      
  }  
}

boolean checkTrigger() {
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
  
  return trigger;
}

