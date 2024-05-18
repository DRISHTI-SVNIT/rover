int motor;
int motorpwm=11;
int x=1;
int i;

void setup()
{

pinMode(11,OUTPUT);
Serial.begin(9600);
}

void loop() 
{

for(int i=0;i<motorpwm-1;i=i+x)
 {
analogWrite(motorpwm,i);
Serial.println(i);
 }
for (int i= 




if(i==255)
  {
x=0;
Serial.println("PWM is maximum");
  }
 }
}
