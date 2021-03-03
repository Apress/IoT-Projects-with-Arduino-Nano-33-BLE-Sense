void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; 
  }
}

void loop() {
  int reading = analogRead(A0);  

  float voltage = reading * 3.3;
  voltage /= 1024.0; 
  
  // print out the voltage
  Serial.print(voltage); Serial.println(" volts");
  
  // now print out the temperature
  //converting from 10 mv per degree wit 500 mV offset
  //to degrees ((volatge - 500mV) times 100)
  float tempC = (voltage - 0.5) * 100 ;  

  
  Serial.print(tempC); 
  Serial.println(" degrees C");
  delay(3000);
}
