/*
  TimeRetriever Example 
  Library for getting current date and time components via WiFi for ESP32.

  Created by Seth Hyde, November, 2022.

  Released into the public domain.
*/

#include <TimeRetriever.h>
#include <WiFi.h>

const char* ssid       = "your SSID";                       
const char* password   = "your WiFi password"; 
 
float zuluOffset = -5;    //Units of hours, offset from Greenwich Mean Time (a.k.a. zulu time). Example: -5 is Eastern Standard Time.
TimeRetriever tr;         //Instanitate TimeRetriever            

void setup() {

  Serial.begin(115200);

  //Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println("WiFi Connected");
  Serial.println(WiFi.localIP());

  tr.begin(zuluOffset);     //Configure time and connect to NTP Service. note: WiFi connection must already be established or this step won't work
  
}

void loop() {
  //Wait 1 second
  delay(1000);


  //Upate object variables (properties) with the current time/date 
  tr.update();           
 

  //-----------------------------------------------------------------------------------------
  //                                                                                        -
  //                               ALL THE TIME COMPONENTS                                  -
  //                                                                                        -
  //-----------------------------------------------------------------------------------------

  
  Serial.print("Year: ");
  Serial.println(tr.getFullYear);                        // returns type int, 4 digits (e.g. 2022)

  Serial.print("Month: ");
  Serial.println(tr.getMonth);                           // returns type int  (0-11, e.g. 0 = January)

  Serial.print("Julian date: ");
  Serial.println(tr.getJulian);                          // returns type int  (0-365, e.g. 0 = 1st of January)
  
  Serial.print("Date: ");
  Serial.println(tr.getDate);                            // returns type int  (1-31)

  Serial.print("Day of week: ");
  Serial.println(tr.getDay);                             // returns type int  (0-6, 0 = Sunday)

  Serial.print("Hours: ");
  Serial.println(tr.getHours);                           // returns type int  (0-23, 0 = midnight, 23 = 11 P.M.)

  Serial.print("Minutes: ");
  Serial.println(tr.getMinutes);                         // returns type int  (0-59)
  
  Serial.print("Seconds: ");
  Serial.println(tr.getSeconds);                         // returns type int  (0-59)
  Serial.println();

}
