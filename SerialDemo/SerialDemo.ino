int led = 13;

void setup() {                
  Serial.begin(9600);  
  pinMode(led, OUTPUT);     
}

void loop() {
  Serial.println("LED: HIGH");
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  Serial.println("LED: LOW");
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
