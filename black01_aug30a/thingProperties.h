#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[] = "f7b13109-4408-40cc-a589-b4f2a775e9ba";

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

void onLED1Change();

bool lED1;

void initProperties(){

  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(lED1, READWRITE, ON_CHANGE, onLED1Change);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
