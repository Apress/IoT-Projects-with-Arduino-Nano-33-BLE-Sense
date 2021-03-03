void setup() {
  // initialize serial communication
  Serial.begin(115200);
  while (!Serial) {
    ; 
  }
}

void loop() {
  long val = random(6, 15);
  int i;

  // print
  Serial.print("val: ");
  Serial.println(val);
  
  // looping
  Serial.println("Looping: for");
  for(i=0;i<val;i++){
    if(i==5) 
      continue;

    if(i>10)
      break;
    
    Serial.print(i);
    Serial.print(" ");  
  }
  Serial.println();
  
  
  delay(3000);
}
