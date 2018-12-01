/*********************************************
Author: Sam Pickell
Date: 9/17/2016
Time Spent: 40 minutes
Purpose: Print out and sum up all prime
		numbers in a specified range. 
Reason for resubmit: My previous submission
		counted negative numbers and the 
		number 1 as prime.
*********************************************/

#include <iostream>

using namespace std;

int isItPrime(int sum, int maxNum, int counter);

int main()
{
	int minNum, maxNum, counter, sum = 0;

	cout << "Enter starting value: ";
	cin >> minNum;
	cout << "Enter ending value: ";
	cin >> maxNum;

	counter = minNum;

	sum += isItPrime(sum, maxNum, counter);

	
	cout << "The sum of all the numbers is: " << sum << endl;


	return 0;
}

int isItPrime(int sum, int maxNum, int counter)
{
	while (counter <= maxNum)
	{
		if ((counter == 2) || (counter == 3) || (counter == 5))
		{
			cout << counter << endl;
			sum += counter;
		}
		else if (counter < 2)
		{

		}
		else
		{
			if ((counter % 2 == 0) || (counter % 3 == 0) || (counter % 5 == 0))
			{

			}
			else
			{
				cout << counter << endl;
				sum += counter;
			}
		}

		counter++;
	}

	return sum;
}