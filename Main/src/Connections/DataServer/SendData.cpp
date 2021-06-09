#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include "../../Sensor/Sensor.h"

HTTPClient http;


String myHash = "1";
String datarx;


void sendData(SENSORRESULT values){
   http.begin("http://http.projects4maker.com/wetterstation/server/api/post");       //Specify request destination
   http.addHeader("Content-Type", "application/x-www-form-urlencoded");              //Specify content-type header

   String data = "hash=" + myHash + "&temperature=" + values.temperature + "&humidity=" + values.relHumidity + "&pressure=" + values.pressure;
   int httpCode = http.POST(data);                                                  //Send the request
   String payload = http.getString();                                               //Get the response payload

   Serial.println(payload);

    http.end();
}
