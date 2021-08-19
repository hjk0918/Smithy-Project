int servopin=13;//定义数字接口13 连接伺服舵机信号线
int pulsewidth;//定义脉宽变量
int val;
int openPos = 110;  //开门位置
int closePos = 40;  //关门位置
 
void servopulse(int servopin,int myangle)//定义一个脉冲函数
  {
  pulsewidth=(myangle*11)+500;//将角度转化为500-2480 的脉宽值
  for(int i=0;i<=50;i++){
    digitalWrite(servopin,HIGH);//将舵机接口电平至高
    delayMicroseconds(pulsewidth);//延时脉宽值的微秒数
    digitalWrite(servopin,LOW);//将舵机接口电平至低
    delay(20-pulsewidth/1000);
  }
}
 
void setup()
  {
  pinMode(servopin,OUTPUT);//设定舵机接口为输出接口
  Serial.begin(9600);//连接到串行端口，波特率为9600
  Serial.println("servo=o_seral_simple ready" ) ;
  }
 
void loop()
{
  val=Serial.read();//读取串行端口的值
  if(val == 'q'){
    servopulse(servopin,openPos);//引用脉冲函数
  }else if(val == 'w'){
    servopulse(servopin,closePos);//引用脉冲函数
  }
} 
