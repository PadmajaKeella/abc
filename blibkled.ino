
int led1=19;

void setup() {
  pinMode(led1,OUTPUT);// put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led1,HIGH);
delay(500);
digitalWrite(led1,LOW);
delay(500);
}
