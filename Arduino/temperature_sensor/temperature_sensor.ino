int tempPin = A0;
float temp;

void setup() {
  // put your setup code here, to run once:
  pinMode(tempPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = analogRead(tempPin);
  temp=temp * 0.48828125;

  Serial.println(temp);
  delay(500);
}
