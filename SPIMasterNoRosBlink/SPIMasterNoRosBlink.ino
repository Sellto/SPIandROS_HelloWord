//SPIMaster 
//Command the led of the SpiSlaveHW.
//Connection : 
//SLK  : pin 13
//MISO : pin 12
//MOSI : pin 11


#include <SPIManager.h>
#include <SPI.h>

#define SERIAL_BAUD 57600
#define SPI_SS_Green  10
#define SPI_SS_Red    9

SPIManager conn_with_Green(SPI_SS_Green);
SPIManager conn_with_Red(SPI_SS_Red);

void setup() {
  Serial.begin(SERIAL_BAUD);
  conn_with_Green.initialize();
  conn_with_Red.initialize();
  delay(1000);
}

void loop() {
  conn_with_Green.writeData(0x01, 0x01, 0x01);
  conn_with_Red.writeData(0x01, 0x01, 0x00);
  delay(1000);
  conn_with_Green.writeData(0x01, 0x01, 0x00);
  conn_with_Red.writeData(0x01, 0x01, 0x01);
  delay(1000);
}
