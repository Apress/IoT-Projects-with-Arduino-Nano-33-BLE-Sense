#include <SPI.h>

byte sendData,recvData;
void setup() {  
  SPI.begin();
  Serial.begin(9600);
  randomSeed(80);
}

void loop() {
  sendData = random(50, 100);
  recvData = SPI.transfer(sendData);

  Serial.print("Send=");
  Serial.println(sendData,DEC);
  Serial.print("Recv=");
  Serial.println(recvData,DEC);
  delay(800);
}
