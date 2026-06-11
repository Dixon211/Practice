/*
Exercise:
	A program needs a class to represent the date.
		■ Define the class Date for this purpose using three integral data members
			for day, month, and year.Additionally, declare the following methods:
				void init( int month, int day, int year);
				void init(void);
				void print(void);
			Store the definition of the class Date in a header file.

		■ Implement the methods for the class Date in a separate source file:
			1. The method print() outputs the date to standard output using the
			format Month-Day-Year.
			2. The method init() uses three parameters and copies the values
			passed to it to corresponding members.A range check is not required
			at this stage, but will be added later.
			3. The method init() without parameters writes the current date to the
			corresponding members.

			The structure tm and sample calls to this function are included opposite.The type time_t is defined as long in ctime.
			The function time() returns the system time expressed as a number of seconds and writes this value to the variable referenced by ptrSec. This value can be passed to the function localtime() that
			converts the number of seconds to the local type tm date and returns
			a pointer to this structure.

		■ Test the class Date using an application program that once more is stored
		in a separate source file.To this end, define two objects for the class and
		display the current date. Use object assignments and—as an additional
		exercise—references and pointers to objects.
*/
#pragma once
#include <iostream>
#include <chrono>

using namespace std;

//Class Declaration
class Date 
{
	private:
		int year;
		unsigned day, month;

	public:
		void init(unsigned month, unsigned day, int year);
		void init(void);
		void print(void);
};

//Method Definitions
void Date::init(unsigned month, unsigned day, int year) 
{
	this->month = month; //technically this is a pointer pointing to the internal variables same as python's self.<variablename> for updating class variables for specific classes
	this->day = day;
	this->year = year;
}

void Date::init(void)
{
	//used <chrono> instead of <ctime> because <ctime> is depreciated
	chrono::system_clock::time_point now = chrono::system_clock::now();
	chrono::year_month_day ymd = chrono::floor<chrono::days>(now);
	this->month = static_cast<unsigned>(ymd.month());
	this->day = static_cast<unsigned>(ymd.day());
	this->year = static_cast<int>(ymd.year());
}

void Date::print(void) 
{
	cout << "The Date is " << month << "-" << day << "-" << year;
}