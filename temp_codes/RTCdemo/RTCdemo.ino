#include <RTCZero.h>
#include "time.h"

RTCZero rtc;
void setup() {
  while (!Serial);
  Serial.begin(9600);

  rtc.begin(); // initialize RTC

  Serial.println("RTC set time");
  // set the current time 10 August 2019 7:23 AM
  rtc.setDate(10, 8, 19);
  rtc.setTime(7, 23, 00);  
  delay(1000);

  Serial.println("RTC Read time");
  Serial.println("-------------------");
}

void loop() {
  Serial.print("RTC, Time = ");
  print2digits(rtc.getMinutes());
  Serial.write(':');
  print2digits(rtc.getHours());
  Serial.write(':');
  print2digits(rtc.getSeconds());
  Serial.print(", Date (D/M/Y) = ");
  Serial.print(rtc.getDay());
  Serial.write('/');
  Serial.print(rtc.getMonth());
  Serial.write('/');
  Serial.print(rtc.getYear());
  Serial.println();
  delay(1000);
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}
