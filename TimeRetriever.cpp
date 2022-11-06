/*

  TimeRetriever.cpp - Library for getting the current date and time components via WiFi for ESP32.

  Created by Seth A. Hyde, October, 2022.

  Released into the public domain.

*/
#include "Arduino.h"
#include "TimeRetriever.h"
#include <Time.h>

//Establish connection to NTP service at pool.ntp.org
void TimeRetriever::begin(float zuluHourOffset) {
        configTime(zuluHourOffset*3600, 0, "pool.ntp.org");         //function from the <Time.h> library
}

//Retrieve time components (sec/min/hour/etc.) for "right now"
void TimeRetriever::update(){
    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)){
        Serial.print("\u25B6 \u25B6 ");
        Serial.print("Unable to acquire time, ensure WiFi connected");
        Serial.println(" \u25C0 \u25C0");
    }
    else{
                                                // Possible Return Values
        getSeconds =    timeinfo.tm_sec;        // 0-59                 
        getMinutes =    timeinfo.tm_min;        // 0-59
        getHours =      timeinfo.tm_hour;       // 0-23
        getDay =        timeinfo.tm_wday;       // 0-6 (0 is Sunday)
        getDate =       timeinfo.tm_mday;       // 1-31
        getMonth =      timeinfo.tm_mon;        // 0-11 (0 is January)
        getJulian =     timeinfo.tm_yday;       // 0-365 (0 is 1 January, 365 is December 31)
        getFullYear =   timeinfo.tm_year+1900;  // 4 digit year (e.i. 2022)
    }
}




