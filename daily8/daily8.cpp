/**************************************
Author: Sam Pickell
Date: 10/9/2016
Time Spent: 4 hours and 25 minutes
Purpose: Modify the BigInt class so
	that the operators +, -, and <
	work with BigInts.
**************************************/

#include "BigInt.h"


int main()
{
	BigInt a("-1000");
	BigInt b("+999");
	cout << b << "+" << a << endl << "= " << b + a << endl;
	a = BigInt("1000");
	b = BigInt("999");
	cout << a << "-" << b << endl << "= " << a - b << endl;
	a = BigInt("99999999999999999999999999999999999999999999999999999999999999999999999999999999");
	b = BigInt("1");
	cout << " " << a << "+" << b << endl << "= " << a + b << endl;
	cout << "Expecting 1, got: " << (BigInt("-30") < BigInt("-1")) << endl;
	cout << "Expecting 0, got: " << (BigInt("30") < BigInt("-1")) << endl;
	cout << "Expecting 1, got: " << (BigInt("30") < BigInt("300")) << endl;
	cout << "Expecting 0, got: " << (BigInt("-30") < BigInt("-300")) << endl;
	return 0;
}

