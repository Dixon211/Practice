#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Exercise 1
	The sample program fcopy1, which copies a file to the screen or to a second
	file, was introduced in this chapter.Write a program named fcopy to enhance
	fcopy1 as follows:
		■ If the program is launched without any arguments, it does not issue an
			error message and terminate but requests user input for the names of the
			source and target files. If an empty string is given as the name of the target file, that is, the Return key is pressed, the source file is displayed on
			screen.

		■ If the command line or the user dialog contains valid source and target
			file names, a binary copy operation is performed.

		■ Copy the data block by block with the read() and write() methods.
			The default block size is 1024 bytes.

		■ The copy() function returns false if an error occurs while copying and
			true in all other cases.
			Also refer to the notes on the opposite page.
*/


int getinput(string* file, string* targetlocation, fstream* filestream) {
	string temp;

	cout << "Please supply original file: ";
	while (true) {
		filestream->clear();
		cin >> temp;
		cout << "\n";

		filestream->open(temp);
		if (filestream->is_open()) {
			*file = temp;
			filestream->close();
			break;
		}
		else {
			cout << "File unable to be accessed please try again: ";
		}
	}
	
	cout << "Please supply target file: ";
	while (true) {
		filestream->clear();
		cin >> temp;
		cout << "\n";

		filestream->open(temp);
		if (filestream->is_open()) {
			*targetlocation = temp;
			filestream->close();
			break;
		}
		else {
			cout << "File unable to be accessed please try again: ";
		}
	}

	filestream->clear();
}


int main(int args, char** chwargs, char** env) //** denotes a list of pointers
{
	cout << "Program Running: " << chwargs[0] << "\n";
	cout << "Arguments supplied: " << args-1 << "\n";

	fstream file, *strptr;
	fstream::pos_type size;
	strptr = &file;

	string fileloc, * fptr, targetloc, * trgt;
	fptr = &fileloc; //remember pointers need a reference. Cannot be assigned to variable.
	trgt = &targetloc;

	char* memblock;


	//check args amount
	switch (args) {
		case 1:
			getinput(fptr, trgt, strptr);
			break;
		case 3:
			fileloc = chwargs[1];
			targetloc = chwargs[2];
			break;
		default:
			cout << "Error: Please Supply a file and a target location\n";
			cout << "Ex: fcopy C:\\Users\\<filename> C:\\Users\\<username>\\Documents\n";
	}

	cout << "original file: " << *fptr << "\n";
	cout << "target location: " << *trgt << "\n";


	file.open(*fptr, ios::in | ios::binary | ios::ate);
	if (file.is_open()) {
		size = file.tellg(); //tellg returns current pointer position in the input stream
		file.seekg(0, ios::beg); //return pointer to the beginning to start reading
		memblock = new char[size]; //store in memory, size is equal to total file size, **DONT USE FOR HUGE FILES**
		file.read(memblock, size); //store in memblock, store all data
		file.close();
		file.clear();
	} else {
		cout << "ERROR: unable to get input from original file\n";
		return 1;
	}

	file.open(*trgt, ios::out | ios::binary);
	if (file.is_open()) {
		file.write(memblock, size);
		file.close();
		file.clear();
	}
	else {
		cout << "Error: unable to write output to target file\n";
		return 1;
	}

	cout << "Transfer Complete!!\n\n";
	return 0;

}