#include <SPI.h>
#include <WiFiNINA.h>

int led = 13;

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

}

void loop() {
  digitalWrite(led, HIGH);
  scanWiFi();
  digitalWrite(led, LOW);
  delay(15000);
}

void scanWiFi() {  
  Serial.print("Scanning...");
  byte ssid = WiFi.scanNetworks();

  Serial.print("found ");
  Serial.println(ssid);
  
  for (int i = 0; i<ssid; i++) {    
    Serial.print(">> ");
    Serial.print(WiFi.SSID(i));
    Serial.print("\tRSSI: ");
    Serial.print(WiFi.RSSI(i));
    Serial.print(" dBm");
    Serial.print("\tEncryption: ");
    Serial.println(WiFi.encryptionType(i));
  }
  Serial.println("");
  Serial.println("");
}
