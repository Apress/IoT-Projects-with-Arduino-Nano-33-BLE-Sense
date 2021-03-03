#include <ArduinoBLE.h>
#include <Arduino_LSM6DS3.h>

BLEService sensorService("16150f38-e7a9-4fe1-ae08-48464baf25b2");
BLEStringCharacteristic  xSensorLevel("ff99948c-18ff-4ed8-942e-512b9b24b6da", 
    BLERead | BLENotify,15);
BLEStringCharacteristic  ySensorLevel("8084aa6b-6cae-461f-9540-e1a5768de49d", 
    BLERead | BLENotify,15);
BLEStringCharacteristic  zSensorLevel("ab80cb77-fe74-40d8-9757-96f8a54c16d9", 
    BLERead | BLENotify,15);        

// last sensor data    
float oldXLevel = 0; 
float oldYLevel = 0; 
float oldZLevel = 0; 
long previousMillis = 0;  

void setup() {
  Serial.begin(115200);  
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  pinMode(LED_BUILTIN, OUTPUT); 
  
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");
    while (1);
  }

  BLE.setLocalName("Gyroscope");
  BLE.setAdvertisedService(sensorService);
  
  sensorService.addCharacteristic(xSensorLevel);
  sensorService.addCharacteristic(ySensorLevel);
  sensorService.addCharacteristic(zSensorLevel);
  BLE.addService(sensorService); 

  // initialize default data
  xSensorLevel.writeValue(String(0)); 
  ySensorLevel.writeValue(String(0)); 
  zSensorLevel.writeValue(String(0)); 

  // start advertising
  BLE.advertise();
  Serial.println("Bluetooth device active, waiting for connections...");
}

void loop() {
  // wait for a BLE central
  BLEDevice central = BLE.central();
  if (central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());
    digitalWrite(LED_BUILTIN, HIGH);

    while (central.connected()) {
      //long currentMillis = millis();
      updateGyroscopeLevel();
      delay(300);
    }

    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}

void updateGyroscopeLevel() {
  float x, y, z;

  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(x, y, z);

    if (x != oldXLevel) {
       xSensorLevel.writeValue(String(x)); 
       oldXLevel = x;
    }
    if (y != oldYLevel) {
       ySensorLevel.writeValue(String(y)); 
       oldYLevel = y;
    }
    if (z != oldZLevel) {
       zSensorLevel.writeValue(String(z)); 
       oldZLevel = z;
    }
    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);

  }
}
