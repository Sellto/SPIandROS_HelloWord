//SPI Manager drive by ROSSERIAL.
#include <SPIManager.h>
#include <ros.h>
#include <std_msgs/Float32.h>
#include <SPI.h>

#define SERIAL_BAUD 57600
#define SPI_SS_Green  10
#define SPI_SS_Red    9

SPIManager conn_with_Green(SPI_SS_Green);
SPIManager conn_with_Red(SPI_SS_Red);

float lightSpeed = 200.000;
byte ledOn  = 0x01;
byte ledOff = 0x00;


//Start ROS handle.
ros::NodeHandle nh;

std_msgs::Float32 str_msg;
void green( const std_msgs::Float32 & toggle_msg){
  lightSpeed = toggle_msg.data;
  //Serial communication disable SPI.
  //Need to initialise SPI Communication at each Call.
  conn_with_Green.initialize();
  conn_with_Green.writeData(0x01, 0x01, ledOn);
  delay(lightSpeed);
  conn_with_Green.writeData(0x01, 0x01, ledOff);
  delay(lightSpeed);  
  conn_with_Green.writeData(0x01, 0x01, ledOn);
  delay(lightSpeed);
  conn_with_Green.writeData(0x01, 0x01, ledOff);
  delay(lightSpeed);
  conn_with_Green.writeData(0x01, 0x01, ledOn);
  delay(lightSpeed);
  conn_with_Green.writeData(0x01, 0x01, ledOff);
  delay(lightSpeed);
}

void red( const std_msgs::Float32 & toggle_msg){
  lightSpeed = toggle_msg.data;
  //Serial communication disable SPI.
  //Need to initialise SPI Communication at each Call.
  conn_with_Red.initialize();
  conn_with_Red.writeData(0x01, 0x01, ledOn);
  delay(lightSpeed);
  conn_with_Red.writeData(0x01, 0x01, ledOff);
  delay(lightSpeed);  
  conn_with_Red.writeData(0x01, 0x01, ledOn);
  delay(lightSpeed);
  conn_with_Red.writeData(0x01, 0x01, ledOff);
  delay(lightSpeed);
  conn_with_Red.writeData(0x01, 0x01, ledOn);
  delay(lightSpeed);
  conn_with_Red.writeData(0x01, 0x01, ledOff);
  delay(lightSpeed);
}

ros::Subscriber<std_msgs::Float32> ledspeedgreen("SPIBrokerGreen", &green);
ros::Subscriber<std_msgs::Float32> ledspeedred  ("SPIBrokerRed", &red);

void setup() {
  nh.initNode();
  nh.subscribe(ledspeedgreen);
  nh.subscribe(ledspeedred);
  Serial.begin(SERIAL_BAUD);
  if (conn_with_Green.initialize())
  {
    //Blink once when SPI is initialized.
    conn_with_Green.writeData(0x01, 0x01, ledOn);
    delay(lightSpeed);
    conn_with_Green.writeData(0x01, 0x01, ledOff);
    delay(lightSpeed);
  }
  if (conn_with_Red.initialize())
  {
    //Blink once when SPI is initialized.
    conn_with_Red.writeData(0x01, 0x01, ledOn);
    delay(lightSpeed);
    conn_with_Red.writeData(0x01, 0x01, ledOff);
    delay(lightSpeed);
  }
}


//the loop contains is empty.
void loop() {
  nh.spinOnce();
}
