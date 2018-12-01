/***************************************
Author: Sam Pickell
Date: 9/27/2016
Resubmit Date: 10/10/2016
Time Spent: 1 hour and 20 minutes 
Purpose: Create a rational function 
		class that has a default
		constructor, single argument
		constructor, and two argument
		constructor. Simplify any
		fractions the user may give
		to the two argument constructor
Reason for Resubmit: Needed to include
		the limits header.
****************************************/

#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

class Rational 
{
public:
	Rational();
	Rational(int num);
	Rational(int num, int denom);
	friend ostream& operator<<(ostream& out, Rational right);
	

private:
	//int data;
	int numerator;
	int denominator;
	int find_gcd(int x, int y);

};

void clear_keyboard_buffer();

int main()
{
	Rational fraction;
	int x, y, z;
	
	//Default Constructor
	cout << "Testing the default constructor: ";
	cout << fraction;
	cout << endl;
	cout << endl;

	//Single Argument Constructor
	cout << "Please enter the numerator for the single argument constructor: ";
	cin >> x;
	clear_keyboard_buffer();
	Rational fraction_2{ x };
	cout << endl;
	cout << "Testing the single argument constructor: ";
	cout << fraction_2;
	cout << endl;
	cout << endl;

	//Two Argument Constructor
	cout << "Please enter the numerator for the two argument constructor: ";
	cin >> y;
	clear_keyboard_buffer();
	cout << "Please enter the denominator for the two argument constructor: ";
	cin >> z;
	clear_keyboard_buffer();
	Rational fraction_3{ y, z };
	cout << endl;
	cout << "Testing the two argument constructor: ";
	cout << fraction_3;
	cout << endl;
	cout << endl;


	return 0;
}

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int num)
{
	numerator = num;
	denominator = 1;
}

Rational::Rational(int num, int denom)
{
	if (num == 0 && denom == 0)
	{
		numerator = 0;
		denominator = 0;

		return;
	}
	else if (denom == 0 && num != 0)
	{
		cout << "Cannot divide by 0!" << endl;
		exit(1);
	}
	else
	{
		int gcd = find_gcd(num, denom);

		num /= gcd;
		denom /= gcd;

		numerator = num;
		denominator = denom;

	}
}

int Rational::find_gcd(int x, int y)
{
	while (abs(x) != abs(y))
	{
		if (abs(x) > abs(y))
		{
			x = abs(x) - abs(y);
		}
		else
		{
			y = abs(y)  - abs(x);
		}
	}

	return x;
}

ostream& operator<<(ostream& out, Rational right)
{
	out << right.numerator << "/" << right.denominator;
	return out;
}

void clear_keyboard_buffer()
{
	cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
}