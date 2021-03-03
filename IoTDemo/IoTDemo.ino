#include <SPI.h>
#include <WiFiNINA.h>

int led1 = 6;
int led2 = 4;
int led3 = 3;

const char* ssid = "TECHNICOLOR";
const char* password = "212142984";

int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  // prepare GPIO5
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  digitalWrite(led1, 0);
  digitalWrite(led2, 0);
  digitalWrite(led3, 0);
  
  // Connect to WiFi network 
 while (status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);    
    status = WiFi.begin(ssid, password);
  
    // wait 10 seconds for connection:
    delay(10000);
  } 
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  char ips[24];
  IPAddress ip = WiFi.localIP();
  sprintf(ips, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);    
  Serial.println(ips);
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  // Match the request
  int val1 = 0;
  int val2 = 0;
  int val3 = 0;
  int ledreq = 0;
  if (req.indexOf("/gpio1/0") != -1) {
    val1 = 0;
    ledreq = 1;
  }
  else if (req.indexOf("/gpio1/1") != -1) {
    val1 = 1;
    ledreq = 1;
  }
  else if (req.indexOf("/gpio2/0") != -1) {
    val2 = 0;
    ledreq = 2;
  }
  else if (req.indexOf("/gpio2/1") != -1) {
    val2 = 1;
    req = 2;
  }
  else if (req.indexOf("/gpio3/0") != -1) {
    val3 = 0; 
    ledreq = 3;
  }
  else if (req.indexOf("/gpio3/1") != -1) {
    val3 = 1;
    ledreq = 3;
  }
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }

  // Set GPIO2 according to the request
  digitalWrite(led1, val1);
  digitalWrite(led2, val2);
  digitalWrite(led3, val3);
  
  client.flush();

  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n";
  if(ledreq==1) {
    s += "LED1 is ";
    s += (val1)? "ON": "OFF";
  }else if(ledreq==2) {
    s += "LED2 is ";
    s += (val2)? "ON": "OFF";
  }else if(ledreq==3) {
    s += "LED3 is ";
    s += (val3)? "ON": "OFF";
  }  
  s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  client.stop();
  Serial.println("Client disonnected");
 
}
