/*******************************
 * OLED Display with Address 0x3C
 *******************************/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/FreeSerif24pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



void initDisplay(){
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 
    // Clear the buffer
    display.clearDisplay();
/*
    for(int i = 0; i < 127; i++){
       display.drawLine(i, 0, i, 127, WHITE); 
       display.display(); 
       display.clearDisplay(); 
    }
    
    for(int i = 0; i < 63; i++){
       display.drawLine(0, i, 127, i, WHITE); 
       display.display();
       display.clearDisplay();  
    }
*/    
    display.clearDisplay();
    display.display();
}


void showTemperature(float temp, boolean clearDisp=false){
    
    if(clearDisp){
        display.clearDisplay();
    }
    
    display.setFont(&FreeSerif9pt7b);
    display.setTextSize(1);             
    display.setTextColor(WHITE);
    display.setCursor(35, 28);      
    display.print(temp); display.print("  "); display.drawCircle(83, 18, 2, WHITE); display.println("C");
    display.display();
}



void showHumidity(int hum, boolean clearDisp=false){
    
    if(clearDisp){
        display.clearDisplay();
    }
    
    display.setFont(&FreeSerif9pt7b);
    display.setTextSize(1);             
    display.setTextColor(WHITE);
    display.setCursor(35,45);      
    display.print(hum); display.print(" %");  
    display.display();
}

void showPressure(int pressure, boolean clearDisp=false){
    
    if(clearDisp){
        display.clearDisplay();
    }
    
    display.setFont(&FreeSerif9pt7b);
    display.setTextSize(1);             
    display.setTextColor(WHITE);
    display.setCursor(35,63);      
    display.print(pressure); display.print(" hPa");  
    display.display();
}


void showTime(String currentTime, boolean clearDisp=false){
    
    if(clearDisp){
        display.clearDisplay();
    }
    
    display.setFont(&FreeSerif9pt7b);
    display.setTextSize(1);             
    display.setTextColor(WHITE);
    display.setCursor(10,11);      
    display.print(currentTime);
    display.display();
}
