/**************************************
Author: Sam Pickell
Date: 10/16/2016
Time Spent: 2 hours and 50 minutes 
Purpose: Overload *, >, and == operators
	so that they work with the BigInt.
**************************************/

#include "BigInt.h"


int main()
{
	
	BigInt a("100");
	BigInt b("100");
	cout << a << " * " << b << endl
		<< "Expecting 10000 got" << endl
		<< " " << a*b << endl;
	cout << endl;
	a = BigInt("1234");
	b = BigInt("-678");
	cout << a << " * " << b << endl
		<< "Expecting -836652 got" << endl
		<< " " << a*b << endl;
	cout << endl;

	cout << "Expecting 1, got: " << (BigInt("30") > BigInt("-1")) << endl;
	cout << "Expecting 1, got: " << (BigInt("-1") == BigInt("-1")) << endl;
	
	/*a = BigInt("-123456789012345678901234567890");
	b = BigInt("-987654321");
	cout << a << " * " << b << endl
		<< "Expecting 121932631124828532112482853211126352690 got" << endl
		<< " " << a*b << endl;*/




	return 0;
}

