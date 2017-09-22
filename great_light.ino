//LOW -for on relay for normaly open
//HIGH-for off relay for normaly close



#include <SoftwareSerial.h>
#include <EEPROM.h>
SoftwareSerial BTSerial(8, 9); // RX | TX

int r1=2 ;
int r2=3;
int ad1=1;
int ad2=2;
char data;
byte i;
byte j;
int statusled=13;
int address=0;

void setup()
{

  Serial.begin(9600);
  BTSerial.begin(9600);  // HC-05 default speed in AT command more
  Serial.println("Welcome to bluetooth light");
  
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(statusled,OUTPUT);
  
  i=EEPROM.read(ad1);
  j=EEPROM.read(ad2);

  Serial.println("*****Device 1******");
  Serial.print("ad1: ");
  Serial.println(ad1);
  Serial.print("i:");
  Serial.println(i);
  Serial.println("********Device 2*****");


  if(i==1){
    digitalWrite(r1,LOW);
//    blu_connect("Light is ON");
          }
  else if(i==2){
    digitalWrite(r1,HIGH);
//    blu_connect("Light is OFF");
          }
  Serial.print("ad2: ");
  Serial.println(ad2);
  Serial.print("j: ");
  Serial.println(j);
  Serial.println("******************");

          
  if(j==3){
    digitalWrite(r2,LOW);
  //  blu_connect("Light is ON");
          }
  else if(j==4){
    digitalWrite(r2,HIGH);
//    blu_connect("Light is OFF");
          }

}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  while (BTSerial.available()){
    
    digitalWrite(statusled,HIGH);
    data=BTSerial.read();
    Serial.print("data: ");
    Serial.println(data);
           }

  if(data=='1'){
      digitalWrite(r1,LOW);
      EEPROM.write(ad1, 1);
    //   blu_connect("Light is ON1");
    //   Serial.println("ON1");
  
      }
  else if(data=='2'){
  
      digitalWrite(r1,HIGH);
      EEPROM.write(ad1, 2);
  //    blu_connect("Light is OFF1");
    //  Serial.println("OFF1");
      } 
      
  else if(data=='3'){
      digitalWrite(r1,LOW);
      EEPROM.write(ad2, 3);
   //   blu_connect("Light is ON2");
   //   Serial.println("ON1");
      }
      
  else if(data=='4'){
    digitalWrite(r1,HIGH);
    EEPROM.write(ad2, 4);
  //  blu_connect("Light is OFF2");
   // Serial.println("OFF2");
    }
    
    }


////////////////////////////////////////////////////////////
//   void blu_connect(char* lamp_stat){
//  while(Serial.available()){
//  BTSerial.write(lamp_stat);
//  }
//   }
