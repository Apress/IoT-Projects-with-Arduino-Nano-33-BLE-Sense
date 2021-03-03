#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[] = "12e6a0e8-fd46-498a-aef6-2e1c17e8757e";

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)


float xDegree;
float yDegree;
float zDegree;

void initProperties(){

  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(xDegree, READ, ON_CHANGE, NULL, 0.05);
  ArduinoCloud.addProperty(yDegree, READ, ON_CHANGE, NULL, 0.05);
  ArduinoCloud.addProperty(zDegree, READ, ON_CHANGE, NULL, 0.05);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
