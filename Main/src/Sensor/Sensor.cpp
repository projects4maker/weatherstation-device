/************************************************************
 * Funktionen des BME280
 * returns pointer to result array
 ***********************************************************/
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "Sensor.h"



SENSORRESULT readBME(){

      Adafruit_BME280 bme; 
      
      bool status;
      status = bme.begin(0x76);  
        if (!status) {
            Serial.println("RESET");
            delay(500);
            ESP.reset();
        }

    
      SENSORRESULT result;
      result.temperature = bme.readTemperature();
      result.relHumidity = bme.readHumidity();
      result.pressure = bme.readPressure() / 100.0F;
     
       /*
       String res = String(bme.readTemperature()) + ", " + String(bme.readHumidity()) + ", " 
           + String(bme.readPressure()/100.0F); 
       Serial.println(res);   
       */
    
       return result;
}
