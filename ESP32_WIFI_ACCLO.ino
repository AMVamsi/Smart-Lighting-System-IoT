/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "7f21e8681c0a4f3d949fe438f56a8dab";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "OPPO F9";
char pass[] = "12345678";
WidgetLED up(V0);
WidgetLED right(V1);
WidgetLED down(V2);
WidgetLED left(V3);

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
   int x= analogRead(A4);
  int y = analogRead(A7);

  Serial.print("X = ");
  Serial.print(x);
  Serial.print("Y = ");
  Serial.println(y);

  if((1220<x)&&(x<1300))
   {
    up.off();
    down.off(); 
  
    
    
     Serial.println("OFF");
   }
else if(x>1600)
  {
    up.on();
    down.off(); 
    right.off();
    left.off();
    
     Serial.println("up");
  }
else if(x<1000)
  {
    up.off();
    right.off();
    left.off();
    down.on();
     Serial.println("down");
  }
else if((1220<y)&&(y<1300))
   { 
    right.off();
    left.off();
     Serial.println("OFF");
   }
else if(y>1700)
  {
    up.off();
    down.off(); 
    left.off();
    right.on();
     Serial.println("right");
  }
else if(y<1700)
  {
    up.off();
    down.off(); 
    right.off();
    left.on();
     Serial.println("left");
  }
 else
 {
    up.off();
    down.off(); 
    right.off();
    left.off();
     Serial.println("move");
 }
  Blynk.run();
delay(2000);
}
