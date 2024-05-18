 #include "WiFi.h"

const char* ssid = "Kriya";
const char* password =  "krishna@";

WiFiServer wifiServer(6677);
const int PIN1 = 19;
const int PIN2 = 18;
const int PIN3 = 5;

const int dir1 = 4;
const int pwm1 = 2;
const int dir2 = 15;
const int pwm2 = 24;
const int dir3 = 26;
const int pwm3 = 27;

int PWM;
int ang = 180;

void setup() {

  Serial.begin(115200);

  delay(1000);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());

  wifiServer.begin();
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pinMode(PIN3, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(pwm3, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {

    
  WiFiClient client = wifiServer.available();

  if (client) {

    while (client.connected()) {
      
      

      while(client.available()>0 ) {
        int ans =0;

          char a = client.read();
          Serial.println(a);
          //int b;
          //int d=0;
          //while(a!='#')
          //{
            //b=a-'0';
            //d=d*10+b;
            //a = client.read();
            
          //}
          //if(d!=-23){
            //Serial.println(d);
                //int x = d/1000;
                //int val = d%1000;
                //int dir = val/100;
                //int pwm = val%100;
                
                //DIR=0 FORWARD; DIR=1 BACKWARD
                
//                if(x == 1 )
//                {
//                  PWM = map(pwm,0,99,0,255);
//                  digitalWrite(dir1, dir);
//                  digitalWrite(pwm1, PWM);
//                  Serial.println("motor 1 for");
//                }
//                if(x == 2 )
//                {PWM = map(pwm,0,99,0,255);
//                  digitalWrite(dir2, dir);
//                  digitalWrite(pwm2, PWM);
//                  Serial.println("motor 1 back");
//                }
//                
//                else if(x == 3 )
//                {
//                  PWM = map(pwm,0,99,0,255);
//                  digitalWrite(dir3, dir);
//                  digitalWrite(pwm3, PWM);
//                  Serial.println("motor 2 for");
//                }
//             
//                else if(x == 4)
//                {
//                  digitalWrite(PIN1, 1);
//                  digitalWrite(PIN2, 0);
//                  digitalWrite(PIN3, dir);
//                  
//                  Serial.println("st1");
//                }
//                else if(x == 5)
//                {
//                  digitalWrite(PIN1, 0);
//                  digitalWrite(PIN2, 1);
//                  digitalWrite(PIN3, dir);
//                  Serial.println("st2");
//                }
//                else if(x == 6)
//                {
//                  digitalWrite(PIN1, 1);
//                  digitalWrite(PIN2, 1);
//                  digitalWrite(PIN3, dir);
//                  Serial.println("st3");
//                }
//          }
          delay(100);
          
      }
      

      delay(10);
    }

    client.stop();
    Serial.println("Client disconnected");

  }
}
