/* Low-level movement methods for autonomous */

// Set these using a bumper switch
float currentX = 0;
float currentY = 0;

void moveDistance(float dist)
{
	int rotations = 0; // convert dist to number of rotations (use wheel diameter)
	// reset SensorValue for your optical shaft controller
	while(5 <= rotations) // update this condition to match your optical shaft sensor value instead of 5
	{
		// activate motors
	}
	return; // once done rotating
}

void turn(float degrees)
{
	int rotations = 0; // convert degrees to number of rotations (use wheel diameter)
	// reset SensorValue for your optical shaft controller
	while(5 <= rotations) // update this condition to match your optical shaft sensor value instead of 5
	{
		// activate motors
	}
	return; // once done rotating
}

void goTo(float x, float y)
{
	// compare x, y to currentX, currentY
	// unless you want to do complex path-finding to avoid obstacles like goals: find angle between you and destination, turn that angle, then move necessary distance.
}
