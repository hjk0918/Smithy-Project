#include <Servo.h>    // 声明调用Servo.h库
Servo myservo;        // 创建一个舵机对象
char lr, maohao, n;
int pwm;
int pos = 0;          // 变量pos用来存储舵机位置
int openPos = 110;
int closePos = 40;

void setup(){
  myservo.attach(13);  // 将引脚13上的舵机与声明的舵机对象连接起来
  }

void loop(){
  if (Serial.available () > 0){ //when serial buffer receive data
    String s;
    boolean p;

    //读左右
    lr = Serial.read();
    delay(10);
    Serial.println(lr);

    //读冒号
    maohao = Serial.read();
    delay(10);
    //Serial.println(l);

    //读数字
    n = Serial.read();
    while(n != '&'){
      //Serial.println(n);
      s += (char)n;
      n = Serial.read();
    }
    Serial.println(s);
    pwm = s.toInt(); //得到pwm数值
    delay(20);

    if(lr == '6'){     //Servo Control
        myservo.write(openPos);
        //setServo(openPos);
    }else if(lr == '7'){
        myservo.write(closePos);
        //setServo(closePos);
    }
  }
}

void setServo(int pos){
  int curPos = myservo.read(); //读取当前舵机位置
  if(curPos >= pos){
    for(int i = curPos; i > pos; i--){
      myservo.write(pos);
      delay(5);
    }
  }else{
    for(int i = curPos; i < pos; i++){
      myservo.write(i);
      delay(5);
    }
  }
}
