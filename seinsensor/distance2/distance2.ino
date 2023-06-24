#define trigPin 2
#define echoPin 3
//#define led 11
//#define led2 10

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //pinMode(led, OUTPUT);
  //pinMode(led2, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  distance = distance * 2.54; //convert cm to inches
  
  /*
  if (distance < 4) {  // This is where the LED On/Off happens
  digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
 }
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  */
  
   Serial.print("duration: ");
   Serial.print(duration);
   Serial.println("");

  delay(100);
}
