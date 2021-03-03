#include "Wire.h"
#define PCF8591 0x48 // I2C bus address
#define PCF8591_ADC_CH0 0x00 // thermistor
#define PCF8591_ADC_CH1 0x01 // photo-voltaic cell
#define PCF8591_ADC_CH2 0x02
#define PCF8591_ADC_CH3 0x03 // potentiometer 
byte ADC1, ADC2, ADC3;

void setup()
{  
  Wire.begin();
  Serial.begin(9600);
}
void loop()
{
  // read thermistor
  Wire.beginTransmission(PCF8591); 
  Wire.write((byte)PCF8591_ADC_CH0); 
  Wire.endTransmission(); 
  delay(100);
  Wire.requestFrom(PCF8591, 2);
  delay(100);
  ADC1=Wire.read();
  ADC1=Wire.read();

  Serial.print("Thermistor=");
  Serial.println(ADC1); 
  
  // read photo-voltaic cell
  Wire.beginTransmission(PCF8591); 
  Wire.write(PCF8591_ADC_CH1); 
  Wire.endTransmission(); 
  delay(100);
  Wire.requestFrom(PCF8591, 2);
  delay(100);
  ADC2=Wire.read();
  ADC2=Wire.read();

  Serial.print("Photo-voltaic cell=");
  Serial.println(ADC2); 

  // potentiometer 
  Wire.beginTransmission(PCF8591); 
  Wire.write(PCF8591_ADC_CH3); 
  Wire.endTransmission(); 
  delay(100);
  Wire.requestFrom(PCF8591, 2);
  delay(100);
  ADC3=Wire.read();
  ADC3=Wire.read();

  Serial.print("potentiometer=");
  Serial.println(ADC3); 
  
  delay(500);
}
