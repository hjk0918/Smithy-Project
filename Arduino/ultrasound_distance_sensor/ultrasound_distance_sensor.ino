const int trigPin = 9;
const int echoPin = 10;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  Serial.print("Distance: ");
  Serial.print(getDistance());
  Serial.println("cm");
  

}
float getDistance(){
  float duration;
  float distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); //trig gives a 10μs pulse
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); //retrieve the time (v=0.034 cm/μs)
  distance = duration*0.034/2;        //Distance in cm: s = t*0.034/2 

  return distance;
}
