/**************************************
Author: Sam Pickell
Date: 10/27/2016
Time Spent: 1 hour and 50 minutes
Purpose: Overload the / operator to 
	work with BigInts
**************************************/

#include "BigInt.h"


int main()
{

	BigInt a("2377847584");
	BigInt b("4875634");
	cout << a+b << endl;
	cout << a - b << endl;
	//cout << a * b << endl;
	cout << a / b << endl;
	
	cout << endl;




	return 0;
}

