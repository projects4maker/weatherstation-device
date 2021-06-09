/********************************************************************************
 * Funktionen des Displays
 * Nach der Initialisierung können verschiedene Parameter angezeigt werden
********************************************************************************/

#ifndef DISPLAY_H
#define DISPLAY_H

void initDisplay();

void showTemperature(float, boolean);
void showHumidity(int, boolean);
void showPressure(int, boolean);

void showTime(String, boolean);

void showText(byte, byte, String);

void showImage(byte, byte, byte, byte, const uint8_t[]);

void displayRefresh();

#endif
