#pragma once
#include <iostream>
using namespace std;

bool a;
char b;
wchar_t c;
short d;
int e;
long f;
float g;
double h;
long double i;

int sizeoftesting() {
	cout << "Byte size of a bool: " << sizeof(a) << "\n";
	cout << "Byte size of a char: " << sizeof(b) << "\n";
	cout << "Byte size of a wchar_t: " << sizeof(c) << "\n";
	cout << "Byte size of a short: " << sizeof(d) << "\n";
	cout << "Byte size of an int: " << sizeof(e) << "\n";
	cout << "Byte size of a long: " << sizeof(f) << "\n";
	cout << "Byte size of a float: " << sizeof(g) << "\n";
	cout << "Byte size of a double: " << sizeof(h) << "\n";
	cout << "Byte size of a long double: " << sizeof(i) << "\n";
	cout << endl;

	return 0;
}