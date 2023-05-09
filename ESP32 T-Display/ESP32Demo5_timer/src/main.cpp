#include <Arduino.h>


volatile int interruptCounter;
int totalInterruptCounter;
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

//	函数名称：onTimer()
//	函数功能：中断服务的功能，它必须是一个返回void（空）且没有输入参数的函数，
//	为使编译器将代码分配到IRAM内，中断处理程序应该具有 IRAM_ATTR 属性
void IRAM_ATTR onTimer() {
	// Serial.println(interruptCounter++);
	portENTER_CRITICAL_ISR(&timerMux);
	interruptCounter++;
	portEXIT_CRITICAL_ISR(&timerMux);
}

void IRAM_ATTR onTimer2(){
  Serial.println("Timer2 is on time");
}

void setup() {
  Serial.begin(115200);

  //	函数名称：timerBegin()
	//	函数功能：Timer初始化，分别有三个参数
	//	函数输入：1. 定时器编号（0到3，对应全部4个硬件定时器）
	//			     2. 预分频器数值（ESP32计数器基频为80M，80分频单位是微秒）
	//			     3. 计数器向上（true）或向下（false）计数的标志
	//	函数返回：一个指向 hw_timer_t 结构类型的指针
  hw_timer_t *timer = timerBegin(0, 80, true);
  hw_timer_t *timer2 = timerBegin(1, 160, true);

  //	函数名称：timerAttachInterrupt()
	//	函数功能：绑定定时器的中断处理函数，分别有三个参数
	//	函数输入：1. 指向已初始化定时器的指针（本例子：timer）
	//			     2. 中断处理函数的地址
	//			     3. 表示中断触发类型是边沿（true）还是电平（false）的标志
	//	函数返回：无
  timerAttachInterrupt(timer, &onTimer, true);
  timerAttachInterrupt(timer2, &onTimer2, true);

  //	函数名称：timerAlarmWrite()
	//	函数功能：指定触发定时器中断的计数器值，分别有三个参数
	//	函数输入：1. 指向已初始化定时器的指针（本例子：timer）
	//			    2. 第二个参数是触发中断的计数器值（1000000 us -> 1s）
	//			    3. 定时器在产生中断时是否重新加载的标志
	//	函数返回：无
  timerAlarmWrite(timer, 1000000, true);
  timerAlarmWrite(timer2, 1000000, true);

  //使能定时器
  timerAlarmEnable(timer);
  timerAlarmEnable(timer2);
}


void loop() { 
  if (interruptCounter > 0) {
		portENTER_CRITICAL(&timerMux);
		interruptCounter--;
		portEXIT_CRITICAL(&timerMux);
		totalInterruptCounter++;
		Serial.print("An interrupt as occurred. Total number: ");
		Serial.println(totalInterruptCounter);
	}
}
