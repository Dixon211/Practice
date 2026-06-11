#pragma once

/*
Notes:
	ifstream allows for file reading
	ostream allows for file writing
	fstream supports both read and write

	modes for file classes:
		ios:in = Opens an existing file for file input
		ios::out = Opens a file for output, implies ios::trunc if not combined with ios::in, ios::app, or ios::ate
		ios::app = opens file for output at the end-of-file
		ios::trunc = An existing file is truncated to zero length
		ios::ate = open and seek to end immediately after opening. Without this flag, the satrting postion after opening is always at beginning-of-file.
		ios::binary = Perform input and output in binary mode

		ex:  fstream addresses("Address.fle", ios::out | ios::app)

	Easy Error Handling:
		if(!myfile)
		if(myfile.eof()) //checks end of file

	Checking File Status:
		myfile.is_open() = checks if file is open (duh)
		myfile.close() = close the file
*/

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

/*
Exercise 2
	a. Modify the sample program Pizza_w.cpp in this chapter to allow the
		user to add new pizza records to the four standard pizzas and store
		these records on file.

	b. Then write a program called Pizza_r.cpp, which displays the pizza
		menu, that is, outputs the contents of the pizza file.
*/

/*
Exercise 3
	Test the methods read() and write() in the Account class.To do so, write a
	program called Account_rw.cpp that
		■ initializes an array with account objects and stores the array in a file
		■ reads the contents of the file to a second array and displays the accounts
	in that array to allow you to check them.
	Use binary mode for read or write access to the file.
*/

/*
Exercise 4
	The program TelList, which was written as an exercise for Chapter 16, needs
	to be modified to allow telephone lists to be saved in a file.
	To allow this, first add the data members and methods detailed on the
	opposite page to TelList.The string filename is used to store the name of
	the file in use.The dirty flag is raised to indicate that the phone list has been
	changed but not saved.You will need to modify the existing methods append()
	and erase()to provide this functionality.

	The strings in the phone list must be saved as C strings in a binary file,
	allowing for entries that contain several lines.
	Add the following items to the application program menu:

		O = Open a file
			Read a phone list previously stored in a file.

		W = Save
			Save the current phone list in a file.

		U = Save as . . .
			Save the current phone list in a new file.

	Choosing one of these menu items calls one of the following methods as
	applicable: load(), save() or saveAs().These methods return true for a
	successful action and false otherwise.The user must be able to supply a file
	name for the save() method, as the list may not have been read from a file
	previously.

	If the phone list has been modified but not saved, the user should be
	prompted to save the current phone list before opening another file or
	terminating the program.
*/