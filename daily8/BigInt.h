

#ifndef BIG_INT_H
#define BIG_INT_H

#include <iostream>
/**************************************
Author: Sam Pickell
Date: 10/9/2016
Time Spent: 4 hours and 25 minutes
Purpose: Modify the BigInt class so
that the operators +, -, and <
work with BigInts.
**************************************/

#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;

class BigInt
{
public:
	BigInt(); // Initializes the BigInt to zero.
	BigInt(int x); //Initializes the BigInt to have the same value as x
	explicit BigInt(string x);//Initalizes the BigInt to have the value of the given string BUT
							  //must check that the string is valid or exit(1) otherwise.
	friend ostream& operator<<(ostream& out, const BigInt& right);
	friend BigInt operator+(BigInt left, BigInt right);
	friend BigInt operator-(BigInt left, BigInt right);
	bool friend operator<(BigInt left, BigInt right);


private:
	string data;
	bool isNegative;
};

void error_function(string x);

#endif