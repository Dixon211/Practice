#pragma once
/*
Exercise 1
	What happens if the parameter in the sample function strToUpper() is
	declared as a string& instead of a string?

Exercise 2
	Write a void type function called circle() to calculate the circumference and
	area of a circle.The radius and two variables are passed to the function, which
	therefore has three parameters:

	Parameters: A read-only reference to double for the radius and two
	references to double that the function uses to store the area
	and circumference of the circle.

	Test the function circle() by outputting a table containing the radius, the
	circumference, and the area for the radii 0.5, 1.0, 1.5, . . . , 10.0.

Exercise 3
	a. The version of the function swap() opposite can be compiled without
	producing any error messages. However, the function will not swap the
	values of x and y when swap(&x,&y); is called.What is wrong?
	b. Test the correct pointer version of the function swap() found in this
	chapter.Then write and test a version of the function swap() that uses
	references instead of pointers.

Exercise 4
	Create a function quadEquation() that calculates the solutions to quadratic
	equations.The formula for calculating quadratic equations is shown opposite.

	Arguments: The coefficients a, b, c and two pointers to both solutions.
	Returns: false, if no real solution is available, otherwise true.

	Test the function by outputting the quadratic equations on the opposite page
	and their solutions.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

#define PI 3.141592

void Exercise121();
void Exercise122();
void Exercise123();
void Exercise124();
void strToUpper(string&);
void circle(const double&, double&, double&);
void swap(float*, float*);
void referenceswap(float&,float&);
bool quadraticsolve(double, double, double, double*, double*);

void Exercise121() {
	string a = "this is a string";
	strToUpper(a);
	cout << a;
	cout << "\n The string itself is modified when a reference is passed, when the function is called without a string reference it creates a copy in the function, modifies that, and then deletes it at the end of the function scope";
}

void Exercise122() {
	double area;
	double circumference;

	 for(double radius = 0.5; radius < 10.5; radius += .5) {
		 circle(radius, area, circumference);
		 cout << "\n\nradius: " << radius << "\nArea: " << area << "\nCircumference: " << circumference;
	}
}

void Exercise123() {
	float a = 10;
	float b = 30;
	cout << "\n the float needs to be a full variable not a pointer and the swap needs to be done by the pointers reference where they are pointing";
	referenceswap(a,b);
	cout << "\n a:" << a << "\n b:" << b;
}

void Exercise124() {
	double solution1;
	double solution2;
	double* ptr1 = &solution1;
	double* ptr2 = &solution2;
	double a;
	double b;
	double c;
	//first test
	a = 2;
	b = -2;
	c = -1.5;
	if (quadraticsolve(a, b, c, ptr1, ptr2)) {
		cout << "\nx1:" << solution1 << " x2:" << solution2;
	}
	else {
		cout << "\nnone";
	}
	//second test
	a = 1;
	b = -6;
	c = 9;
	if (quadraticsolve(a, b, c, ptr1, ptr2)) {
		cout << "\nx1:" << solution1 << " x2:" << solution2;
	}
	else {
		cout << "\nnone";
	}
	//third test
	a = 2;
	b = 0;
	c = 2;
	if (quadraticsolve(a, b, c, ptr1, ptr2)) {
		cout << "\nx1:" << solution1 << " x2:" << solution2;
	}
	else {
		cout << "\nnone";
	}
}

void strToUpper(string& str) {
	int len = str.length();
	for (int i = 0; i < len; ++i)
		str[i]=toupper(str[i]);
}

void circle(const double& radius, double& area, double& circumference) {
	area = PI * pow(radius, 2);
	circumference = PI * radius * 2;
}

void swap(float* p1, float* p2)
{
	float temp; // Temporary variable
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void referenceswap(float& ref1, float& ref2) {
	float temp;
	temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

bool quadraticsolve(double a, double b, double c, double* sol1, double* sol2) {
	if ((pow(b, 2) - (4 * a * c)) < 0)
		return false;
	*sol1 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
	*sol2 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
	return true;
}