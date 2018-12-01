/**************************************
Author: Sam Pickell
Date: 9/20/2016
Resubmit Date: 10/1/2015
Time Spent: 2 hours and 45 minutes 
Purpose: Create a month class
		that stores the month 
		as an integer and can take
		input in multiple ways and
		can display the month in
		multiple ways.

Reason for Resubmit: Needed to make my
		const ints capital and replace the 
		if statements in my single argument
		consturctor with the set_month()
		function.
**************************************/


#include <iostream>
#include <cstdlib>

using namespace std;

const int JAN = 1, FEB = 2, MAR = 3, APR = 4, MAY = 5, JUN = 6,
JUL = 7, AUG = 8, SEP = 9, OCTOBER = 10, NOV = 11, DECEMBER = 12;

class Month
{
public:
	Month();
	Month(char letter_1, char letter_2, char letter_3);
	Month(int iMonth);

	//mutator functions
	void set_month(int iMonth);

	//accessor functions

	//other functions
	void output_as_char();
	void output_as_int();
	void output_entire_name();
	Month next_month();

private:
	int month;
};

void letters_arent_month(char letter_1, char letter_2, char letter_3);
void set_month_menu();
void initialize_by_number();
void initialize_by_characters();
void view_month_menu(Month& test_month);

int main()
{
	cout << "How would you like to set the month?" << endl;
	set_month_menu();


	cout << endl;
	cout << "This concludes the driver program. Thank you!" << endl;

	return 0;
}

Month::Month()
{
	month = JAN;
}

