int input1 = 2; // 定义uno的pin 5 向 input1 输出 
int input2 = 3; // 定义uno的pin 6 向 input2 输出
int input3 = 9; // 定义uno的pin 9 向 input3 输出
int input4 = 10; // 定义uno的pin 10 向 input4 输出

void setup() {
  // put your setup code here, to run once:

  pinMode(input1,OUTPUT);
  pinMode(input2,OUTPUT);
  pinMode(input3,OUTPUT);
  pinMode(input4,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(input1,255);
  analogWrite(input2,0);
  digitalWrite(input1,HIGH);
  digitalWrite(input2,LOW);
  digitalWrite(input3,HIGH); //给高电平
  digitalWrite(input4,LOW);  //给低电
  digitalWrite(13,HIGH);
  delay(1000);

  digitalWrite(input1,LOW);
  digitalWrite(input2,LOW);
  digitalWrite(input3,LOW);
  digitalWrite(input4,LOW); 
  digitalWrite(13,LOW);
  delay(500);
  
  digitalWrite(input1,LOW);
  digitalWrite(input2,HIGH);
  digitalWrite(input3,LOW);
  digitalWrite(input4,HIGH); 
  delay(1000);
}
