
long num_a;
long num_b;

void setup() {
   // initialize serial communication
  Serial.begin(115200);
  while (!Serial) {
    ; 
  }
}

void loop() {
  num_a = random(100);
  num_b = random(100);

  // print
  Serial.print("num_a: ");
  Serial.print(num_a);
  Serial.print(", num_b: ");
  Serial.println(num_b);
    
  if(num_a > num_b) {
     Serial.println("num_a > num_b");
  }else {
    Serial.println("num_a <= num_b");
  }

  delay(2000);
}
