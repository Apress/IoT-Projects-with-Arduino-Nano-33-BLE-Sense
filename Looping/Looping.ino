void setup() {
  // initialize serial communication
  Serial.begin(115200);
  while (!Serial) {
    ; 
  }
}

void loop() {
  long val = random(15);
  int i;

  // print
  Serial.print("val: ");
  Serial.println(val);
  
  // looping
  Serial.println("Looping: for");
  for(i=0;i<val;i++){
    Serial.print(i);
    Serial.print(" ");  
  }
  Serial.println();
  
  Serial.println("Looping: while");
  int start = 0;
  while(start < val) {
    Serial.print(start);
    Serial.print(" ");  

    start++;
  }
  Serial.println();

  Serial.println("Looping: do..while");
  start = 0;
  do {
    Serial.print(start);
    Serial.print(" ");  

    start++;
  }while(start < val);
  Serial.println();
  
  delay(3000);
}
