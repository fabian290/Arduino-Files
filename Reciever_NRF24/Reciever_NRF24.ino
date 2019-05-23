#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//#include <Servo.h>
//#define button 4
#define ENB 6   // Left  wheel speed
#define IN1 2   // Left  wheel forward
#define IN2 3   // Left  wheel reverse
#define IN3 4   // Right wheel reverse
#define IN4 1 // Right wheel forward
#define ENA 5  // Right wheel speed
#define carSpeed 200  // initial speed of car >=0 to <=255

RF24 radio(7, 8); // CE, CSN
//const byte addresses[][6] = {"00007", "00002"};
const byte address[6] = "00001";
//Servo myServo;
//boolean buttonState = 0;
void setup() {
  Serial.begin(9600);
  //pinMode(button, INPUT);
  //myServo.attach(5);
  radio.begin();
 radio.setChannel(12);
  radio.openReadingPipe(0, address); // 00001
  radio.setPALevel(RF24_PA_MIN);
  
  radio.startListening();
}

void forward() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go forward!"); 
}

void back(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("go back!");
}
void left(){

  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  Serial.println("go left!");
}

void right(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("go right!");
}

void stop(){
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("STOP!");
} 


void loop() {

  //Serial.println("is chip connected?" + String(radio.isChipConnected()));
  Serial.print(",");
  if (radio.available()) {

    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);

    if (String(text) == "forward") {

     forward();
    }
    else if (String(text) == "backward") {
      back();
    }
    else if (String(text) == "right"){  
      right();
    }
    else if (String(text) == "left") {
      left();
    }

    else {
      
      stop();

     
    }
  }
  
}
                                                        
