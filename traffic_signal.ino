#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
 
int IR_Remote = 8;  //IR Sensor connected with arduino 
int RedLED = 4;
int GreenLED = 3;
int YellowLED = 2;
int led[] = {0,0,0,0};

#define code1  0xC101E57B  // Hex Code for Button 1 of IRR Remote
#define code2  0x97483BFB  // Hex Code for Button 2 of IRR Remote
#define code3  0xF0C41643  // Hex Code for Button 3 of IRR Remote
 
IRrecv irrecv(IR_Remote);
 
decode_results results;
 
void setup()
{
  irrecv.enableIRIn();  // Start the receiver
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);
}
 
void loop() {
  if (irrecv.decode(&results)) 
  {
    unsigned int value = results.value;
    switch(value) 
      {
       case code1:
         if(led[1] == 1) 
         {        
            digitalWrite(RedLED, LOW);   //led off when button is pressed
            led[1] = 0;                 
         } 
         else 
         {                                // if first led is off
             digitalWrite(RedLED, HIGH); // turn it on when the button is pressed
             led[1] = 1;                 // and set its state as on
         }
       break; 
      
       case code2:
         if(led[2] == 1) 
         {        
            digitalWrite(GreenLED, LOW);   
            led[2] = 0;                 
         } 
         else 
         {                      
             digitalWrite(GreenLED, HIGH); 
             led[2] = 1;          
         }
       break; 
       
       case code3:
         if(led[3] == 1) 
         {
            digitalWrite(YellowLED, LOW);
            led[3] = 0;
         } else 
         {
             digitalWrite(YellowLED, HIGH);
             led[3] = 1;
         }
          break;          
    }
  irrecv.resume(); // Receive the next value
  }
}
