
// Fill-in information from your Blynk Template here

#define BLYNK_TEMPLATE_ID "TMPLSGAQ-Dov"
#define BLYNK_DEVICE_NAME "SmartBinAI"
#define BLYNK_FIRMWARE_VERSION "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
#include<Servo.h>
#define ph_sensor A0//a0
Servo servoMain; // Define our Servo

BlynkTimer timer1;
String message1,message2;
const int trigpin2 = 12;//d5
const int echopin2 = 14;//d6
long dur;
int dist;
float ph_value, sensor_value = 0,p;
int trigpin =5;//d1
int pos = 0;
int echopin =4;//d2
int distance;
float duration;
float cm;
void datas(){
  Blynk.virtualWrite(V0,dist);
  Blynk.virtualWrite(V1,sensor_value);
  Blynk.virtualWrite(V2,message1);
  Blynk.virtualWrite(V3,message2);
}
void setup()
{
  //Serial.begin(115200);
  //delay(100);

  BlynkEdgent.begin();
  Serial.begin(9600);
  delay(100);

  BlynkEdgent.begin();
  
  servoMain.attach(13); // d7
  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  servoMain.write(0);
  timer1.setInterval(2000L,datas);
}

void loop() {
  BlynkEdgent.run();
   ph_value = analogRead(ph_sensor);
    
  sensor_value = (ph_value/24.57);

  Serial.print("ph_value=");
  Serial.println(sensor_value);
  delay(1000);

  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  cm = (duration / 58.82);
  distance = cm;
  if (distance < 10)
  {
    servoMain.write(180); // Turn Servo back to center position (90 degrees)
    delay(1000);
  }
  else {
    servoMain.write(0);
    delay(50);
  }
  digitalWrite(trigpin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin2, HIGH);
  delayMicroseconds(10);


  dur = pulseIn(echopin2, HIGH);
  dist = 0.0343 * (dur / 2);
  Serial.print("Distance:");
  Serial.println(dist);
  timer1.run();
  p=sensor_value;
    if(dist>15){
        message1="The bin is empty no need to pick the bin";
    }
    else if((dist>=10)&&(dist<=15)){
        message1="The bin is almost filled, should be picked up soon";
        if(p<3) message2="Recommendation: To be treated with strong base to neutralize";
        else if(p<6.5) message2="Recommendation: To be treated with mild base to neutralize";
        else if(p<7.5) message2="Recommendation: Can be directly disposed";
        else if(p<10.5) message2="Recommendation: To be treated with mild acid to neutralize";
        else message2="Recommendation: To be treated with a strong acid in order to neutralize";
    }
    else if(dist<10){ message1="The bin is completely filled hence clear the bin";
        if(p<3) message2="Recommendation: To be treated with strong base to neutralize";
        else if(p<6.5) message2="Recommendation: To be treated with mild base to neutralize";
        else if(p<7.5) message2="Recommendation: Can be directly disposed";
        else if(p<10.5) message2="Recommendation: To be treated with mild acid to neutralize";
        else message2="Recommendation: To be treated with a stroong acid in order to neutralize";
    }
 
}
