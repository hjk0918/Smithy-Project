# Physical Prototyping: Smithy
<p align="center" width="75%">
  [![IMAGE ALT TEXT](http://img.youtube.com/vi/cRNW_WYLdRA/0.jpg)](http://www.youtube.com/watch?v=cRNW_WYLdRA "Video Title")
</p>

## Project Overview
<p align="center" width="75%">
  <img src="/images/20200517_195020.jpg" width="75%">
</p>
 This is my year 1 physical prototyping project for course ISDN2400. This project involves CAD design, 3D printing & scanning, linkage, Arduino, and mobile App. Basically, I created a scene of a traditional smithy. When the system is turned on, the blacksmith starts to strike the unfinished sword with a hammer. The air blower pumps air into the forge while the fire inside the forge is flickering (lighted up by LED) and jumping up and down. The driven motor can be tele-controlled by an Android App with either touching and motion detection.

## Mechanism
<p align="center">
  <img src="/images/image1.png" width="75%">
  <img src="/linkages/Bar_air_blower.png" width="75%">
  <img src="/linkages/Bar_fire.png" width="75%">
</p>
The mechanical motion system consists of three parts, the blacksmith, the air blower and the forge. Each part is an extension from four-bar linkage, designed by me. I separately designed each single mechanism, and then combined them all together with gears, so that it can be driven by one motor.

## PID Control
The torque of the linkage system fluctuates while working. At the beginning, I used PWM control to input a constant votage to the motor, but it can’t rotate at a constant speed. So I used PID control regarding to the error between the current RPM and my target RPM. Then the whole system could keep working at a certain speed that I want. 
<p align="center">
  <img src="/images/image2.png" width="75%">
</p>

## 3D Printing & 3D Scanning
<p align="center">
  <img src="/images/image4.png" width="75%">
  <img src="/images/image5.png" width="75%">
</p>

## Conclusion
In this project, I spent most of my time on linkage design and PID controller. For mechanical design, It takes me quite a lot of time to adjust dimensions for different linkage systems to fit into one. There were always some unexpected interferences that I should deal with. If I were doing this project once again, I would consider the system as a whole thing at the very beginning. This is also my first time to write a PID controller by myself. Its performance turned out to be so amazing and I'm proud of it. 
