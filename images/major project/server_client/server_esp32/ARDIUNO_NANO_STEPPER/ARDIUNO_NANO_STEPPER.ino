const int Pin1 = 5;
const int Pin2 = 6;
const int Pin3 = 7;
const int Pin4 = 8;
const int pwm1 = 20;
const int dir1 = 21;
const int pwm2 = 22;
const int dir2 = 20;
const int pwm3 = 21;
const int dir3 = 22;

void setup() {
  // put your setup code here, to run once:


}

void loop() {
  // put your main code here, to run repeatedly:
    int pin1 = digitalRead(Pin1); 
    int pin2 = digitalRead(Pin2);
    int pin3 = digitalRead(Pin3); 
    int pin4 = digitalRead(Pin4);
    if(pin1 == HIGH && pin2==LOW)
    {
      Serial.println("1");
      Serial.println(pin1);
      Serial.println(pin2);
      Serial.println(pin3);
      Serial.println(pin4);
     
    digitalWrite(dir1, pin3);
    digitalWrite(pwm1, HIGH);
    delayMicroseconds(500);
    digitalWrite(pwm1, LOW);
    delayMicroseconds(0);
    //Serial.println(steps);
    }
    if(pin1 == LOW && pin2==HIGH)
    {
      Serial.println("2");
      Serial.println(pin1);
      Serial.println(pin2);
      Serial.println(pin3);
    digitalWrite(dir2, pin3);
    digitalWrite(pwm2, HIGH);
    delayMicroseconds(500);
    digitalWrite(pwm2, LOW);
    delayMicroseconds(0);
    //Serial.println(steps);
    }
    if(pin1 == HIGH && pin2==LOW)
    {
      Serial.println("3");
      Serial.println(pin1);
      Serial.println(pin2);
      Serial.println(pin3);
    digitalWrite(dir3, pin3);
    digitalWrite(pwm3, HIGH);
    delayMicroseconds(500);
    digitalWrite(pwm3, LOW);
    delayMicroseconds(0);
    //Serial.println(steps);
    }
    
  

}
