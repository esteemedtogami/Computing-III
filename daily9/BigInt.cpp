/**************************************
Author: Sam Pickell
Date: 10/16/2016
Time Spent: 2 hours and 50 minutes
Purpose: Overload *, >, and == operators
	so that they work with the BigInt.
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

BigInt operator+(BigInt left, BigInt right)
{
	
	int iResult_size = 0, leftover = 0;

	//If adding a negative, go to subtraction:
	if (right.isNegative == 1)
	{
		right.isNegative = 0;

		BigInt BIResult = right - left;

		BIResult.data.insert(0, 1, '-');

		return BIResult;
	}

	//When determining the size of the result string,
	// we don't want to include any +s or -s in the string
	if (left.data.at(0) == '+' || left.data.at(0) == '-')
	{
		left.data.erase(0, 1);
	}

	if (right.data.at(0) == '+' || right.data.at(0) == '-')
	{
		right.data.erase(0, 1);
	}

	//Determine size. +1 is in case numbers at element 
	// are larger than 9 and we need the extra 1. Also
	// fill the smaller string with leading 0s.
	if (left.data.length() >= right.data.length())
	{
		iResult_size += (left.data.length() + 1);
		for (int i = right.data.length(); i < left.data.length(); i++)
		{
			right.data.insert(0, 1, '0');
		}
	}
	else
	{
		iResult_size += (right.data.length() + 1);
		for (int i = left.data.length(); i < right.data.length(); i++)
		{
			left.data.insert(0, 1, '0');
		}
	}

	string sSum(iResult_size, '0');


	for (int i = (iResult_size - 2); i >= 0; i--)
	{
		int iLeft, iRight, iElement_sum;
		char cLeft, cRight, cElement_sum;

		//Get each number as a character
		cLeft = left.data.at(i);
		cRight = right.data.at(i);

		//Convert each character to an int
		iLeft = (cLeft - 48);
		iRight = (cRight - 48);

		iLeft += leftover;

		iElement_sum = iLeft + iRight;

		//If the element's sum is larger than 9
		if (iElement_sum > 9)
		{
			leftover = ((iElement_sum / 10));
			iElement_sum %= 10;
		}
		else
		{
			leftover = 0;
		}

		cElement_sum = (iElement_sum + 48);

		sSum.at(i + 1) = cElement_sum;

	}

	if (leftover > 0)
	{
		char c;
		c = (leftover + 48);
		sSum.at(0) = c;
	}
	
	if (sSum.at(0) == '0')
	{
		sSum.erase(0, 1);
	}
	
	BigInt BIResult{ sSum };

	

	return BIResult;
}

BigInt operator-(BigInt left, BigInt right)
{
	int iResult_size = 0, leftover = 0;

	//If subtracting a negative, go to subtraction:
	if (right.isNegative == 1)
	{
		right.isNegative = 0;
		
		BigInt BIResult2 = left + right;

		return BIResult2;
	}

	//When determining the size of the result string,
	// we don't want to include any +s or -s in the string
	if (left.data.at(0) == '+' || left.data.at(0) == '-')
	{
		left.data.erase(0, 1);
	}

	if (right.data.at(0) == '+' || right.data.at(0) == '-')
	{
		right.data.erase(0, 1);
	}

	//Determine size. +1 is in case numbers at element 
	// are larger than 9 and we need the extra 1. Also
	// fill the smaller string with leading 0s.
	if (left.data.length() >= right.data.length())
	{
		iResult_size += (left.data.length() + 1);
		for (int i = right.data.length(); i < left.data.length(); i++)
		{
			right.data.insert(0, 1, '0');
		}
	}
	else
	{
		iResult_size += (right.data.length() + 1);
		for (int i = left.data.length(); i < right.data.length(); i++)
		{
			left.data.insert(0, 1, '0');
		}
	}

	string sSub(iResult_size, '0');


	for (int i = (iResult_size - 2); i >= 0; i--)
	{
		int iLeft, iRight, iElement_sub;
		char cLeft, cRight, cElement_sub;

		//Get each number as a character
		cLeft = left.data.at(i);
		cRight = right.data.at(i);

		//Convert each character to an int
		iLeft = (cLeft - 48);
		iRight = (cRight - 48);

		iLeft -= leftover;

		//If the element's result is less than 0
		if (iLeft < iRight)
		{
			leftover = 1;
			iLeft += 10;
			iElement_sub = iLeft - iRight;
		}
		else
		{
			iElement_sub = iLeft - iRight;
		}

		cElement_sub = (iElement_sub + 48);

		sSub.at(i + 1) = cElement_sub;

	}

	int delete_zeroes = 0;

	while (sSub.at(delete_zeroes) == '0')
	{
		sSub.erase(0, 1);
	}

	BigInt BIResult{ sSub };



	return BIResult;
}

bool operator<(BigInt left, BigInt right)
{
	int iLeft, iRight;

	iLeft = stoi(left.data);
	iRight = stoi(right.data);

	return iLeft < iRight;
}

BigInt operator*(BigInt left, BigInt right)
{
	BigInt BIResult;

	//Remove leading sign
	if (left.data.at(0) == '+' || left.data.at(0) == '-')
	{
		left.data.erase(0, 1);
	}

	if (right.data.at(0) == '+' || right.data.at(0) == '-')
	{
		right.data.erase(0, 1);
	}

	// If one of the numbers is 0, then return a default BigInt
	if (left.data.at(0) == '0' || right.data.at(0) == '0')
	{
		return BIResult;
	}

	// If one of the numbers is 1, return the other number
	if (left.data.at(0) == '1' && left.data.length() == 1)
	{
		return right;
	}

	if (right.data.at(0) == '1' && right.data.length() == 1)
	{
		return left;
	}

	//Here's where the actual multiplication begins:

	BigInt BICounter;
	BigInt BIOne(1);

	while (BICounter.data != right.data)
	{
		BIResult = (left + BIResult);
		BICounter = (BIOne + BICounter);
	}










	// If one of the numbers is negative, the result is too
	if (left.isNegative == true || right.isNegative == true)
	{
		BIResult.data.insert(0, 1, '-');
		BIResult.isNegative = true;
	}

	// If multiplying two negative numbers, the answer is positive
	if (left.isNegative == true && right.isNegative == true)
	{
		BIResult.isNegative = false;
	}

	return BIResult;
}

bool operator>(BigInt left, BigInt right)
{
	int iLeft, iRight;

	iLeft = stoi(left.data);
	iRight = stoi(right.data);

	return iLeft > iRight;
}

bool operator==(BigInt left, BigInt right)
{
	int iLeft, iRight;

	iLeft = stoi(left.data);
	iRight = stoi(right.data);

	return iLeft == iRight;
}

void error_function(string x)
{
	cout << "Tried to construct invalid BigInt from string: " << endl;
	cout << x << endl;
	cout << "Exiting." << endl;
	exit(1);
}