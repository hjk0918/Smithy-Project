char lr;
char colon;
char n;
int pwm;

// LeftMotor
int dir1PinA = 7; 
int dir2PinA  = 6;
int speedPinA = 5;


int LED_DOWN_R = 9;
int LED_DOWN_G = 10;
int LED_DOWN_B = 11;



void setup() {
  Serial.begin (9600); //initialise serial port
  
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);

  
}
void loop() {
  
  if (Serial.available () > 0){ //when serial buffer receive data
    String s;
    boolean p;

    //读左右
    lr = Serial.read();
    delay(4);//Serial.println(lr);

    //读冒号
    colon = Serial.read();
    delay(4);//Serial.println(l);

    //读数字
    n = Serial.read();
    while(n != '&'){
      //Serial.println(n);
      s += (char)n;
      n = Serial.read();
    }
    //Serial.print(p);
    pwm = s.toInt();
    delay(4);

    if (lr == '1'){
      if(pwm > 0){
        digitalWrite(dir1PinA, HIGH);
        digitalWrite(dir2PinA, LOW);
      }else{
        digitalWrite(dir1PinA, LOW);
        digitalWrite(dir2PinA, HIGH);
      }
      analogWrite(speedPinA, abs(pwm));
    }
    /*else if(lr == '2'){
      if(pwm > 0){
        digitalWrite(dir1PinB, HIGH);
        digitalWrite(dir2PinB, LOW);
      }else{
        digitalWrite(dir1PinB, LOW);
        digitalWrite(dir2PinB, HIGH);
      }
      analogWrite(speedPinB, abs(pwm));
    }*/
    
  }
}
