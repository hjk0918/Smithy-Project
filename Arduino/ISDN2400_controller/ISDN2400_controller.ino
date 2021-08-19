#include <SoftwareSerial.h>
SoftwareSerial BT(12, 13);
//PID
float kp = 0.18;
float ki = 0.003;
float kd = 0.045;
float e, e_prev = 0, inte, inte_prev=0;

float t, t_prev, dt;
float Round, Round_prev = 0, RPM=0, RPM_d=5, RPM_h;

//Encoder
const byte interruptPinA = 2;
const byte interruptPinB = 4;
long EncoderCount = 0;

//Motor
int PWMPin = 5;
int DirPin1 = 7; 
int DirPin2 = 8;
const float PPR = 11; //pulse per revolution
const int gearRatio = 45;
float Vmax = 12;
float Vmin = -12;
float V = 0.1;

//RGB
int RGB_UP_R = 11;
int RGB_UP_G = 10;
int RGB_DOWN_R = 9;
int RGB_DOWN_G = 6;
int RGB_count = 255;
int RGB_freq = 10;
bool RGB_countdown = true;

volatile unsigned long count = 0;
unsigned long count_prev = 0;

void setup() {
  pinMode(interruptPinA, INPUT_PULLUP);
  pinMode(interruptPinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPinA), ISR_EncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(interruptPinB), ISR_EncoderB, CHANGE);
  Serial.begin(115200);
  //Serial.println("BT is ready!");
  BT.begin(9600);

  pinMode(DirPin1, OUTPUT);
  pinMode(DirPin2, OUTPUT);
  pinMode(PWMPin, OUTPUT);
  pinMode(RGB_UP_R, OUTPUT);
  pinMode(RGB_UP_G, OUTPUT);
  pinMode(RGB_DOWN_R, OUTPUT);
  pinMode(RGB_DOWN_G, OUTPUT);
  
  count = 0;
  PID_setup();
  RGB_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BT.available () > 0){
    changeRPM();
    PID_setup();
  }
  RGB_update();
  PID();
  if(count%20==0){
    BT.print(String(RPM));
  }
  
  delay(10);
  count++;
  //Serial.print(RPM_d); Serial.print('\t');
  Serial.print(128); Serial.print('\t');
  Serial.println(RPM_h);
  
  
  
}

void RGB_setup(){
  int RGB_count = 255;
  bool RGB_countdown = true;
}

void RGB_update(){
  if(RPM!=0){
    RGB_freq = RPM/10+2;
  }else{
    RGB_freq = 3;
  }
  RGB_DOWN((255+3*RGB_count)/4,RGB_count/5,0);
  RGB_UP(RGB_count,0,0);

  if(RGB_countdown == false){
    RGB_count += RGB_freq;
  }else{
    RGB_count -= RGB_freq;
  }
  if(RGB_count <= 0){
    RGB_count = 0;
    RGB_countdown = false;
  }else if(RGB_count >= 255){
    RGB_count = 255;
    RGB_countdown = true;
  }
}

void RGB_UP(int red_light_value, int green_light_value, int blue_light_value){
  analogWrite(RGB_UP_R, red_light_value);
  analogWrite(RGB_UP_G, green_light_value);
  //analogWrite(RGB_UP_B, blue_light_value);
}

void RGB_DOWN(int red_light_value, int green_light_value, int blue_light_value){
  analogWrite(RGB_DOWN_R, red_light_value);
  analogWrite(RGB_DOWN_G, green_light_value);
  //analogWrite(RGB_DOWN_B, blue_light_value);
}

void changeRPM(){
    String s;
    s=BT.readStringUntil('&');
    RPM_d = s.toInt();   
}

void PID_setup(){
  e=0;
  e_prev = 0;
  inte=0;
  inte_prev=0;
  //WriteDriverVoltage(2,12);
  //delay(50);
}

void PID(){
    t = millis(); //current time in millisecond
    dt = (t-t_prev);
    
    Round = EncoderCount/(PPR*gearRatio*2);
    RPM = (Round-Round_prev)*(1/dt)*1000*60;
    //RPM_h = RPM/22*40;
    e = RPM_d - RPM;
    
    inte = inte_prev + (dt * e);

    V = kp * e + ki * inte + (kd * (e - e_prev) / dt) ;
    if (V > Vmax) {
        V = Vmax;
        inte = inte_prev;
      }
      if (V < Vmin) {
        V = Vmin;
        inte = inte_prev;
      }
  
    WriteDriverVoltage(V, Vmax);
  
    Round_prev = Round;
    t_prev = t;
    inte_prev = inte;
    e_prev = e;
}

void ISR_EncoderA(){
  bool PinB = digitalRead(interruptPinB);
  bool PinA = digitalRead(interruptPinA);

  if(PinB == LOW){
    if(PinA == HIGH){
      EncoderCount++;
    }
    else{
      EncoderCount--;
    }
  }
  else{
    if(PinA == HIGH){
      EncoderCount--;
    }
    else{
      EncoderCount++;
    }
  }
}

void ISR_EncoderB(){
  bool PinB = digitalRead(interruptPinB);
  bool PinA = digitalRead(interruptPinA);

  if(PinA == LOW){
    if(PinB == HIGH){
      EncoderCount--;
    }
    else{
      EncoderCount++;
    }
  }
  else{
    if(PinB == HIGH){
      EncoderCount++;
    }
    else{
      EncoderCount--;
    }
  }
}

void WriteDriverVoltage(float V, float Vmax) {
  int PWMval = int(255 * abs(V) / Vmax);
  if (PWMval > 255) {
    PWMval = 255;
  }
  if (V > 0) {
    digitalWrite(DirPin1, HIGH);
    digitalWrite(DirPin2, LOW);
  }
  else if (V < 0) {
    digitalWrite(DirPin1, LOW);
    digitalWrite(DirPin2, HIGH);
  }
  else {
    digitalWrite(DirPin1, LOW);
    digitalWrite(DirPin2, LOW);
  }
  analogWrite(PWMPin, PWMval);
}
