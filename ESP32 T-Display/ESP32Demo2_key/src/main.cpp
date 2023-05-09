#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //初识化串口波特率

  pinMode(0, INPUT_PULLUP);
  Serial.write("GPIO0 INIT DONE\n");
  pinMode(35, INPUT_PULLUP);
  Serial.write("GPIO35 INIT DONE\n");
}

void loop() { 
  if(!digitalRead(0)){
    delay(10);
    if(!digitalRead(0)){
      Serial.write("KEY0 DOWN\n");
    }
    
  }

  if(!digitalRead(35)){
    delay(10);
    if(!digitalRead(35)){
      Serial.write("KEY35 DOWN\n");
    }
  }

  delay(200);
}
