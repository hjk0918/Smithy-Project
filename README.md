# Physical Prototyping: Smithy

## Project Overview
<p align="center" width="75%">
  <img src="/images/20200517_195020.jpg" width="75%">
  This is a year 1 physical prototyping project involving CAD design, 3D printing & scanning, linkage, Arduino, and mobile App.
I created a scene of a traditional smithy. When the system is turned on, the blacksmith starts to strike the unfinished sword with a hammer. The air blower pumps air into the forge while the fire inside the forge is flickering (lighted up by LED) and jumping up and down. The driven motor can be tele-controlled by an Android App with either touching and motion detection.
</p>




## Mechanism
<p align="center">
  <img src="/images/image1.png" width="75%">
  <img src="/linkages/Bar_air_blower.png" width="75%">
  <img src="/linkages/Bar_fire.png" width="75%">
  <img src="/linkages/Bar_hammer.png" width="75%">
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

