#pragma once
#include <iostream>
using namespace std;

float first(123.456);
float second(75.543);

void floatexercise() {
	cout << "Sum of " << first << " and " << second << ": " << (first + second);
	cout << "\nDifference of " << first << " and " << second << ": " << (first - second) << endl;
}
.