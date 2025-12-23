#include <Arduino.h>
#include "connections/wifi_utils.h"
#include "connections/mqtt_utils.h"
#include "RTClib.h"

WifiUtils Wifi;
MqttUtils Mqtt;
RTC_DS3231 rtc;

void initRtc();

void setup() {
    Serial.begin(115200);
    Wifi.connect();
    initRtc();
}

void loop() {
    // if ((Wifi.isConnected() && Mqtt.isConnected() == false))
    // {
    //    Mqtt.connect();
    // }
    
    // Mqtt.loop();


    DateTime time = rtc.now();
    Serial.print("Current DateTime: ");
    Serial.print(time.hour());
    Serial.print(":");
    Serial.print(time.minute());
    Serial.print(":");
    Serial.print(time.second());
    Serial.print(" ");
    Serial.print(time.day());
    Serial.print("/");
    Serial.print(time.month());
    Serial.print("/");
    Serial.println(time.year());
    delay(1000);
}

void initRtc() {
    if (!rtc.begin()) {
        Serial.println("Couldn't find RTC");
        while (1);
    }

    // if (rtc.lostPower()) {
        // Serial.println("RTC lost power, setting the time!");
        // Set the RTC to the date & time this sketch was compiled
        // rtc.adjust(DateTime(2025, 12, 9, 21, 40, 0));
    // }
}
