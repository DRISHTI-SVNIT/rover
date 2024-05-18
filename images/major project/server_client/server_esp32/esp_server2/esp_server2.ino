#include "WiFi.h"

const char* ssid = "Kriya";
const char* password =  "krishna@";

WiFiServer wifiServer(6677);

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
}

void loop() {

  WiFiClient client = wifiServer.available();

  if (client) {

    while (client.connected()) {

      while (client.available() > 0) {
        char b = client.read();
        int a = b - '0';
        Serial.println(a);
        Serial.println(b);
        Serial.println("");
      }

      delay(10);
    }

    client.stop();
    Serial.println("Client disconnected");

  }
}
