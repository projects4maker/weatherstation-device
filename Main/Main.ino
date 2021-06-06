//#include <SPI.h>
#include <Wire.h>
#include "Sensor.h"
#include "Display.h"
#include "Wifi.h"
#include "Timer.h"
#include "SendData.h"




void setup() {
  Serial.begin(9600);          //Serial
  Wire.pins(4, 5);             //I2C
  Wire.begin();
  delay(1000);
  initDisplay();
  startWifi();
  startTimer();
}


void loop() {
  //showMid(readBME(), false);
  SENSORRESULT result;
  result = readBME();
  showTemperature(result.temperature, true);
  showHumidity(result.relHumidity, false);
  showPressure(result.pressure, false);
  showTime(getTime(), false);

  displayRefresh();

  //sendData(result);
  
  delay(10000);
  //ESP.deepSleep(30e6);
  //Serial.println("Temperatur, Luftfeuchte, Druck");
  //String res = readBME();
  //Serial.println(res);

}
