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

#include "BigInt.h"


int main()
{
	BigInt x;
	cout << x << endl;
	x = BigInt(42);
	cout << x << endl;
	x = BigInt("    -123456789012345678901234567890 and more stuff");
	cout << x << endl;
	x = BigInt("+-4848484848484848");
	cout << x << endl;
	return 0;
}

