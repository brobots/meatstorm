/* Low-level movement methods for autonomous */

// UNITS: THIS CODE USES INCHES!!! FOR ALL FUNCTIONS!!!
// Set these using a bumper switch
float currentX = 0;
float currentY = 0;

void moveDistance(float dist)
{
	float rotations = (dist / (4.0 * PI)); // convert dist to number of rotations (use wheel diameter)

	// reset SensorValue for your optical shaft controller
	// we need to add the wheel encoder(s) to the motor and sensors setup window!
	SensorValue[rwheelEncoder] = 0;
	SensorValue[lwheelEncoder] = 0;
	// 360 ticks for encoder per rev
	while(SensorValue[rwheelEncoder] < (360 * rotations)) // update this condition to match your optical shaft sensor value instead of 5
	{
		// activate motors- going straight. automatic straightening with shaft encoders
		motor[rightWheel] = 120;
		motor[leftWheel] = 120;
		if (SensorValue[rwheelEncoder] > SensorValue[lwheelEncoder])
		{
			motor[rightWheel] = 90;
			motor[leftWheel] = 120;
		}
		else if (SensorValue[lwheelEncoder] > SensorValue[rwheelEncoder])
		{
			motor[leftWheel] = 90;
			motor[rightWheel] = 120;
		}
		else
		{
			motor[rightWheel] = 120;
			motor[leftWheel] = 120;
		}

	}
	return; // once done rotating
}

void turn(float degrees) // positive: right; negative: left
{
	int rotations = 0; // convert degrees to number of rotations (use wheel diameter)
	// reset SensorValue for your optical shaft controller
	SensorValue[lwheelEncoder] = 0;
	SensorValue[rwheelEncoder] = 0;
	/* I'm not 100% sure this part is right, but I treated the rotation as a circle with the angle being a
	central angle of the circle and the width between wheels being the radius. Until we measure it tommorrow, I will
	make the radius 12 in or 1 ft. I then divided this section of the circumference by the wheel's circumference to find #  of rotations */
	rotations = abs((13.5 * PI * degrees / 180.0) / (4.0 * PI));
	// 360 ticks per rev
	if (degrees > 0)
	{
		while(abs(SensorValue[lwheelEncoder]) < (360 * rotations)) // update this condition to match your optical shaft sensor value instead of 5
		{
				// activate motors
				motor[leftWheel] = 70;
				motor[rightWheel] = 0;
		
		}
	
	}
	
	else
	{
		while(abs(SensorValue[rwheelEncoder]) < (360 * rotations))
		{
			//activate motors
			motor[rightWheel] = 70;
			motor[leftWheel] = 0;
		}
	}

	return; // once done rotating
}

void goTo(float x, float y) // unless you want to do complex path-finding to avoid obstacles like goals: find angle between you and destination, turn that angle, then move necessary distance.
{
	// compare x, y to currentX, currentY

	float distX = x-currentX;
	float distY = y-currentY;
	float angleRadians = atan(distY/distX);
	float realAngle = 90 - degreesToRadians(angleRadians);
	float hypotenuse = sqrt(distX*distX + distY*distY);
	turn(realAngle);
	moveDistance(hypotenuse);
	currentX = x;
	currentY = y;
}

void pickup() // activate intake for 2.5 seconds to scoop up some stuff.
{
	ClearTimer(T1);
	while(time10[T1] < 250) // time10 is in hundredths of a second, so we count for 2.5 seconds
	{
		motor[intake] = 90;
	}
	motor[intake] = 0;
}
