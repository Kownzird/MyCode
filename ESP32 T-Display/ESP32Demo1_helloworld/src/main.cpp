#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //初识化串口波特率
  Serial.println("Hello world");
  
  pinMode(4, OUTPUT); //设置GOIP2引脚为输出模式
  digitalWrite(4, LOW); //设置GOIP2引脚为低电平
}

void loop() { 
  // put your main code here, to run repeatedly:
  digitalWrite(4, HIGH); //设置GOIP4引脚为高电平
  Serial.println("LED: ON");  //串口台中输入
  delay(500); //延迟500ms
  digitalWrite(4, LOW); //设置GOIP4引脚为低电平
  Serial.println("LED: OFF");
  delay(500);
}
