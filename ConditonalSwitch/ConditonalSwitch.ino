
long num_a;

void setup() {
   // initialize serial communication
  Serial.begin(115200);
  while (!Serial) {
    ; 
  }
}

void loop() {
  num_a = random(5);

  // print
  Serial.print("num_a: ");
  Serial.println(num_a);

  switch(num_a) {
    case 0: 
            Serial.println("num_a value is 0");
            break;
    case 1: 
            Serial.println("num_a value is 1");
            break;
    case 2: 
            Serial.println("num_a value is 2");
            break;      
    case 3: 
            Serial.println("num_a value is 3");
            break;
    case 4: 
            Serial.println("num_a value is 4");
            break;                              
  }
  
  delay(2000);
}
