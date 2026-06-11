#pragma once
/*
Please write
	a. the macro ABS, which returns the absolute value of a number,
	b. the macro MAX, which determines the greater of two numbers.

In both cases use the conditional operator ?: .

Add these macros and other macros from this chapter to the header file
myMacros.h and then test the macros.

If your system supports screen control macros, also add some screen control
macros to the header. For example, you could write a macro named
COLOR(f,b) to define the foreground and background colors for the following
output.
*/

#define ABS(number) ((number)<(0) ? (-number) : (number)) // ?: is the conditional operator basically its func_name(parameter(s)) (expression ? iftrue : iffalse)

#define MAX(a,b) ((a)>(b) ? (a) : (b))

