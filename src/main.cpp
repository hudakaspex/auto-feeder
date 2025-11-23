#include <Arduino.h>
#include "connections/wifi_utils.h"
#include "connections/mqtt_utils.h"

WifiUtils Wifi;
MqttUtils Mqtt; 

void setup() {
    Serial.begin(115200);
    Wifi.connect();
}

void loop() {
    if ((Wifi.isConnected() && Mqtt.isConnected() == false))
    {
       Mqtt.connect();
    }
    
    Mqtt.loop();
}
