#pragma once
/*
Exercise 1:
	Write a C++ program that reads a maximum of 100 integers from the keyboard,
	stores them in a long array, sorts the integers in ascending order, and displays
	sorted output. Input can be terminated by any invalid input, such as a letter.

Exercise 2:
	Chapter 14 introduced the sample class DayTime and the isLess() method.
	Define and initialize an array with four DayTime class objects.
	Then write a main function that first uses the print() method to display the
	four elements. Finally, find the largest and smallest elements and output them on
	screen.

Exercise 3:
	Write a program that outputs all prime numbers less than 1000.The program
	should also count the number of prime numbers less than 1000.An integer >= 2
	is a prime number if it is not divisible by any number except 1 and itself. Use the
	Sieve of Eratosthenes:
		To find primary numbers simply eliminate multiples of any primary numbers
		you have already found, i.e.:
		first eliminate any multiples of 2 ( 4, 6, 8, ... ),
		then eliminate any multiples of 3 ( 6, 9, 12, ...),
		then eliminate any multiples of 5 ( 10, 15, 20, ..) // 4 has already been eliminated
		and so on.

Exercise 4:
	Write a C++ program to create the screen output shown opposite.The
	following banner

	* * * B R E A K * * *
	 
	is to be displayed in the center of the window and scrolled left.You can scroll
	the banner by beginning string output with the first character, then the second,
	and so on. Handle the string like a loop where the first letter follows the last
	letter and output continues until the starting position is reached.
	You can use a wait loop to modify the speed of the banner after each string is
	output.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;


void Exercise1() {
	long input [100];
	int i;

	cout << "Type an list of 100 or less numbers and I will sort them!" << endl;
	for (i = 0; i < 100 && cin >> input[i]; i++); //this is a full for loop, the condition is in the stop step, its weird but it works
	/*
	cin works in that it will skip any spaces, enters, or tabs
	originally I thought like a string it would treat every position
	as its own index, but it doesnt it uses spaces to determine the index

	the check for numbers is inbuilt because cin has to convert whatever is entered to long type
	if it cant it will end the loop, so typing any character that doesnt convert to long will
	close the for loop.

	technically you might want to use <vector> for this, its slower but has dynamically sized arrays
	*/


	int count = i;
	int end = count;
	bool sorted = false;
	long temp;

	while (!sorted) {
		sorted = true;
		--count; //stops out of bounds because you are checking 2 positions at a time and if you did --count last then the first pass would do count+1 on the final check

		for (i = 0; i < count; i++) {
			if (input[i] > input[i + 1]) {
				sorted = false;
				temp = input[i + 1];
				input[i + 1] = input[i];
				input[i] = temp;
			}
		}
	}
	cout << "Here are the sorted numbers" << endl;
	for (i = 0; i < end; i++) {
		cout << input[i] << " ";
	}
}

void Exercise3() {
	bool numbers[1001];
	fill(numbers, numbers + 1001, true);
	numbers[0] = false;
	numbers[1] = false;

	cout << "Here are all the prime numbers below 1000" << endl;

	/*
	This took a lot longer to understand than it shouldve, essentially what is happening is we skip 0 and 1 since they are not primes;
	We check if the squre of i is bigger than n. if it isnt and its true we make its square false and then increment by whatever its base is
	Ex:
		2 is true, and 2x2 = 4 which is less than 1000;
		we make 4 false, then increment by two to 6; we make 6 false, until this new variable is above 1000 and move to next parent loop;
		3 is true, and 3x3 = 9 is less than 1000;
		we make 9 false, as 6 was made false in the previous 2 loop, then 12, then 15, etc, etc
		this loop should stop at i = 31 as 32*32 > 1000;
	*/
	for (int i = 2; (i * i) <= 1000; i++) {
		if (numbers[i] == true) {
			for (int j = i * i; j <= 1000; j += i) {
				numbers[j] = false;
			}
		}
	}


	for (int i = 0; i < 1001; i++) {
		if (numbers[i] == true) {
			cout << i << " ";
		}
	}

	cout << "\n now you know the primes below 1000!" << endl;

}

#define LOCATE(x,y) (cout <<"\033["<< y <<';'<< x <<'H')
#define CLS (cout << "\033[2J") // Clear screen

void Exercise4() {
	string brkstring = "* * * * BREAK * * * *";
	int xpos = 0;
	long delay = 100000000L;
	while (true) {
		CLS;

		if (40-xpos < size(brkstring)) {
			LOCATE(0, 0);
			cout << brkstring.substr(40 - xpos, size(brkstring) - 1);
			LOCATE(xpos, 0);
			cout << brkstring.substr(0, (40 - xpos));
		}
		else {
			LOCATE(xpos, 0);
			cout << brkstring;
		}
		


		if (xpos < 40) { xpos++; }
		else { xpos = 0; }

		//delay
		for (long i = 0; i < delay; i++);
	}

}