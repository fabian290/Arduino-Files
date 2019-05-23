#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>                                                                                    

#define led 12
RF24 radio(8, 9); // CE, CSN

//connection between NRF24L1
const byte address[6] = "00001";


void setup() {
  Serial.begin(9600);
  radio.begin();
radio.setChannel(12);
  radio.openWritingPipe(address);
  //
  //power amplifier level and also the MIN means that we aew using the 3v3  
  radio.setPALevel(RF24_PA_MIN);

  radio.stopListening();
}
void loop() {
  Serial.println("loop");
  const char text[] = "Hello World";
  int num = 12;

  if (radio.isChipConnected()) {
    Serial.println("connected");
  }

  //sending the message to the reciever
  if (!radio.write(&text, sizeof(text))) {
    Serial.println("error");
  } else {
    Serial.println("success");
  }
  Serial.println("done");
  delay(1000);
}

