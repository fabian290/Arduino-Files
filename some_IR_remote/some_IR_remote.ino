
//this project contains modified numbers for the joystick in which only my 
//joystcks work
#include <IRremote.h>

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A3; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

IRsend irsend;
#define FORWARD 16736929
#define BACKWARD 16754778
#define LEFT    16720609
#define RIGHT   16761407
#define STOP    16712449
void setup() {
  // put your setup code here, to run once:

   
  
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println (analogRead(Y_pin));
  if (analogRead(Y_pin) <= 3)  {

    irsend.sendNEC(FORWARD, 32);
  
  
    
  } else if  (analogRead(Y_pin) >= 900)  {

      irsend.sendNEC(BACKWARD, 32);

      

   } else if  (analogRead(X_pin) <= 3)  {

      irsend.sendNEC(LEFT, 32);

    }  else if  (analogRead(X_pin) >= 900)  {

      irsend.sendNEC(RIGHT, 32);

    }

    
  
       delay(15);
  
}
