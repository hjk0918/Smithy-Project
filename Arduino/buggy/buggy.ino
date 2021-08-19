//#include<Servo.h>   // 声明调用Servo.h库
//Servo myservo;      // 创建一个舵机对象
char lr, maohao, n;
int pwm;
int openPos = 110;  //开门位置
int closePos = 40;  //关门位置
  //PWM capable Pin : 3,5,6,9,10,11   but: 9pin,10pin的pwm与servo库冲突
  // LeftMotor
int dir1PinA = 8; 
int dir2PinA  = 7;
int speedPinA = 6;
  // RightMotor
int dir1PinB = 2;
int dir2PinB = 4;
int speedPinB = 5;
  //shovel __ ignore it now
int dir1PinC = 12;
int dir2PinC = 10;
int speedPinC = 11;
  //Servo
int servoPin = 3;

void setup() {
  
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);
  pinMode(dir1PinC, OUTPUT);
  pinMode(dir2PinC, OUTPUT);
  pinMode(speedPinC, OUTPUT);

  //myservo.attach(servoPin); // 将舵机与声明的舵机对象连接起来
  pinMode(servoPin, OUTPUT);// 设定舵机接口为输出接口

  Serial.begin (9600); //initialise serial port
  
}


void servopulse(int servopin,int myangle)//定义一个脉冲函数
  {
  int pulsewidth=(myangle*11)+500;//将角度转化为500-2480 的脉宽值
  for(int i=0;i<=40;i++){
    digitalWrite(servoPin,HIGH);//将舵机接口电平至高
    delayMicroseconds(pulsewidth);//延时脉宽值的微秒数
    digitalWrite(servoPin,LOW);//将舵机接口电平至低
    delay(20-pulsewidth/1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available () > 0){ //when serial buffer receive data
    String s;
    boolean p;

    //读左右
    lr = Serial.read();
    delay(10);//Serial.println(lr);

    //读冒号
    maohao = Serial.read();
    delay(10);//Serial.println(l);

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

    if (lr == '1'){           //left motor
      if(pwm > 0){
        digitalWrite(dir1PinA, HIGH);
        digitalWrite(dir2PinA, LOW);
      }else{
        digitalWrite(dir1PinA, LOW);
        digitalWrite(dir2PinA, HIGH);
      }
      analogWrite(speedPinA, abs(pwm));
    }else if(lr == '2'){      //right motor
      if(pwm > 0){        
        digitalWrite(dir1PinB, HIGH);
        digitalWrite(dir2PinB, LOW);
      }else{
        digitalWrite(dir1PinB, LOW);
        digitalWrite(dir2PinB, HIGH);
      }
      analogWrite(speedPinB, abs(pwm));
    }else if(lr == '3'){      //shovel motor __ ignore it now
      if(pwm > 0){
        digitalWrite(dir1PinC, HIGH);
        digitalWrite(dir2PinC, LOW);
      }else{
        digitalWrite(dir1PinC, LOW);
        digitalWrite(dir2PinC, HIGH);
      }
      analogWrite(speedPinC, abs(pwm));
    }else if(lr == '4'){      //shovel motor step by step
      if(pwm > 0){
        digitalWrite(dir1PinC, HIGH);
        digitalWrite(dir2PinC, LOW);
      }else{
        digitalWrite(dir1PinC, LOW);
        digitalWrite(dir2PinC, HIGH);
      }
      analogWrite(speedPinC, 255);
      delay(30);
      analogWrite(speedPinC, 0);
    }
    else if(lr == '5'){     //both wheels
      if(pwm > 0){        
        digitalWrite(dir1PinA, HIGH);
        digitalWrite(dir2PinA, LOW);
        digitalWrite(dir1PinB, HIGH);
        digitalWrite(dir2PinB, LOW);
      }else{
        digitalWrite(dir1PinA, LOW);
        digitalWrite(dir2PinA, HIGH);
        digitalWrite(dir1PinB, LOW);
        digitalWrite(dir2PinB, HIGH);
      }
      analogWrite(speedPinA, abs(pwm));
      analogWrite(speedPinB, abs(pwm));
      
    }else if(lr == '6'){    //Servo Open
        servopulse(servoPin,openPos);//引用脉冲函数
    }else if(lr == '7'){    //Servo Close
        servopulse(servoPin,closePos);//引用脉冲函数
    }
  }
}


/*void setServo(int pos){
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
}*/
