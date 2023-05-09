#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //初识化串口波特率
  Serial.println("Serial Init Done!");

}

void loop() { 
  Serial.println(78);
  Serial.println(78, BIN);
  Serial.println(78, OCT);
  Serial.println(78, DEC);
  Serial.println(78, HEX);

  Serial.println(1.3456);
  Serial.println(1.3456, 0);
  Serial.println(1.3456, 1);
  Serial.println(1.3456, 2);
  Serial.println(1.3456, 4);

  Serial.print("No Format");
  Serial.print("\t");

  Serial.print("BIN");
  Serial.print("\t");

  Serial.print("OCT");
  Serial.print("\t");

  Serial.print("DEC");
  Serial.print("\t");

  Serial.print("HEX");
  Serial.print("\n");

  for(int i=0; i<64; i++){
    Serial.print(i);
    Serial.print("\t\t");

    Serial.print(i, BIN);
    Serial.print("\t");

    Serial.print(i, OCT);
    Serial.print("\t");

    Serial.print(i, DEC);
    Serial.print("\t");

    Serial.print(i, HEX);
    Serial.println();
  }

  while(1){
    if(Serial.available() > 0){
      int incomingByte = Serial.read();
      // int incomingByte = Serial.peek(); //返回传入串行数据的下一个字节（字符），而不将其从内部串行缓冲区中删除
      Serial.printf("%c", incomingByte);
    }

    delay(10);
  }
  
}
