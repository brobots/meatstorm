## Motors and Ports

**Digital:**

* 1, 2: quadrature encoder on right side for tower
* 3: single-wire encoder on right base wheel
* 5: touch
* 6: touch
* 7: touch
* 8: touch
	
**Motors:**

* 2: Right tower; 2-wire 393
* 3: Left tower; 2-wire 393
* 6: Intake; 3-wire
* 8: Left wheel; 3-wire
* 9: Right wheel; 3-wire

**Code for all that:**

```
#pragma config(Sensor, dgtl1,  rightTowerEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  Button1,        sensorTouch)
#pragma config(Sensor, dgtl6,  Button2,        sensorTouch)
#pragma config(Sensor, dgtl7,  Button3,        sensorTouch)
#pragma config(Sensor, dgtl8,  Button4,        sensorTouch)
#pragma config(Motor,  port2,           rightTower,    tmotorVex393, openLoop)
#pragma config(Motor,  port3,           leftTower,     tmotorVex393, openLoop)
#pragma config(Motor,  port6,           intake,        tmotorNormal, openLoop)
#pragma config(Motor,  port8,           leftWheel,     tmotorNormal, openLoop)
#pragma config(Motor,  port9,           rightWheel,    tmotorNormal, openLoop)
```

