// 电机A
int dir1PinA = 6; //分别连接IN1和IN2
int dir2PinA  = 7;
int speedPinA = 5;//PWM输出管脚连接ENA

void setup() {
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);

}

void loop() {
  analogWrite(speedPinA, 255);//输出PWM脉冲到ENA
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
  delay(1000);

  /*analogWrite(speedPinA, 100);//输出PWM脉冲到ENA
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
  delay(1000);*/
}
