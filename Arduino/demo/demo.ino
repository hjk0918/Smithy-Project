int Sensor = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(Sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(Sensor)==HIGH){
    Serial.println("high");
  }else{
    Serial.println("low");
  }
  
  delay(200);
}
