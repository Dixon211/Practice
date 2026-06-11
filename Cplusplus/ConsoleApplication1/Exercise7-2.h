#pragma once
/*
Modify the program ball1.cpp to
	a. display a white ball on a blue background,
	b. terminate the program when the Esc key is pressed,
	c. increase the speed of the ball with the + key and decrease the speed
		with the – key.
You will need the functions kbhit() and getch() to solve
parts b and c of this problem.
*/



// ball1.cpp
// Simulates a bouncing ball
// ---------------------------------------------------
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
//#define DELAY 100000000L // Output delay
#define CLS (cout << "\033[2J") // Clear screen
#define BLS (cout << "\033[44m") //Blue Screen! added by me for a
#define RDS (cout << "\033[41m") //Red screen for practice
#define LOCATE(z,s) (cout <<"\033["<< z <<';'<< s <<'H')
// Position the cursor in row z and column s
void bouncingball()
{
	int x = 2, y = 3, dx = 1, speed = 0;
	unsigned long delay = 100000000L;
	string floor(79, '-'), header = "**** JUMPING BALL ****";
	BLS;
	CLS;
	LOCATE(1, 25); cout << header;
	LOCATE(25, 1); cout << floor;
	while (true) // Let the ball "always" bounce
	{ // Terminate by interrupt key (^C)
		LOCATE(1, 25); cout << header << " y: " << y << " x: " << x;
		LOCATE(y, x); cout << 'o' << endl; // Show the ball
		for (long wait = 0; wait < delay; ++wait)
			;
		if (x == 1 || x == 79) dx = -dx; // Bounce off
		// a wall?
		if (y == 24) // On the floor?
		{
			speed = -speed;
			if (speed == 0) speed = -7; // Restart
		}
		speed += 1; // Acceleration = 1
		LOCATE(y, x); cout << ' '; // Clear output
		y += speed; x += dx; // New Position
		if (_kbhit() != 0) //key check for b
		{
			switch (_getch()) {
				case 27: //esc
					RDS;
					CLS;
					break;
				case 43: //+
					delay -= delay / 5;
					break;
				case 45: //-
					delay += delay / 5;
					break;
			}
		}
	}
}