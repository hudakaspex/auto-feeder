#include <Arduino.h>
#include "connections/wifi_utils.h"
#include "connections/mqtt_utils.h"

WifiUtils Wifi;
MqttUtils Mqtt; 
void connectMqtt();

void setup() {
    Serial.begin(115200);
    Wifi.connect();
    connectMqtt();
}

void loop() {
}

void connectMqtt() {
    while (Wifi.isConnected() && Mqtt.isConnected() == false)
    {
       Mqtt.connect();
    }
}