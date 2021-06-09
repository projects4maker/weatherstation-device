/*******************************
 * OLED Display with Address 0x3C
 *******************************/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/FreeSerif24pt7b.h>
#include "Images.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



void initDisplay(){
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    display.setFont(&FreeSerif9pt7b);
    display.setTextSize(1);             
    display.setTextColor(WHITE);
    
    // Clear the buffer
    display.clearDisplay();
    display.display();
}


void showTemperature(float temp, boolean clearDisp=false){
    
    if(clearDisp){
        display.clearDisplay();
    }
    
    display.setCursor(35, 28);      
    display.print(temp); display.print("  "); display.drawCircle(83, 18, 2, WHITE); display.println("C");
}



void showHumidity(int hum, boolean clearDisp=false){
    
    if(clearDisp){
        display.clearDisplay();
    }
    
    display.setCursor(35,45);      
    display.print(hum); display.print(" %");  
}

void showPressure(int pressure, boolean clearDisp=false){
    
    if(clearDisp){
        display.clearDisplay();
    }
    
    display.setCursor(35,63);      
    display.print(pressure); display.print(" hPa");  
}


void showTime(String currentTime, boolean clearDisp=false){
    
    if(clearDisp){
        display.clearDisplay();
    }
    
    display.setCursor(18,12);      
    display.print(currentTime);
}


void showText(byte x, byte y, String txt){
    display.setCursor(x, y);      
    display.print(txt);
}


void showImage(byte x, byte y, byte lx, byte ly, const uint8_t img[]){
    //position, width, height, rotation
    display.drawBitmap(x, y, img, lx, ly, 1);
}


void displayRefresh(){
    showImage(113, 0, 15, 15, img_WifiOn);
    showImage(113, 20, 15, 15, img_Sun);
    showImage(113, 40, 15, 15, img_Rain);
    display.display();  
}