Month::Month(char letter_1, char letter_2, char letter_3)
{
	if (letter_1 == 'j' || letter_1 == 'J')
	{
		if (letter_2 == 'a' || letter_2 == 'A')
		{
			if (letter_3 == 'n' || letter_3 == 'N')
			{
				month = JAN;
			}
			else
			{
				letters_arent_month(letter_1, letter_2, letter_3);
			}
		}
		else if (letter_2 == 'u' || letter_2 == 'U')
		{
			if (letter_3 == 'n' || letter_3 == 'N')
			{
				month = JUN;
			}
			else if (letter_3 == 'l' || letter_3 == 'L')
			{
				month = JUL;
			}
			else
			{
				letters_arent_month(letter_1, letter_2, letter_3);
			}
		}
		else
		{
			letters_arent_month(letter_1, letter_2, letter_3);
		}
	}
	else if (letter_1 == 'f' || letter_1 == 'F')
	{
		if (letter_2 == 'e' || letter_2 == 'E')
		{
			if (letter_3 == 'b' || letter_3 == 'B')
			{
				month = FEB;
			}
			else
			{
				letters_arent_month(letter_1, letter_2, letter_3);
			}
		}
		else
		{
			letters_arent_month(letter_1, letter_2, letter_3);
		}
	}
	else if (letter_1 == 'm' || letter_1 == 'M')
	{
		if (letter_2 == 'a' || letter_2 == 'A')
		{
			if (letter_3 == 'r' || letter_3 == 'R')
			{
				month = MAR;
			}
			else if (letter_3 == 'y' || letter_3 == 'Y')
			{
				month = MAY;
			}
			else
			{
				letters_arent_month(letter_1, letter_2, letter_3);
			}
		}
		else
		{
			letters_arent_month(letter_1, letter_2, letter_3);
		}
	}
	else if (letter_1 == 'a' || letter_1 == 'A')
	{
		if (letter_2 == 'p' || letter_2 == 'P')
		{
			if (letter_3 == 'r' || letter_3 == 'R')
			{
				month = APR;
			}
			else
			{
				letters_arent_month(letter_1, letter_2, letter_3);
			}
		}
		else if (letter_2 == 'u' || letter_2 == 'U')
		{
			if (letter_3 == 'g' || letter_3 == 'G')
			{
				month = AUG;
			}
			else
			{
				letters_arent_month(letter_1, letter_2, letter_3);
			}
		}
		else
		{
			letters_arent_month(letter_1, letter_2, letter_3);
		}
	}
	else if (letter_1 == 's' || letter_1 == 'S')
	{
		if (letter_2 == 'e' || letter_2 == 'E')
		{
			if (letter_3 == 'p' || letter_3 == 'P')
			{
				month = SEP;
			}
			else
			{
				letters_arent_month(letter_1, letter_2, letter_3);
			}
		}
		else
		{
			letters_arent_month(letter_1, letter_2, letter_3);
		}
	}
	else if (letter_1 == 'o' || letter_1 == 'O')
	{
		if (letter_2 == 'c' || letter_2 == 'C')
		{
			if (letter_3 == 't' || letter_3 == 'T')
			{
				month = OCTOBER;
			}
			else
			{
				letters_arent_month(letter_1, letter_2, letter_3);
			}
		}
		else
		{
			letters_arent_month(letter_1, letter_2, letter_3);
		}
	}
	else if (letter_1 == 'n' || letter_1 == 'N')
	{
		if (letter_2 == 'o' || letter_2 == 'O')
		{
			if (letter_3 == 'v' || letter_3 == 'V')
			{
				month = NOV;
			}
			else
			{
				letters_arent_month(letter_1, letter_2, letter_3);
			}
		}
		else
		{
			letters_arent_month(letter_1, letter_2, letter_3);
		}
	}
	else if (letter_1 == 'd' || letter_1 == 'D')
	{
		if (letter_2 == 'e' || letter_2 == 'E')
		{
			if (letter_3 == 'c' || letter_3 == 'C')
			{
				month = DECEMBER;
			}
			else
			{
				letters_arent_month(letter_1, letter_2, letter_3);
			}
		}
		else
		{
			letters_arent_month(letter_1, letter_2, letter_3);
		}
	}
	else
	{
		letters_arent_month(letter_1, letter_2, letter_3);
	}
}
Month::Month(int iMonth)
{
	set_month(iMonth);
}
void Month::output_as_char()
{
	if (month == JAN)
	{
		cout << "JAN" << endl;
	}
	else if (month == FEB)
	{
		cout << "FEB" << endl;
	}
	else if (month == MAR)
	{
		cout << "MAR" << endl;
	}
	else if (month == APR)
	{
		cout << "APR" << endl;
	}
	else if (month == MAY)
	{
		cout << "MAY" << endl;
	}
	else if (month == JUN)
	{
		cout << "JUN" << endl;
	}
	else if (month == JUL)
	{
		cout << "JUL" << endl;
	}
	else if (month == AUG)
	{
		cout << "AUG" << endl;
	}
	else if (month == SEP)
	{
		cout << "SEP" << endl;
	}
	else if (month == OCTOBER)
	{
		cout << "Oct" << endl;
	}
	else if (month == NOV)
	{
		cout << "NOV" << endl;
	}
	else if (month == DECEMBER)
	{
		cout << "Dec" << endl;
	}
	else
	{
		cout << "Err" << endl;
		exit(1);
	}
}
void Month::output_as_int()
{
	cout << month << endl;
}
void Month::output_entire_name()
{
	if (month == JAN)
	{
		cout << "January" << endl;
	}
	else if (month == FEB)
	{
		cout << "February" << endl;
	}
	else if (month == MAR)
	{
		cout << "March" << endl;
	}
	else if (month == APR)
	{
		cout << "April" << endl;
	}
	else if (month == MAY)
	{
		cout << "May" << endl;
	}
	else if (month == JUN)
	{
		cout << "June" << endl;
	}
	else if (month == JUL)
	{
		cout << "July" << endl;
	}
	else if (month == AUG)
	{
		cout << "August" << endl;
	}
	else if (month == SEP)
	{
		cout << "September" << endl;
	}
	else if (month == OCTOBER)
	{
		cout << "October" << endl;
	}
	else if (month == NOV)
	{
		cout << "November" << endl;
	}
	else if (month == DECEMBER)
	{
		cout << "December" << endl;
	}
	else
	{
		cout << "Error" << endl;
		exit(1);
	}
}
void Month::set_month(int iMonth)
{
	if (iMonth >= JAN && iMonth <= DECEMBER)
	{
		month = iMonth;
	}
	else
	{
		cout << "The entered number was not between 1 and 12." << endl;
		exit(1);
	}
}
Month Month::next_month()
{
	int next_month;

	if (month < DECEMBER)
	{
		next_month = month + JAN;
		
	}
	else if (month == DECEMBER)
	{
		next_month = JAN;
	}

	cout << next_month << endl;

	return next_month;
}

