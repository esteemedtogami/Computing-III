/***************************************
Author: Sam Pickell
Date: 9/29/2016
Resubmit Date: 10/10/2016
Time Spent: 2 hours and 10 minutes
Purpose: Overload arithmetic, boolean,
		and increment operators to
		work with the rational class.
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
	friend Rational operator+(Rational left, Rational right);
	friend Rational operator-(Rational left, Rational right);
	friend Rational operator*(Rational left, Rational right);
	friend Rational operator/(Rational left, Rational right);

	bool friend operator<(Rational left, Rational right);
	bool friend operator>(Rational left, Rational right);
	bool friend operator<=(Rational left, Rational right);
	bool friend operator>=(Rational left, Rational right);
	bool friend operator==(Rational left, Rational right);
	bool friend operator!=(Rational left, Rational right);

	Rational& operator++();
	Rational& operator++(int);
	Rational& operator--();
	Rational& operator--(int);

public:
	int numerator = data;
	int denominator = data;

private:
	int data;
	int find_gcd(int x, int y);
	double value;

};

void output(Rational fraction);
void arithmetic_test(Rational frac_1, Rational frac_2);
void boolean_test(Rational frac_1, Rational frac_2);
void increment_test(Rational frac_1);
void clear_keyboard_buffer();

int main()
{
	int num_1, denom_1, num_2, denom_2;

	cout << "Please enter the first numerator: ";
	cin >> num_1;
	clear_keyboard_buffer();
	cout << "Please enter the first denominator: ";
	cin >> denom_1;
	clear_keyboard_buffer();
	Rational frac_1{ num_1, denom_1 };
	cout << endl;

	cout << "Please enter the second numerator: ";
	cin >> num_2;
	clear_keyboard_buffer();
	cout << "Please enter the second denominator: ";
	cin >> denom_2;
	clear_keyboard_buffer();
	Rational frac_2{ num_2, denom_2 };
	cout << endl;

	//Arithmetic Operations
	arithmetic_test(frac_1, frac_2);

	//Boolean Operations
	boolean_test(frac_1, frac_2);

	//Incrementation Operations
	increment_test(frac_1);

	return 0;
}

Rational::Rational()
{
	numerator = 0;
	denominator = 1;

	value = (static_cast<double> (numerator)) / denominator;
}

Rational::Rational(int num)
{
	numerator = num;
	denominator = 1;

	value = (static_cast<double> (numerator)) / denominator;
}

Rational::Rational(int num, int denom)
{
	if (num == 0 && denom  == 0)
	{
		numerator = 0;
		denominator = 0;

		value = (static_cast<double> (numerator)) / denominator;

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

		value = (static_cast<double> (numerator)) / denominator;
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
			y = abs(y) - abs(x);
		}
	}
	return x;
}

ostream& operator<<(ostream& out, Rational right)
{
	out << right.data;
	return out;
}

void output(Rational fraction)
{
	cout << fraction.numerator << "/" << fraction.denominator << endl;
}

Rational operator+(Rational left, Rational right)
{
	int added_num, added_denom;
	added_num = ((left.numerator * right.denominator) + (left.denominator * right.numerator));
	added_denom = left.denominator * right.denominator;

	if (added_num == 0 || added_denom == 0)
	{
		Rational added{ 0, 0};
		return added;
	}
	else
	{
		Rational added{ added_num, added_denom };
		return added;
	}
}
Rational operator-(Rational left, Rational right)
{
	int subbed_num, subbed_denom;
	subbed_num = ((left.numerator * right.denominator) - (left.denominator * right.numerator));
	subbed_denom = left.denominator * right.denominator;

	if (subbed_num == 0 || subbed_denom == 0)
	{
		Rational subbed{ 0, 0 };
		return subbed;
	}
	else
	{
		Rational subbed{ subbed_num, subbed_denom };
		return subbed;
	}
}
Rational operator*(Rational left, Rational right)
{
	int mult_num, mult_denom;
	mult_num = left.numerator * right.numerator;
	mult_denom = left.denominator * right.denominator;

	Rational mult{ mult_num, mult_denom };
	return mult;
}
Rational operator/(Rational left, Rational right)
{
	int div_num, div_denom;
	div_num = left.numerator * right.denominator;
	div_denom = left.denominator * right.numerator;

	Rational div{ div_num, div_denom };
	return div;
}

bool operator<(Rational left, Rational right)
{
	return left.value < right.value;
}
bool  operator>(Rational left, Rational right)
{
	return left.value > right.value;
}
bool  operator<=(Rational left, Rational right)
{
	return left.value <= right.value;
}
bool  operator>=(Rational left, Rational right)
{
	return left.value >= right.value;
}
bool  operator==(Rational left, Rational right)
{
	return left.value == right.value;
}
bool  operator!=(Rational left, Rational right)
{
	return left.value != right.value;
}

Rational& Rational::operator++()
{
	value += 1.0;
	numerator += denominator;
	return *this;
}
Rational& Rational::operator++(int)
{
	cout << numerator << "/" << denominator << endl;
	value += 1.0;
	numerator += denominator;
	return *this;
}
Rational& Rational::operator--()
{
	value -= 1.0;
	numerator -= denominator;
	return *this;
}
Rational& Rational::operator--(int)
{
	cout << numerator << "/" << denominator << endl;;
	value -= 1.0;
	numerator -= denominator;
	return *this;
}

void arithmetic_test(Rational frac_1, Rational frac_2)
{
	cout << "The fractions added equate to: ";
	output(frac_1 + frac_2);
	cout << "The fractions subtracted equate to: ";
	output(frac_1 - frac_2);
	cout << "The fractions multiplied equate to: ";
	output(frac_1 * frac_2);
	cout << "The fractions divided equate to: ";
	output(frac_1 / frac_2);
	cout << endl;
}
void boolean_test(Rational frac_1, Rational frac_2)
{
	cout << "Fraction 1 is less than Fraction 2: " << endl;
	if (frac_1 < frac_2)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Fraction 1 is greater than Fraction 2: " << endl;
	if (frac_1 > frac_2)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Fraction 1 is less than or equal to Fraction 2: " << endl;
	if (frac_1 <= frac_2)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Fraction 1 is greater than or equal to Fraction 2: " << endl;
	if (frac_1 >= frac_2)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Fraction 1 is equivalent to Fraction 2: " << endl;
	if (frac_1 == frac_2)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Fraction 1 is not equivalent to Fraction 2: " << endl;
	if (frac_1 != frac_2)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}

	cout << endl;
}
void increment_test(Rational frac_1)
{
	cout << "++Fraction 1 is: ";
	output(++frac_1);
	cout << "Fraction 1++ is: ";
	frac_1++;
	cout << "(Side effect): ";
	output(frac_1);
	cout << "--Fraction 1 is: ";
	output(--frac_1);
	cout << "Fraction 1-- is: ";
	frac_1--;
	cout << "(Side effect): ";
	output(frac_1);
	cout << endl;
}


void clear_keyboard_buffer()
{
	cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
}