#pragma once
/*
Write a C++ program to output the sine curve on screen as in the graphic
shown on the opposite page. Its a basic Sine Curve
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string headertxt = "-------- The Sine Function ---------";

#define CLS (cout << "\033[2J") //clear screen
#define LOCATE(x,y) (cout << "\033[" << (y) << ";" << (x) <<"H") //moves cursor to that line/column
#define DOT(x,y) (LOCATE(x,y) << '*') //place dot
#define PI 3.14159265
#define FULLX 100
#define FULLY 30
#define START 0
#define END (2 * PI)


void drawgraph(int x = 100, int y = 30) {
	for (int i = 2; i < (y + 2); i++) {
		LOCATE(x / 10, i) << "|";
	}
	string xline(x + (x / 10), '-');
	LOCATE(0, y / 2);
	cout << xline;
	LOCATE((x / 10) + 1, (y / 2) + 1) << '0';
	LOCATE(x + (x / 10), (y / 2) + 1) << "2PI";
}

void drawgraph2() {

	//draw header
	LOCATE((FULLX / 2) - (headertxt.length() / 2), 1);
	cout << headertxt;

	//draw x axis
	LOCATE(2, (FULLY / 2)+2);
	for (int i = 1; i < FULLX; i++) {
		cout << (i % 5 ? "\304" : "\305");
	}
	LOCATE(0, (FULLY / 2)+2);
	cout << "\021";
	LOCATE(FULLX, (FULLY / 2)+2);
	cout << "\020";


	//draw y axis
	for (int i = 2; i < FULLY + 2; i++) {
		LOCATE(FULLX / 10, i);
		cout << (i % 5 ? "\263" : "\305"); //these are octets; use ASCII table and convert to decimal
	}
	LOCATE(FULLX / 10, 2);
	cout << "\036";
	LOCATE(FULLX / 10, FULLY+2);
	cout << "\037";

	//draw lengths
	LOCATE(FULLX - 2, (FULLY / 2) + 1);
	cout << "2" << "\343";
	LOCATE((FULLX / 10) + 1, (FULLY / 2) + 1);
	cout << "0";
	LOCATE((FULLX / 10) + 2, 2);
	cout << "1";
	LOCATE((FULLX / 10) + 2, FULLY);
	cout << "-1";
}

void drawcurve(double x = 100, double y = 30) {
	double result;
	double offset = x / 10;
	for (double i = offset + 1; i < (x + offset); i++) {
		result = sin((i - offset) * ((2 * PI) / x)); //this is correct
		DOT(i, (y)+((y)*result));
	}
}

void drawcurve2() {
	double result;
	int ypos;
	double offset = FULLX / 10;
	double range = FULLX - offset;
	for (double i = offset; i < FULLX; i++) {
		result = sin((i - offset) * ((2 * PI) / range));
		ypos = (((result * -1) * ((FULLY / 2))) + (FULLY / 2));
		DOT(i, ypos + 2);
	}
}

void getsinepositions() {
	double result;
	int ypos;
	double offset = FULLX / 10;
	double range = FULLX - offset;
	int sineypositions[90];
	for (double i = offset; i < FULLX; i++) {
		result = sin((i - offset) * ((2 * PI) / range));
		ypos = ((((result * -1) * ((FULLY / 2))) + (FULLY / 2))+2);
		
	}
}

void drawsine() {
	drawgraph2();
	drawcurve2();
	LOCATE(1000, 1000);
}
