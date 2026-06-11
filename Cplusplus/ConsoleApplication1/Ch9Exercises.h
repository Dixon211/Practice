#pragma once
/*
Exercise 1
	Write a C++ program to
		■ initialize a string s1 with the string "As time by ..." and a second
		string s2 with the string "goes",
		■ insert string s2 in front of "by" in string s1,
		■ erase the remainder of string s1 after the substring "by",
		■ replace the substring "time" in s1 with "Bill".
	In each case, your program should determine the position of the substring.
	Output string s1 on screen at the beginning of the program and after every
	modification.
Exercise 2
	Write a C++ program that reads a word from the keyboard, stores it in a string,
	and checks whether the word is a palindrome.A palindrome reads the same
	from left to right as from right to left.The following are examples of
	palindromes:“OTTO, ” “deed, ” and “level.”
	Use the subscript operator []. Modify the program to continually read and
	check words.
Exercise 3
	Write down the screen output for the program on the opposite page.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



void exercise91() {
	string s1 = "As time by ...";
	string s2 = "goes";

	cout << s1 << "\n";
	s1.insert(s1.find("by"), s2+" ");
	cout << s1 << "\n";
	s1.erase(s1.find("by")+2, s1.length()+1);
	cout << s1 << "\n";
	s1.replace(s1.find("time"), 4, "Bill");
	cout << s1<< "\n";
}

void exercise92() {
	string possibility;
	string reversestring;
	cout << "Write a word and I will check if its a palindrome: ";
	cin >> possibility;
	reversestring = possibility;
	reverse(begin(reversestring), end(reversestring));
	for (int i = 0; i < possibility.length()-1; i++) {
		if (possibility[i] != reversestring[i]) {
			cout << "\n" + possibility + " is not a palindrome\n";
			return;
		}
	}
	cout << "\n" + possibility + " is a palindrome, congratz!\n";
}