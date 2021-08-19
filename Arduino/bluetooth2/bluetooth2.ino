char lr;
char colon;
char n;
int pwm;

// LeftMotor
int dir1PinA = 7; //Arduino的13和12号管脚分别连接IN3和IN4
int dir2PinA  = 6;
int speedPinA = 5;//Arduino的10号PWM输出管脚连接ENB


int LED_DOWN_R = 9;
int LED_DOWN_G = 10;
int LED_DOWN_B = 11;

/*
// RightMotor
int dir1PinB = 3; //Arduino的3和4号管脚分别连接IN1和IN2
int dir2PinB = 4;
int speedPinB = 5; //Arduino的5号PWM输出管脚连接ENA
*/

void setup() {
  Serial.begin (9600); //initialise serial port
  
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);

  
}
void loop() {
  
  if (Serial.available () > 0){ //when serial buffer receive data
    String s;
    s=Serial.readStringUntil('&');
    pwm = s.toInt();
    delay(4);

    if(pwm > 0){
      digitalWrite(dir1PinA, HIGH);
      digitalWrite(dir2PinA, LOW);
    }else{
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, HIGH);
    }
    analogWrite(speedPinA, abs(pwm));

  }
}
//void LED_UP_RGB(int red_light_value, int Lgreen_light_value, int blue_light_value)
// {
//  analogWrite(LED_UP_R, red_light_value);
//  analogWrite(LED_UP_G, green_light_value);
//  analogWrite(LED_UP_B, blue_light_value);
//}
//
//void LED_down_RGB(int red_light_value, int green_light_value, int blue_light_value)
// {
//  analogWrite(LED_DOWN_R, red_light_value);
//  analogWrite(LED_DOWN_G, green_light_value);
//  analogWrite(LED_DOWN_B, blue_light_value);
//}
