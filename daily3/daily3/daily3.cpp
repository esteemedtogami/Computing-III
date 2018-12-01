/*************************************
Author: Sam Pickell
Date: 9/17/2016
Time Spent: 2 hours and 2 minutes
Purpose: Take any temperature in
	degrees kelvin, fahrenheit, or
	celsius, store that temperature
	in degrees kelvin, and then
	convert that stored temperature
	to any of the three types.
************************************/

#include <iostream>

using namespace std;

void magic_formula();

class Temperature
{
public:
	Temperature();

	//mutators
	void set_temp_kelvin(double temperature);
	void set_temp_fahrenheit(double temperature);
	void set_temp_celsius(double temperature);

	//accessors
	double get_temp_kelvin();
	double get_temp_fahrenheit();
	double get_temp_celsius();

	//other functions
	char check_for_errors(char& choose_temp_1);
	void display_converted_temp(char choose_temp_1, double user_temp);
	void display_converted_temp_2(char choose_temp_1, double user_temp);

private:
	double temp_kelvin;

};



int main()
{
	magic_formula();
	char choose_temp_1, choose_temp_2;
	double user_temp;
	Temperature temp;

	cout << "What scale are you using?" << endl;
	cout << "Please enter 'K' for Kelvin, 'F' for Fahrenheit, or 'C' for Celsius: ";
	cin >> choose_temp_1;
	temp.check_for_errors(choose_temp_1);
	cout << "Please enter the temperature: ";
	cin >> user_temp;
	temp.display_converted_temp(choose_temp_1, user_temp);

	cout << endl;
	
	cout << "What scale would you like to convert to?" << endl;
	cout << "Please enter 'K' for Kelvin, 'F' for Fahrenheit, or 'C' for Celsius: ";
	cin >> choose_temp_2;
	temp.check_for_errors(choose_temp_2);
	temp.display_converted_temp_2(choose_temp_2, user_temp);
	
	


	return 0;
}

void magic_formula()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
}

Temperature::Temperature()
{
	temp_kelvin = 0;
}

void Temperature::set_temp_kelvin(double temperature)
{
	temp_kelvin = temperature;
}
void Temperature::set_temp_fahrenheit(double temperature)
{
	temp_kelvin = (((5.0 / 9) * (temperature - 32)) + 273.15);
}
void Temperature::set_temp_celsius(double temperature)
{
	temp_kelvin = temperature + 273.15;
}

double Temperature::get_temp_kelvin()
{
	return temp_kelvin;
}
double Temperature::get_temp_fahrenheit()
{
	return ((temp_kelvin - 273.15) * ((9.0 / 5) + 32));
}
double Temperature::get_temp_celsius()
{
	return (temp_kelvin - 273.15);
}

char Temperature::check_for_errors(char& choose_temp_1)
{

	for (;;)
	{

		if (choose_temp_1 == 'K' || choose_temp_1 == 'k' || choose_temp_1 == 'F' ||
				choose_temp_1 == 'f' || choose_temp_1 == 'C' || choose_temp_1 == 'c')
		{
			break;
		}
		else
		{
			cout << "Error, you input something unreasonable." << endl;
			cout << "Please enter 'K' for Kelvin, 'F' for Fahrenheit, or 'C' for Celsius: ";
			cin >> choose_temp_1;
		}
	}

	return choose_temp_1;
}

void Temperature::display_converted_temp(char choose_temp_1, double user_temp)
{
	if (choose_temp_1 == 'K' || choose_temp_1 == 'k')
	{
		set_temp_kelvin(user_temp);
		cout << "Your original temperature of " << user_temp << " degrees Kelvin is now "
			<< temp_kelvin << " degrees Kelvin." << endl;
	}
	else if (choose_temp_1 == 'F' || choose_temp_1 == 'f')
	{
		set_temp_fahrenheit(user_temp);
		cout << "Your original temperature of " << user_temp << " degrees Fahrenheit is now "
			<< temp_kelvin << " degrees Kelvin." << endl;
	}
	else if (choose_temp_1 == 'C' || choose_temp_1 == 'c')
	{
		set_temp_celsius(user_temp);
		cout << "Your original temperature of " << user_temp << " degrees Celsius is now "
			<< temp_kelvin << " degrees Kelvin." << endl;
	}
}

void Temperature::display_converted_temp_2(char choose_temp_1, double user_temp)
{
	if (choose_temp_1 == 'K' || choose_temp_1 == 'k')
	{
		cout << "The stored temperature of " << temp_kelvin << " degrees Kelvin is now "
			<< get_temp_kelvin() << " degrees Kelvin." << endl;
	}
	else if (choose_temp_1 == 'F' || choose_temp_1 == 'f')
	{
		cout << "The stored temperature of " << temp_kelvin << " degrees Kelvin is now "
			<< get_temp_fahrenheit() << " degrees Fahrenheit." << endl;
	}
	else if (choose_temp_1 == 'C' || choose_temp_1 == 'c')
	{
		cout << "The stored temperature of " << temp_kelvin << " degrees Kelvin is now "
			<< get_temp_celsius() << " degrees Celsius." << endl;
	}
}