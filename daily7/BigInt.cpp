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


BigInt::BigInt()
{
	data = "0";
	isNegative = 0;
}

BigInt::BigInt(int x)
{
	data = to_string(x);
	if (x < 0)
	{
		isNegative = 1;
	}
	else
	{
		isNegative = 0;
	}
}

BigInt::BigInt(string x)
{
	string temp_string;
	bool hasOperator = 0;

	if (x.at(0) == '+')
	{
		isNegative = 0;
		hasOperator = 1;
	}
	else if (x.at(0) == '-')
	{
		isNegative = 1;
		hasOperator = 1;
		temp_string.push_back(x.at(0));
	}
	else if (x.at(0) == ' ')
	{

	}
	else if (x.at(0) >= 48 && x.at(0) <= 57) 
	{
		temp_string.push_back(x.at(0));
	}
	else
	{
		error_function(x);
	}

	for (int i = 1; i < x.length(); i++)
	{
		if (x.at(i) == ' ')
		{
			if (x.at(i - 1) >= 48 && x.at(i - 1) <= 57) 
			{
				break;
			}
			else if (x.at(i - 1) == '+' || x.at(i - 1) == '-')
			{
				error_function(x);
			}
			else
			{

			}
		}
		else if (x.at(i) == '+')
		{
			if (hasOperator == 1)
			{
				error_function(x);
			}
			else if (hasOperator == 0)
			{
				isNegative = 0;
				hasOperator = 1;
				temp_string.push_back(x.at(i));
			}
		}
		else if (x.at(i) == '-')
		{
			if (hasOperator == 1)
			{
				error_function(x);
			}
			else if (hasOperator == 0)
			{
				isNegative = 1;
				hasOperator = 1;
				temp_string.push_back(x.at(i));
			}
		}
		else if (x.at(i) >= 48 && x.at(i) <= 57)
		{
			temp_string.push_back(x.at(i));
		}
		else
		{
			error_function(x);
		}
	}
	data = temp_string;
}

ostream& operator<<(ostream& out, const BigInt& right)
{
	out << right.data;

	return out;
}

void error_function(string x)
{
	cout << "Tried to construct invalid BigInt from string: " << endl;
	cout << x << endl;
	cout << "Exiting." << endl;
	exit(1);
}