void letters_arent_month(char letter_1, char letter_2, char letter_3)
{
	cout << "'" << letter_1 << letter_2 << letter_3 << "' does not represent a month." << endl;
	exit(1);
}
void set_month_menu()
{
	int iSelect; 

	cout << "(1) By number" << endl;
	cout << "(2) By first three letters" << endl;
	cout << endl;
	cout << "Selection: ";
	cin >> iSelect;

	
	for (;;)
	{
		if (iSelect == 1 || iSelect == 2)
		{
			break;
		}
		else
		{
			cout << "Error. Please change your selection." << endl;
			cout << "Select month by... " << endl;
			cout << "(1) By number" << endl;
			cout << "(2) By first three letters" << endl;
			cout << endl;
			cout << "Selection: ";
			cin >> iSelect;
		}
	}
	

	if (iSelect == 1)
	{
		cout << endl;
		initialize_by_number();
	}
	else if (iSelect == 2)
	{
		cout << endl;
		initialize_by_characters();
	}
	
}

void initialize_by_number()
{
	int iMonth;
	cout << "Please enter a number that corresponds to a month: ";
	cin >> iMonth;

	while (iMonth < 1 || iMonth > 12)
	{
		cout << "Error, you have entered a number that is out of bounds." << endl;
		cout << "Please enter a number that corresponds to a month (1-12): ";
		cin >> iMonth;
	}

	Month test_month{ iMonth };

	cout << "How would you like to view the month?" << endl;
	view_month_menu(test_month);
}
void initialize_by_characters()
{
	char letter_1, letter_2, letter_3;

	cout << "Enter the first three letters of a month." << endl;
	cout << "***NOTE: If you enter something unreasonable ahead, the program will end." << endl;
	cout << "Enter letter 1: ";
	cin >> letter_1;
	cout << "Enter letter 2: ";
	cin >> letter_2;
	cout << "Enter letter 3: ";
	cin >> letter_3;

	Month test_month{ letter_1, letter_2, letter_3 };

	cout << "How would you like to view the month?" << endl;
	view_month_menu(test_month);
}

void view_month_menu(Month& test_month)
{
	int iSelect;

	cout << "(1) By number" << endl;
	cout << "(2) By first three letters" << endl;
	cout << "(3) By entire name" << endl;
	cout << endl;
	cout << "Selection: ";
	cin >> iSelect;

	for (;;)
	{
		if (iSelect == 1 || iSelect == 2 || iSelect == 3)
		{
			break;
		}
		else
		{
			cout << "Error. Please change your selection." << endl;
			cout << "Select month by... " << endl;
			cout << "(1) By number" << endl;
			cout << "(2) By first three letters" << endl;
			cout << "(3) By entire name" << endl;
			cout << endl;
			cout << "Selection: ";
			cin >> iSelect;
		}
	}
	

	cout << endl;

	if (iSelect == 1)
	{
		test_month.output_as_int();
	}
	else if (iSelect == 2)
	{
		test_month.output_as_char();
	}
	else if (iSelect == 3)
	{
		test_month.output_entire_name();
	}

	cout << "The following month is: ";
	test_month.next_month();

}