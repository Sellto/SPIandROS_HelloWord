//SpiSlave object have 3 properties :
// command   : byte which contains the register
// dataSize  : byte which contains the size of the msg
// msg       : bytes arrays. 
//SLK  : pin 13
//MISO : pin 12
//MOSI : pin 11 

#include <SPIslave.h>

SpiSlave mySPI;

#define led 4
#define SS 10

void setup() {
mySPI.begin();
pinMode(led ,OUTPUT);
}

void loop() {
  //Reset the data when there isn't any communication.
  if (digitalRead(SS) == HIGH){
      mySPI.reset();
      }
}


//Interrupt needed by SPI Communication
ISR (SPI_STC_vect) {
    mySPI.com(SPDR); 
    if(mySPI.endTrans) {
      spiReg();//Function called at the end of the communication.
      }
}


//Function which contains the action binded to each registers.
void spiReg(){  
switch (mySPI.command) {
  case 0x01:
    digitalWrite(led, (int) mySPI.msg[0]);
    break;
  } 
}

