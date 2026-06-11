/*
Exercise 2
	a. Modify the sample program Pizza_w.cpp in this chapter to allow the
		user to add new pizza records to the four standard pizzas and store
		these records on file.

	b. Then write a program called Pizza_r.cpp, which displays the pizza
		menu, that is, outputs the contents of the pizza file.
*/

// Pizza_W.cpp
// Demonstrating output of records block by block.
// ---------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define CLS system("cls")

using namespace std;

// Record structure:
struct Pizza { string name; float price; };
const int MAXCNT = 10;

Pizza pizzaMenu[MAXCNT] ={
{ "Pepperoni", 9.90F },
{ "White Pizza", 15.90F },
{ "Ham Pizza", 12.50F },
{ "Calzone", 14.90F } };

char response;
int cnt = 4;
string filepath = "C:\\Users\\Assoc\\pizzamenu.txt";
fstream filestrm;


//bool printtofile(const char* file, Pizza Menu[],int menusize, fstream &stream) {
//	stream.clear();
//	stream.open(file, ios::out | ios::binary);
//
//	if (!stream.is_open()) {
//		cerr << "Could not open file: " << file;
//		return false;
//	}
//
//	for (int i = 0; i < menusize; i++) {
//
//	}
//
//
//
//
//}


void displaymenu(Pizza pizzaMenu[]) {
	CLS;
	char header[] = " * * * P I Z Z A P R O N T O * * *\n\n";
	cout << header;
	cout << "Current Pizza Menu:\n";
	for (int i = 0; i < cnt; i++) {
		printf("%s \t\t$%.2f\n", pizzaMenu[i].name.c_str(), pizzaMenu[i].price); //printf allows for f-strings that I like .c_str() turns a string into a char array which is so helpful
	}
	cout << "\nOptions:\n";
	if (cnt < 10) { cout << "\ta : Add a pizza to the menu (max 10)\n"; }
	cout << "\tp : print to file\n";
	cout << "\tq : Quit\n";
}

void addpizza(Pizza pizzaMenu[]) {
	string stemp;
	float ftemp;

	cin.ignore(); //resets the cin buffer

	cout << "\nName of new pizza: ";
	getline(cin, stemp); //need to use getline for strings

	cout << "\nPrice of new pizza: ";
	cin >> ftemp;

	pizzaMenu[cnt] = { stemp, ftemp };
	cnt++;

	displaymenu(pizzaMenu);
}


int main(int args, char* chwargs[]) // To write records.
{
	displaymenu(pizzaMenu);
	while (true) {
		cin >> response;
		switch (response) {
		case 'a':
			if (cnt < 10) { addpizza(pizzaMenu); }
			else { cout << "Pizza Menu is full, cannot add another\n"; }
			break;
		case 'p':
			cout << "you pressed P, thanks!\n";
			//printtofile();
			break;
		case 'q':
			exit(0);
		default:
			cout << "please choose a, p, q\n";
		}
	}
}

/*
		cout << header << endl;
	// To write data into the file:
	int exitCode = 0;
	ofstream outFile(pizzaFile, ios::out | ios::binary);
	if (!outFile)
	{
		cerr << "Error opening the file!" << endl;
		exitCode = 1;
	}
	else
	{
		for (int i = 0; i < cnt; ++i) {
			if (!outFile.write((char*)&pizzaMenu[i],
				sizeof(Pizza)))
			{
				cerr << "Error writing!" << endl;
				exitCode = 2;
			}
		}

	}
	if (exitCode == 0)
		cout << "\nData has been added to file "
		<< pizzaFile << "\n" << endl;
	return exitCode;
*/