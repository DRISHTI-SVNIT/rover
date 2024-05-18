#include "WiFi.h"

const char* ssid = "t";
const char* password =  "123456788";
//c is for motor id ;from c=3  stepper ; from c = 4 to c = 8 for dc motor
//c=3
const int st1dir = 13;
const int st1pwm = 12;
//c=4
const int dc4dir = 1;
const int dc4pwm = 27;
//c=5
const int dc5dir = 26;
const int dc5pwm = 28;
//c=6
const int dc1dir = 18;
const int dc1pwm = 19;
//c=7
const int dc2dir = 4;
const int dc2pwm = 2;
//c=8
const int dc3dir = 15;
const int dc3pwm = 5;

WiFiServer wifiServer(6677);
int b = 0;
int d, c = 0;
char a;
void setup() {

  Serial.begin(115200);
  pinMode(st1dir, OUTPUT);
  pinMode(st1pwm, OUTPUT);
  pinMode(dc4dir, OUTPUT);
  pinMode(dc4pwm, OUTPUT);
  pinMode(dc5dir, OUTPUT);
  pinMode(dc5pwm, OUTPUT);
  pinMode(dc1dir, OUTPUT);
  pinMode(dc1pwm, OUTPUT);
  pinMode(dc2dir, OUTPUT);
  pinMode(dc2pwm, OUTPUT);
  pinMode(dc3dir, OUTPUT);
  pinMode(dc3pwm, OUTPUT);
  delay(1000);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());

  wifiServer.begin();
}

void loop() {

  WiFiClient client = wifiServer.available();

  if (client) {

    while (client.connected()) {

      while (client.available() > 0) {
        a = client.read();
        b = a - '0';
        if (b > 2 && b < 10)
        {
          c = b;
          Serial.print("X = ");
          Serial.println(b);
        }
        if (b < 3 && b > -1) {
          d = b;
          Serial.print("Y = ");
          Serial.println(d);
        }
      }
      Serial.println(c);
      if (c == 3) {
        if (d == 0) {
          digitalWrite(st1dir,LOW);
  
          digitalWrite(st1pwm,HIGH);
          delayMicroseconds(500);
          digitalWrite(st1pwm,LOW);
          delayMicroseconds(500);
          
          Serial.print("A");
        }
        else if (d == 1) {
          //analogWrite(2, 75);
          digitalWrite(st1dir,HIGH);
  
          digitalWrite(st1pwm,LOW);
          delayMicroseconds(500);
          digitalWrite(st1pwm,LOW);
          delayMicroseconds(500);
          Serial.print("B");
        }
        else if (d == 2) {
          digitalWrite(st1dir,HIGH);
  
          digitalWrite(st1pwm,HIGH);
          delayMicroseconds(500);
          digitalWrite(st1pwm,LOW);
          delayMicroseconds(500);
          Serial.print("B");
          
        }
      }

      if (c == 4) {
        if (d == 0) {
          digitalWrite(dc1dir,LOW);
  
          digitalWrite(dc1pwm,HIGH);
          delayMicroseconds(500);
          digitalWrite(dc1pwm,LOW);
          delayMicroseconds(500);
          
          Serial.print("A");
        }
        else if (d == 1) {
          //analogWrite(2, 75);
          digitalWrite(dc1dir,HIGH);
  
          digitalWrite(dc1pwm,LOW);
          delayMicroseconds(500);
          digitalWrite(dc1pwm,LOW);
          delayMicroseconds(500);
          Serial.print("B");
        }
        else if (d == 2) {
          digitalWrite(dc1dir,HIGH);
  
          digitalWrite(dc1pwm,HIGH);
          delayMicroseconds(500);
          digitalWrite(dc1pwm,LOW);
          delayMicroseconds(500);
          Serial.print("B");
          
        }
      }

      if (c == 5) {
        if (d == 0) {
          digitalWrite(dc2dir,LOW);
  
          digitalWrite(dc2pwm,HIGH);
          delayMicroseconds(500);
          digitalWrite(dc2pwm,LOW);
          delayMicroseconds(500);
          
          Serial.print("A");
        }
        else if (d == 1) {
          //analogWrite(2, 75);
          digitalWrite(dc2dir,HIGH);
  
          digitalWrite(dc2pwm,LOW);
          delayMicroseconds(500);
          digitalWrite(dc2pwm,LOW);
          delayMicroseconds(500);
          Serial.print("B");
        }
        else if (d == 2) {
          digitalWrite(dc2dir,HIGH);
  
          digitalWrite(dc2pwm,HIGH);
          delayMicroseconds(500);
          digitalWrite(dc2pwm,LOW);
          delayMicroseconds(500);
          Serial.print("B");
          
        }
      }

      if (c == 6) {
        if (d == 0) {
          digitalWrite(dc3dir,LOW);
  
          digitalWrite(dc3pwm,HIGH);
          delayMicroseconds(500);
          digitalWrite(dc3pwm,LOW);
          delayMicroseconds(500);
          
          Serial.print("A");
        }
        else if (d == 1) {
          //analogWrite(2, 75);
          digitalWrite(dc3dir,HIGH);
  
          digitalWrite(dc3pwm,LOW);
          delayMicroseconds(500);
          digitalWrite(dc3pwm,LOW);
          delayMicroseconds(500);
          Serial.print("B");
        }
        else if (d == 2) {
          digitalWrite(dc3dir,HIGH);
  
          digitalWrite(dc3pwm,HIGH);
          delayMicroseconds(500);
          digitalWrite(dc3pwm,LOW);
          delayMicroseconds(500);
          Serial.print("B");
          
        }
      }

      if (c == 7) {
        if (d == 0) {
          digitalWrite(dc4dir,LOW);
  
          digitalWrite(dc4pwm,HIGH);
          delayMicroseconds(500);
          digitalWrite(dc4pwm,LOW);
          delayMicroseconds(500);
          
          Serial.print("A");
        }
        else if (d == 1) {
          //analogWrite(2, 75);
          digitalWrite(dc4dir,HIGH);
  
          digitalWrite(dc4pwm,LOW);
          delayMicroseconds(500);
          digitalWrite(dc4pwm,LOW);
          delayMicroseconds(500);
          Serial.print("B");
        }
        else if (d == 2) {
          digitalWrite(dc4dir,HIGH);
  
          digitalWrite(dc4pwm,HIGH);
          delayMicroseconds(500);
          digitalWrite(dc4pwm,LOW);
          delayMicroseconds(500);
          Serial.print("B");
          
        }
      }

      if (c == 8) {
        if (d == 0) {
          digitalWrite(dc5dir,LOW);
  
          digitalWrite(dc5pwm,HIGH);
          delayMicroseconds(500);
          digitalWrite(dc5pwm,LOW);
          delayMicroseconds(500);
          
          Serial.print("A");
        }
        else if (d == 1) {
          //analogWrite(2, 75);
          digitalWrite(dc5dir,HIGH);
  
          digitalWrite(dc5pwm,LOW);
          delayMicroseconds(500);
          digitalWrite(dc5pwm,LOW);
          delayMicroseconds(500);
          Serial.print("B");
        }
        else if (d == 2) {
          digitalWrite(dc4dir,HIGH);
  
          digitalWrite(dc5pwm,HIGH);
          delayMicroseconds(500);
          digitalWrite(dc5pwm,LOW);
          delayMicroseconds(500);
          Serial.print("B");
          
        }
      }
      delay(10);
    }

    client.stop();
    Serial.println("Client disconnected");

  }
}
