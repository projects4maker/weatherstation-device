//#include <SPI.h>
#include <Wire.h>
#include "Sensor.h"
#include "Display.h"
#include "Wifi.h"
#include "Timer.h"




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
      delay(10000);

      //showMid(readBME(), false);
      
     
      SENSORRESULT result;
      result = readBME();
      showTemperature(result.temperature, true);
      showHumidity(result.relHumidity, false);
      showPressure(result.pressure, false);

      showTime(getTime(), false);
   
      
      //Serial.println("Temperatur, Luftfeuchte, Druck");
      //String res = readBME();
      //Serial.println(res);

}
