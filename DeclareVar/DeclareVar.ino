void setup() {
  int a = 10;
  int b = 5;

  // initialize serial communication
  Serial.begin(115200);
  while (!Serial) {
    ; 
  }

  int c = a + b;
  int d = a * b;
  
  // print
  Serial.print("C= ");
  Serial.println(c);

  Serial.print("d= ");
  Serial.println(d);
}
void loop() {
  // put your main code here, to run repeatedly:
}
