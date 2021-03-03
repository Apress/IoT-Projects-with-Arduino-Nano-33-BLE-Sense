int redPin = 12;
int greenPin = 11;
int bluePin = 10;


void setup()
{
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
  setColor(255, 0, 0);  // red
  Serial.println("red");
  delay(1000);
  setColor(0, 255, 0);  // green
  Serial.println("green");
  delay(1000);
  setColor(0, 0, 255);  // blue
  Serial.println("blue");
  delay(1000);
  setColor(255, 255, 0);  // yellow
  Serial.println("yellow");
  delay(1000);
  setColor(80, 0, 80);  // purple
  Serial.println("purple");
  delay(1000);
  setColor(0, 255, 255);  // aqua
  Serial.println("aqua");
  delay(1000);
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
