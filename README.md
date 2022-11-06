## Time Retriever for ESP32

Simple library to retrieve current real-world time & date components (day of week, minutes, hours, month etc.) for user-defined timezone.

__Note:__
* __WiFi connection is required to gathered time components__
* __Maximum resolution: *Seconds* (cannot retrieve milliseconds or smaller)__

### Step 1:
Download and extract the Zip, then plop the extracted TimeRetriever folder into your ```Arduino/libraries``` directory.

### Step 2:
Include the TimeRetriever library in your project
```C++
#include <TimeRetriever.h>
```

### Step 3:

Instantiate a TimeRetriever object
```C++
TimeRetriever tr;        
```

### Step 4:
Configure and pass your desired UTC offset (also called Zulu offset or GMT offset) in Hours as an argument to the ```begin()``` method for the timezone you're interested in.  In the code below, ```-5``` is passed as an argument which represents Eastern Standard Time (EST = UTC-5:00).  Realize that the argument passed to the ```begin()``` method is a float.  This is to accomodate unique timezones that are not integer offsets of UTC.
```C++
void setup() {

//establish WiFi connection here (see example in examples folder)

tr.begin(-5);     //automatically connects to pool.ntp.org and sets UTC offset passed as argument

}

```
### Step 5:
Call ```update()``` method to retrieve all time/date components (year, month, day of week, hours, etc.)
```C++
void loop(){
  
  //wait 1 second
  delay(1000);

  tr.update();
  ```
  After ```update()``` has been called, access your desired time/date components via the properties below: 
  ```C++
  
  //-----------------------------------------------------------------------------------------
  //                                                                                        -
  //                               ALL THE TIME/DATE PROPERTIES                             -
  //                                                                                        -
  //-----------------------------------------------------------------------------------------

  
  Serial.print("Year: ");
  Serial.println(tr.getFullYear);                        // returns int, 4 digits (e.g. 2022)

  Serial.print("Month: ");
  Serial.println(tr.getMonth);                           // returns int  (0-11, e.g. 0 = January)

  Serial.print("Julian date: ");
  Serial.println(tr.getJulian);                          // returns int  (0-365, e.g. 0 = 1st of January)
  
  Serial.print("Date: ");
  Serial.println(tr.getDate);                            // returns int  (1-31)

  Serial.print("Day of week: ");
  Serial.println(tr.getDay);                             // returns int  (0-6, 0 = Sunday)

  Serial.print("Hours: ");
  Serial.println(tr.getHours);                           // returns int  (0-23, 0 = midnight, 23 = 11 P.M.)

  Serial.print("Minutes: ");
  Serial.println(tr.getMinutes);                         // returns int  (0-59)
  
  Serial.print("Seconds: ");
  Serial.println(tr.getSeconds);                         // returns int  (0-59)
}
```
