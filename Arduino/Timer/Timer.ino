// Pin 13 has an LED connected on most Arduino boards.
int led = 13;
long initialTime;
int i = 0;
char data;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  
  /*if (Serial.read () > 0){
        
    digitalWrite(led, HIGH);  //turn on the led by sending any keystroke to serial monitor
    //initialTime = millis(); //COMPLETE THIS LINE: Start timer
    int x = Serial.read();
    Serial.println(x);
     
  }*/
  if(Serial.read()>0){
    i = Serial.readString().toInt();
    Serial.println(i);
  }
  /*if (millis() > initialTime + 3000){ //COMPLETE THIS LINE: if more than 3000 millisecond has elapsed since the intialTime turn led off
    
    digitalWrite(led, LOW);
  }  */
}
