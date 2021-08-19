int tempPin = A0;
float temp;

int dir1PinA = 8; //分别连接IN1和IN2
int dir2PinA  = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(tempPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = analogRead(tempPin);
  temp=temp * 0.48828125;
  Serial.println(temp);
  delay(500);
  
  if(temp > 28){
    digitalWrite(dir1PinA, HIGH);
    digitalWrite(dir2PinA, LOW);
  }else{
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, LOW);
  }
}
