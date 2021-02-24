#include "Senser.h"
#define p 5000           //กำหนดเวลาในการเก็บค่าอุณหภูมิ หรือ Delay การเปิด Relay 5000 = 5 วินาที
#define pp 1000          //แสดงค่าอุณหฒิทุกๆ 1 วิ
#define ppp 500
#define relay 22
unsigned long tt;
unsigned long ttt;

void setup() {
  Serial.begin(115200); 
  Serial2.begin(115200); 
  Serial.println("*************** Test ***********");
  Temp = &T_Body;
  pinMode(relay, OUTPUT);
}

void loop() 
{
  Senser();
  
      if(millis()- tt > pp)
     {
       tt = millis();
       Serial.println(*Temp);
       Serial1.println(*Temp);
     }


     
if((*Temp >= 35.00 && *Temp <= 37.50)&& trig == true)
{
  digitalWrite(relay, HIGH);
      if(millis()- ttt > ppp)
     {
       ttt = millis();
       Serial.println("---------  OK  ------------");
     }
}
else{
  digitalWrite(relay, LOW);
}    
}
