#include <WiFiUdp.h>
#include <NTPClient.h>


//Time
const long utcOffsetInSeconds = 7200;//3600;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);


void startTimer(){
    timeClient.begin(); 
}

String getTime(){
     String zeit = "";
     timeClient.update();
      
     zeit += (String) daysOfTheWeek[timeClient.getDay()] + ", ";

     int tmp = (int) timeClient.getHours();
      
     if(tmp < 10){
          zeit += "0" + (String)tmp;
     }
     else{
          zeit += (String)tmp;
     }

     zeit += ":";

     tmp = (int) timeClient.getMinutes();
     
     if(tmp < 10){
          zeit += "0" + (String)tmp;
     }
     else{
          zeit += (String)tmp;
     }

     return zeit;
}
