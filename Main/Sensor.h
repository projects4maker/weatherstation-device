/************************************************************
 * Funktionen des BME280
 * Gibt Werte in der Form
 * Temperatur (°C), rel. Luftfeuchte (%), Luftdruck (hPa)
 * zurück
 ***********************************************************/


#ifndef SENSOR_H
#define SENSOR_H

typedef struct{
    float temperature;
    int relHumidity;
    int pressure;
} SENSORRESULT;

 
SENSORRESULT readBME();


#endif
