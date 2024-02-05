#include <dht.h>
dht DHT;
int led1=19;
int led2=21;
#define DHT11_PIN 23
void setup()
{
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}
void loop()
  
{ 
  int chk=DHT.read11(DHT11_PIN);
  Serial.print("temperature=");
  Serial.println(DHT.temperature);
  Serial.print("humidity=");
  Serial.println(DHT.humidity);
  delay(1000);
  if(DHT.temperature>=20){
    digitalWrite(led1,HIGH);
}
else{
  digitalWrite(led1,LOW);
}
if(DHT.humidity>=20){
  digitalWrite(led2,HIGH);
}
else
{
  digitalWrite(led2,LOW);
}
}
