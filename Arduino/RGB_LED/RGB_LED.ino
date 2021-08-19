int LED_UP_R = 3;
int LED_UP_G = 5;
int LED_UP_B = 6;

int LED_DOWN_R = 9;
int LED_DOWN_G = 10;
int LED_DOWN_B = 11;

void setup() {
  pinMode(LED_UP_R, OUTPUT);
  pinMode(LED_UP_G, OUTPUT);
  pinMode(LED_UP_B, OUTPUT);
  pinMode(LED_DOWN_R, OUTPUT);
  pinMode(LED_DOWN_G, OUTPUT);
  pinMode(LED_DOWN_B, OUTPUT);
}

void loop() {
  for(int i=0;i<=255;i+=5){
    LED_UP_RGB(255-i,255-i,0);
    LED_down_RGB(i,0,0);
    delay(30);
  }
  for(int i=0;i<=255;i+=5){
    LED_UP_RGB(i,i,0);
    LED_down_RGB(255-i,0,0);
    delay(50);
  }
  

}

void RGB_UP_RGB(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(LED_UP_R, red_light_value);
  analogWrite(LED_UP_G, green_light_value);
  analogWrite(LED_UP_B, blue_light_value);
}

void LED_down_RGB(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(LED_DOWN_R, red_light_value);
  analogWrite(LED_DOWN_G, green_light_value);
  analogWrite(LED_DOWN_B, blue_light_value);
}
