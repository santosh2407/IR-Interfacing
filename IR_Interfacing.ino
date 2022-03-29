
#include <IRremote.h>
int red=11;
int green=9;
int blue=8;
int RECV_PIN = 10;



IRrecv irrecv(RECV_PIN);



decode_results results;



void setup()
{
pinMode(red,OUTPUT);
pinMode(blue,OUTPUT);
pinMode(green,OUTPUT);



Serial.begin(9600);
irrecv.enableIRIn(); // Start the receiver
}



void loop() {
if (irrecv.decode(&results)) {
Serial.println(results.value, HEX);
irrecv.resume(); // Receive the next value

if(results.value==0xFD08F7){
digitalWrite(red,HIGH);
digitalWrite(green,LOW);
digitalWrite(blue,LOW);
}
else if(results.value==0xFD48B7){
digitalWrite(red,LOW);
digitalWrite(green,LOW);
digitalWrite(blue,HIGH);
}
else if(results.value==0xFD8877){
digitalWrite(red,LOW);
digitalWrite(green,HIGH);
digitalWrite(blue,LOW);
}
  else if(results.value==0xFD00FF){
  digitalWrite(red,1);
  digitalWrite(green,1);
  digitalWrite(blue,1);
  }  
  else if(results.value==0xFD40BF){
  digitalWrite(red,0);
  digitalWrite(green,0);  
  digitalWrite(blue,0);
  }
}
delay(50);
}
