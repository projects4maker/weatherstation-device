#include <WiFiUdp.h>
#include <NTPClient.h>


//Time
//Germany => UTC + 1.00 => Offset = 3600
const long utcOffsetInSeconds = 3600;
char daysOfTheWeek[7][12] = {"Sun.", "Mon.", "Tue.", "Wed.", "Thu.", "Fri.", "Sat."};
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);


void startTimer(){
    timeClient.begin(); 
}

String getTime(){
     String zeit = "";
     timeClient.update();
      
     zeit += (String) daysOfTheWeek[timeClient.getDay()] + " ";

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
