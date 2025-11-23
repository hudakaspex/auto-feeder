#include <PubSubClient.h>
#include "mqtt_utils.h"
#include <WiFiClientSecure.h>

WiFiClientSecure wifiClient;
PubSubClient mqttClient(wifiClient);


const char* mqtt_server = "20fc0b10deb8417e8a1fcef5835679c3.s1.eu.hivemq.cloud"; // your HiveMQ host
const int mqtt_port = 8883; // your HiveMQ port
const char* mqtt_user = "mifta"; // your HiveMQ username
const char* mqtt_password = "0S089j9l"; // your HiveMQ password
const char* mqtt_topic = "servo/control"; // your MQTT topic


void MqttUtils::connect(){
  Serial.println("Connecting to MQTT broker...");
  mqttClient.setServer(mqtt_server, mqtt_port);
  wifiClient.setInsecure(); // Disable certificate verification (not recommended for production)
  while (!mqttClient.connected())
  {
    if (mqttClient.connect("esp32", mqtt_user, mqtt_password))
    {
      Serial.println("Connected to MQTT broker");
      MqttUtils::mqttSubscribe();
    }
    else {
      Serial.println("Failed to connect to MQTT broker, retrying in 5 seconds...");
      delay(5000);
    }
  }
}

boolean MqttUtils::isConnected(){
  return mqttClient.connected();
}

void MqttUtils::mqttSubscribe(){
  mqttClient.setCallback(MqttUtils::mqttCallBack);
  mqttClient.subscribe(mqtt_topic);
}

// This function runs when a message is received
void MqttUtils::mqttCallBack(char *topic, uint8_t *payload, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.println(topic);
  const String message = MqttUtils::convertByteToString(payload, length);
  Serial.println(message);
}

String MqttUtils::convertByteToString(uint8_t* payload, unsigned int length) {
  // Convert payload to string
  String message = "";
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  return message;
}
