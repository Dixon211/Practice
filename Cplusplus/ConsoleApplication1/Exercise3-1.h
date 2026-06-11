#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <regex>
using namespace std;



void checkstring(string input) {
	regex pattern("^[0-9]*\\.?[0-9]+$");
	if (regex_match(input, pattern)) {
		//True
		cout << "Square Root of " << input << " is " << sqrt(stoi(input)) << endl;
	}
	else {
		//False
		cout << "Not a valid number, try again: ";
		getline(cin, input);
		checkstring(input);
	}
}

void findsqrt() {
	string input;
	cout << "Number\tSquare Root\n4\t" << sqrt(4) << "\n12.25\t" << sqrt(12.25) << "\n0.0121\t" << sqrt(0.0121) << "\n";
	cout << "Type a number and get the sqrt: ";
	getline(cin, input);
	checkstring(input);
}