Pcoord ball.position = {0, 0, 0}; //coordinate for base of cannon
gravity_accel = -9.8;

void time_step_cpu(double delta_t)
{
	//Pressure -> acceleration -> velocity
	if(ball_in_cannon() || is_fired)
	{
	double velocity = sqrt(2*cannon.length*pressure*ball.area*mass_inv) ;
	/*
	Theta is the angle of the cannon along the y-axis, how horizontal the cannon will fire(0 degrees = horizontal, 90 	 degrees is vertical
	Phi is the angle from the positive x-axis, M_PI/2 would be +Z direction. Range from 0 to M_PI
	*/
	ball.velocity.y = sin(Theta) * velocity;
	
	double velocity2 = cos(Theta) * velocity; //this is the velocity amount in the horizontal 	direction
	
	ball.velocity.z = sin(Phi) * velocity2;
	
	ball.velocity.x = cos(Phi) * velocity2;
	
	ball.position += ball.velocity;
	}
	else if(detect_collision())
	{
		//collision physics
	}
	else //ball in flight
	{
	ball.position.y += ball.velocity.y*delta_t + .5*gravity_accel*delta_t*delta_t;
	
	ball.position.z += ball.velocity.z*delta_t;
	
	ball.position.x += ball.velocity.x*delta_t;
	}
}
	