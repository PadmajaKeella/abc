int led1=19;
int led2=21;
void setup() {
  pinMode(led1,OUTPUT);// put your setup code here, to run once:
  pinMode(led2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led1,HIGH);
delay(500);
digitalWrite(led1,LOW);
delay(500);
digitalWrite(led2,HIGH);
delay(500);
digitalWrite(led2,LOW);
delay(500);
}
