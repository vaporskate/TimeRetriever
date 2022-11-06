/*

  TimeRetriever.h - Library for getting current date and time components via WiFi for ESP32 & ESP8266.

  Created by Seth A. Hyde, November, 2022.

  Released into the public domain.

*/

#ifndef TimeRetriever_h
#define TimeRetriever_h
#include "Arduino.h"
#include <Time.h>

class TimeRetriever
{
  public:
    
    void begin(float zuluHourOffset); 
    void update();     
                  
    int getSeconds;               
    int getMinutes;             
    int getHours;              
    int getDay;                 
    int getDate;             
    int getMonth;    
    int getJulian;         
    int getFullYear;              

};

#endif
