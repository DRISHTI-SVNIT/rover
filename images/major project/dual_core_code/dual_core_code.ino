
TaskHandle_t Task1;
TaskHandle_t Task2;

//ultrasonic pins
const int trigPin = 2;
const int echoPin = 4;

//define sound speed in cm/uS
#dfine SOUND_SPEED 0.034


long duration;

// LED pins
const int led1 = 13;


void setup() {
  Serial.begin(115200); 
  pinMode(led1, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
 

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

//Task1code: blinks an LED every 1000 ms
void Task1code( void * pvParameters ){
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());
  
  for(;;){
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(10);
      
      
      duration = pulseIn(echoPin, HIGH);
      delay(1000);
    
      }
  
}

//Task2code: blinks an LED every 700 ms
void Task2code( void * pvParameters ){
  Serial.print("Task2 running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    Serial.print("Distance (cm): ");
    Serial.println(duration * SOUND_SPEED/2);
    digitalWrite(led1, HIGH);
    delay(700);
    digitalWrite(led1, LOW);
    delay(700);
  }
}

void loop() {
  
}
