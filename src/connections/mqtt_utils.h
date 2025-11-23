#ifndef MQTT_UTILS_H
#define MQTT_UTILS_H

class MqttUtils {
public:
    void connect();
    void mqttSubscribe();
    boolean isConnected();
    static void mqttCallBack(char *topic, uint8_t *payload, unsigned int length);
    static String convertByteToString(uint8_t* payload, unsigned int length);
    void loop();
};

#endif