/***************************************************************************
  This is a library for the APDS9960 digital proximity, ambient light, RGB, and gesture sensor

  This sketch puts the sensor in gesture mode and decodes gestures.
  To use this, first put your hand close to the sensor to enable gesture mode.
  Then move your hand about 6" from the sensor in the up -> down, down -> up, 
  left -> right, or right -> left direction.

  Designed specifically to work with the Adafruit APDS9960 breakout
  ----> http://www.adafruit.com/products/3595

  These sensors use I2C to communicate. The device's I2C address is 0x39

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;
int aval_3 = 0;
int aval_4 = 0;
int aval_5 = 0;

// the setup function runs once when you press reset or power the board
void setup() { 
  Serial.begin(9600);  
  
  if(!apds.begin()){
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");

  //gesture mode will be entered once proximity mode senses something close
  apds.enableProximity(true);
  apds.enableGesture(true);
}

// the loop function runs over and over again forever
void loop() {
  //read a gesture from the device
    if (true) {
      uint8_t gesture = apds.readGesture();
      if(gesture == APDS9960_DOWN) Serial.println("v");
      if(gesture == APDS9960_UP) Serial.println("^");
      if(gesture == APDS9960_LEFT) Serial.println("<");
      if(gesture == APDS9960_RIGHT) Serial.println(">");  
    }
    else {
      aval_3 = analogRead(3);
      aval_4 = analogRead(4);
      aval_5 = analogRead(5);
      Serial.print("Test");
      Serial.print(" 3: ");
      Serial.print(aval_3);
      Serial.print(" 4: ");
      Serial.print(aval_4);
      Serial.print(" 5: ");
      Serial.print(aval_5);
      Serial.println();
    }    
}
