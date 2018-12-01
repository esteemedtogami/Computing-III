/**************************************
Author: Sam Pickell
Date: 10/6/2016
Time Spent: 1 hour and 37 minutes
Purpose: Start making a BigInt class
that internally stores integers
as a string.

***Note: The use of chapter 9 in the
textbook was necessary to find
out how to use the functions in
the string library.
**************************************/

#ifndef BIG_INT_H
#define BIG_INT_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class BigInt
{
public:
	BigInt(); // Initializes the BigInt to zero.
	BigInt(int x); //Initializes the BigInt to have the same value as x
	explicit BigInt(string x);//Initalizes the BigInt to have the value of the given string BUT
							  //must check that the string is valid or exit(1) otherwise.
	friend ostream& operator<<(ostream& out, const BigInt& right);
private:
	string data;
	bool isNegative;
};

void error_function(string x);

#endif
