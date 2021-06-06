/************************************************************
 * Funktionen des BME280
 * Gibt Werte in der Form
 * Temperatur (°C), rel. Luftfeuchte (%), Luftdruck (hPa)
 * zurück
 ***********************************************************/

typedef struct{
    float temperature;
    int relHumidity;
    int pressure;
} SENSORRESULT;

 
SENSORRESULT readBME();
