#include <WiFiManager.h>

WiFiManager wm;

int add(int a, int b) {
    return a + b;
}

// void setupWifi(){
//   wm.WiFiManagerInit();

//   if(!wm.autoConnect("ESP32-Setup", "12345678")) {
//     delay(3000);
//     Serial.println("Failed to connect and hit timeout");
//     ESP.restart();
//   }
//   else {
//     Serial.println("Connected to WiFi!");
//   }
//     Serial.println(WiFi.localIP());
// }
