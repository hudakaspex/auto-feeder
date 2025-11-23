#include <PubSubClient.h>

PubSubClient mqttClient;

const char* mqtt_server = "20fc0b10deb8417e8a1fcef5835679c3.s1.eu.hivemq.cloud"; // your HiveMQ host
const int mqtt_port = 8883; // your HiveMQ port
const char* mqtt_user = "mifta"; // your HiveMQ username
const char* mqtt_password = "0S089j9l"; // your HiveMQ password

void setupWifi();
void setupMqtt();
void subscribeMqttTopics();
void mqttCallBack(char* topic, uint8_t* payload, unsigned int length);
String convertByteToString(uint8_t* payload, unsigned int length);



void setupMqtt(){
  mqttClient.setServer(mqtt_server, mqtt_port);
  while (!mqttClient.connected())
  {
    if (mqttClient.connect("esp32", mqtt_user, mqtt_password))
    {
      Serial.println("Connected to MQTT broker");
    }
    else {
      Serial.println("Failed to connect to MQTT broker, retrying in 5 seconds...");
      delay(5000);
    }
  }
  
  // Your MQTT setup code here
  subscribeMqttTopics();
}

void subscribeMqttTopics(){
  mqttClient.subscribe("servo/control");
  mqttClient.setCallback([](char* topic, uint8_t* payload, unsigned int length){
    mqttCallBack(topic, payload, length);
  });
}


// This function runs when a message is received
void mqttCallBack(char *topic, uint8_t *payload, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.println(topic);
  const String message = convertByteToString(payload, length);
  Serial.println(message);
}

String convertByteToString(uint8_t* payload, unsigned int length) {
  // Convert payload to string
  String message = "";
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  return message;
}
