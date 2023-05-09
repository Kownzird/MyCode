#include <Arduino.h>

int KEY0 = 0;
int KEY35 = 35;

//中断处理函数
void keyChange0(){
  Serial.println("key0 is down");
}

void keyChange35(){
  Serial.println("key35 is down");
}

void setup() {
  pinMode(KEY0, INPUT_PULLUP);
  pinMode(KEY35, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(KEY0), keyChange0, CHANGE);//设置中断0的处理函数，电平变化触发
  attachInterrupt(digitalPinToInterrupt(KEY35), keyChange35, CHANGE);

  Serial.begin(115200);
}


void loop() { 
  while(1){
    delay(1000);
  }
}
