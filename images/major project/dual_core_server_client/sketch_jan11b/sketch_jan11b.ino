
 #include "WiFi.h"

const char* ssid = "Kriya";
const char* password =  "krishna@";

WiFiServer wifiServer(6677);
TaskHandle_t Task1;
TaskHandle_t Task2;

const int stepPin = 9;
const int dirPin = 8;
const int enPin = 7;
int ang = 180;
int val;
int dir;



void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);
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

 

  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
  delay(500); 

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    Task2code,   /* Task function. */
                    "Task2",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task2,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */
    delay(500); 
}


void Task1code( void * pvParameters ){
  WiFiClient client = wifiServer.available();

  if (client) {
      while (client.connected()) {
      while(client.available()>0 ) {
      int ans =0;

          char a = client.read();
          int b;
          int d=0;
          while(a!='#')
          {
            b=a-'0';
            d=d*10+b;
            a = client.read();
            
          }
          if(d!=-23){
            //Serial.println(d);
                int x = d/10000;
                int y = d%10000;
                
                if(x == 1)
                {
//                  Serial.println("motor 1");
//                  Serial.println(y);
                }
                dir = y/100;
                val = y%100;
                Serial.println("dir");
                Serial.println(dir);
                Serial.println("val");
                Serial.println(val);

          }
          delay(100);
                
  
    
      }
            delay(10);
  
  }
  client.stop();
  Serial.println("Client disconnected");
}
}


void Task2code( void * pvParameters ){
    int VAL = map(val , 0 , 99 , 0 , 255);
    int steps = (ang * 400.0) / 360.0;
    digitalWrite(dirPin, dir); // Enables the motor to move in a particular direction
    digitalWrite(stepPin,VAL);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(0);
  
  }

void loop() {
  // put your main code here, to run repeatedly:

}
