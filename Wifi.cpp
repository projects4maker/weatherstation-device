#include <ESP8266WiFi.h>
#include "PWs.h"


WiFiClient client;


void startWifi(){
    client.stop();
    Serial.printf("Connecting to %s ", ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
    Serial.println(" connected");
    Serial.println("IP-Adress: ");
    Serial.println(WiFi.localIP());
    Serial.println("MAC-Address:");
    Serial.println(WiFi.macAddress());
}


void stopWiFi(){
    client.stop();  
}
