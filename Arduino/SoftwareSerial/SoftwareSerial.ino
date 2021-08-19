#include <SoftwareSerial.h> //加载软件串口库
SoftwareSerial BT(8, 9); //新建对象，设置软件串口端口，RX为D8，TX为D9
char val; //存储接收的变量
String s;
 
void setup() {
 Serial.begin(115200); //与PC串口连接
 Serial.println("BT is ready!");
 BT.begin(9600); //设置波特率
}
 
void loop() {
 //如果串口接收到数据，输出到蓝牙串口（手机）
 if (Serial.available()) {
 val = Serial.read();
 BT.print(val);
 }
 
 //如果接收到蓝牙模块的数据，输出到屏幕
 if (BT.available()) {
  s = BT.readStringUntil('&');
  Serial.println(s.toInt());
 }
}
