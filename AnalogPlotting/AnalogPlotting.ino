void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; 
  }
}

void loop() {
  int val = analogRead(A0);  
  Serial.println(val);
  delay(300);
}
