#include <ESP8266WiFi.h>
#include <Adafruit_SSD1306.h>
#include "Display.h"
#include "Images.h"
#include "PWs.h"

extern Adafruit_SSD1306 display;

WiFiClient client;



void startWifi(){
    client.stop();
    Serial.printf("Connecting to %s ", ssid);
    
    display.clearDisplay();
    showImage(55, 18, 25, 25, img_WifiOff);
    showText(13, 55, "Try to connect");
    display.display();
    
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
