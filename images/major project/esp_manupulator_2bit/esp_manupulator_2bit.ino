#include "WiFi.h"

const char* ssid = "Kriya";
const char* password =  "krishna@";

const int dir = 13;
const int pwm = 12;

WiFiServer wifiServer(6677);
int b = 0;
int d, c = 0;
char a;
void setup() {

  Serial.begin(115200);
  pinMode(dir, OUTPUT);
  pinMode(pwm, OUTPUT);
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
          digitalWrite(dir, LOW);
          digitalWrite(pwm, HIGH);
          delayMicroseconds(50);
          digitalWrite(pwm, LOW);
          delayMicroseconds(50);
          Serial.print("A");
        }
        else if (d == 1) {
          //analogWrite(2, 75);
          digitalWrite(dir, HIGH);
          digitalWrite(pwm, LOW);
          delayMicroseconds(50);
          digitalWrite(pwm, LOW);
          delayMicroseconds(50);
          Serial.print("B");
        }
        else if (d == 2) {
          digitalWrite(dir, HIGH);
          digitalWrite(pwm, HIGH);
          delayMicroseconds(50);
          digitalWrite(pwm, LOW);
          delayMicroseconds(50);
        }
      }
//      if (c == 4) {
//        if (d == 0) {
//          digitalWrite(2, HIGH);
//          Serial.print("A");
//        }
//        else if (d == 1) {
//          //analogWrite(2, 75);
//          digitalWrite(2, LOW);
//          Serial.print("B");
//        }
//        else if (d == 2) {
//          digitalWrite(2, HIGH);
//          delayMicroseconds(50);
//          digitalWrite(2, LOW);
//          delayMicroseconds(50);
//        }
//      }
//      if (c == 3) {
//        if (d == 0) {
//          digitalWrite(2, HIGH);
//          Serial.print("A");
//        }
//        else if (d == 1) {
//          //analogWrite(2, 75);
//          digitalWrite(2, LOW);
//          Serial.print("B");
//        }
//        else if (d == 2) {
//          digitalWrite(2, HIGH);
//          delayMicroseconds(50);
//          digitalWrite(2, LOW);
//          delayMicroseconds(50);
//        }
//      }      
      delay(10);
    }

    client.stop();
    Serial.println("Client disconnected");

  }
}
