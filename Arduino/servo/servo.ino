#include <Servo.h>    // 声明调用Servo.h库
Servo myservo;        // 创建一个舵机对象
int pos = 0;          // 变量pos用来存储舵机位置
int openPos = 300;
int closePos = -300;

void setup(){
  myservo.attach(13);  // 将引脚13上的舵机与声明的舵机对象连接起来
}

void toPosition(int pos){
  int curPos = myservo.read(); //读取当前舵机位置
  if(curPos >= pos){
    for(int i = curPos; i > pos; i--){
      myservo.write(i);
      delay(5);
    }
  }else{
    for(int i = curPos; i < pos; i++){
      myservo.write(i);
      delay(5);
    }
  }
}
void loop(){
  while(true){
  toPosition(openPos);
  delay(1000);
  toPosition(closePos);
  delay(1000);
  }
}
