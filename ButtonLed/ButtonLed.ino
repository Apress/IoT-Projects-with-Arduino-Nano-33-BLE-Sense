int led = 13;
int pushButton = 7;
int state = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pushButton, INPUT);
}

void loop() {
  state = digitalRead(pushButton);
  digitalWrite(led,state);
  delay(300);
}
