const int steppin=5;
const int dirpin=2;
const int enpin=8;
void setup() {
  pinMode(steppin,OUTPUT);
  pinMode(dirpin,OUTPUT);
  pinMode(enpin,OUTPUT);// put your setup code here, to run once:

}

void loop() {
  digitalWrite(dirpin,HIGH);
  
    digitalWrite(steppin,HIGH);
    delayMicroseconds(500);
    digitalWrite(steppin,LOW);
    delayMicroseconds(500);
    
    delay(0); 
  // put your main code here, to run repeatedly:

}
