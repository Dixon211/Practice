#pragma once
#include <iostream>
#include <random>
using namespace std;
/*
Exercise 1
	Given an array v with the following definition:
		int v[] = { 10, 20, 30, 40 }, i, *pv;
	What screen output is caused by the following statements?
		a. for( pv = v; pv <= v + 3; pv++ )
			cout << " *pv = " << *pv;
		b. for( pv = v, i = 1; i <= 3; i++ )
			cout << " pv[i] = " << pv[i];
		c. for( pv = v, i = 0; pv+i <= &v[3]; pv++,i++)
			cout << " *(pv + i) = " << *(pv + i);
		d. for( pv = v + 3; pv >= v; --pv )
			cout << " v[" << (pv - v) << "] = "
			<< v[pv - v];

	Answers:
		a.  *pv = 10 *pv = 20 *pv = 30 *pv = 40  //v+3 acts as pointer location, cout << v+3 gives memory location; cout<< *(v+3) is 40
		b. pv[i]  = 20 pv[i] = 30 pv[i] = 40
		c. *(pv + i) = 10 *(pv + i) = 30
		d. v[3] = 40  v[2] = 30 v[1] = 20 v[0] = 10 //remember that for pointers v is equivilant to &v[0] so v+3 is &v[0] + 3, which is &v[3] also pv >= v is pv >= &v[0]. which also works for a
*/


/*
Exercise 2
	Write a program that uses the cin method get() to read a line character by
	character and stores it in a char array.The line is then output in reverse order.
	Use a pointer, not an index, to address the array elements.
*/

void Exercise172() 
{
	char input[256];
	char* start = input;
	char* end = input;

	cout << "Please Enter a phrase less than 256 characters and I will reverse it!\n";
	for (; end < start + 255 && cin.get(*end) && *end != '\n'; end++);
	cout << "\nHere is the reverse string: ";
	for (end; end >= start; end--) { cout << *end; }
	cout << "\n";
}


/*
Exercise 3
	The standard function strcmp() performs a lexicographical comparison of two
	C strings.The opposite page contains an index version of strcmp().The return
	value is the difference between two character codes.
	Write a pointer version of the function strcmp(). Call this function
	str_cmp() to distinguish it from the standard function.
	To test the function, use a loop to read two lines of text and output the
	results of the comparison.The loop should terminate when both strings are
	empty.
*/

int Exercise173(const char* str1, const char* str2)
{
	int i;

	for (i = 0; str1[i] == str2[i] && str1[i] != '\0'; i++);
	return(str1[i] - str2[i]);
}

/*
Exercise 4
	Define and test the function selectionSort() that sorts an array of int
	values in ascending order.The principle of the selection sort algorithm is shown
	opposite.
	Arguments: An int array and its length
	Return values: None
	Develop both an index version and a pointer version.Test the functions with
	random numbers between -10000 and +10000.
*/

void indexselectionSort(int randomarray[], int length) //it works!!
{
	int mini, j, temp;

	for (int i = 0; i < length; i++) {

		mini = i;

		for (j = i + 1; j < length; j++) {
			if (randomarray[mini] > randomarray[j]) {
				mini = j;
			}
		}

		if (mini != i) {
			temp = randomarray[i];
			randomarray[i] = randomarray[mini];
			randomarray[mini] = temp;
		}
	}

	cout << "Here is the sorted Array using indeces: ";
	for (int i = 0; i < length; i++) {
		cout << randomarray[i] << " ";
	}
}

void ptrselectionSort(int randomarray[], int length) { //it works!!!
	int* current, * ptr, * mini;
	int temp;

	for (current = randomarray; current < (randomarray+length); current++) {
		mini = current;

		for (ptr = current + 1; ptr < (randomarray + length); ptr++) {
			if (*ptr < *mini) {
				mini = ptr;
			}
		}

		if (*mini < *current) {
			temp = *current;
			*current = *mini;
			*mini = temp;
		}
	}

	cout << "Here is the sorted Array using pointers: ";
	for (ptr = randomarray; ptr < randomarray + length; ptr++) {
		cout << *ptr << " ";
	}
}

void Exercise174()
{
	//using <random> standard library to create a random number generator
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(-10000, 10000);

	int randomnums[10];

	cout << "Generating random array of ints\n" << "Here is the array: ";

	for (int i = 0; i < 10; i++) {
		randomnums[i] = dist(gen);
		cout << randomnums[i] << " ";
	}
	cout << endl;
	
	//indexselectionSort(randomnums, 10);
	ptrselectionSort(randomnums, 10);
}

/*
Exercise 5
a. Write a program that outputs its own name and all command line arguments, each in a separate line.
b. Now extend the program to output its own environment.The environment is a memory area containing strings in the format
NAME=String
A third parameter for the function main() allows access to the environment.
This parameter is an array of pointers just like argv.The array elements are
char pointers to the environment strings, the last element being a NULL
pointer.
*/

void maintesting(int args, char* qargs[]) { //have to build and run in CMD
	cout << "Program Name: " << qargs[0] << "\n";
	for (int i = 1; i < args; i++) {
		cout << "Program Argument " << i << ": " << qargs[i] << "\n";
	}
}

/*
Exercise 6
A sample filter program called search1, which outputs lines and the relevant
line numbers for lines containing the search pattern "ei", was introduced in this
chapter.
Modify the program to produce a useful tool called search, to which you can
pass any search pattern via the command line.The program should issue an
error message and terminate if the command line does not contain a search
string. Use the standard function strstr().
Sample call:
search Shanghai < news.txt
Exercise 7
The following frequency was observed during an examination of the relationship
between age and blood pressure for 300 males.
Write a function that calculates the sums of the rows and columns in an int
matrix with three rows and five columns. Store the sums of the rows and
columns separately in a one-dimensional row or column array.
Arguments: The matrix, the row array, and the column array.
Return value: The sum of all the matrix elements.
To test the function, output the matrix, as shown in the graphic opposite
along with the computed sums in your main function.
*/