/****************************************
Author: Sam Pickell
Date: 9/18/2016
Time Spent: 52 minutes
Purpose: Take measurements in feet and
		inches and convert them to
		meters and centimeters displayed
		to the 8th decimal place.
Reason for Resubmit: Added const 
		variables to the conversion 
		function.
****************************************/

#include <iostream>
#include <cmath>

using namespace std;

void magic_formula();
void get_imperial(int& f, double& i);
void convert_imperial(int f, double i, int& m, double& c);
void display_metric(int f, double i, int m, double c);


int main()
{
	int iFeet, iMeters;
	double dInches, dCentimeters;

	get_imperial(iFeet, dInches);
	convert_imperial(iFeet, dInches, iMeters, dCentimeters);
	display_metric(iFeet, dInches, iMeters, dCentimeters);

	return 0;
}

void magic_formula()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(8);
}

void get_imperial(int& f, double& i)
{
	cout << "Please enter the number of feet: ";
	cin >> f;
	cout << "Please enter the number of inches: ";
	cin >> i;
}

void convert_imperial(int f, double i, int& m, double& c)
{
	double total_feet, total_meters;
	const int inches_to_feet = 12;
	const int meters_to_centimeters = 100;
	const double feet_to_meters = 0.3048;

	total_feet = f + (i / inches_to_feet);
	total_meters = total_feet * feet_to_meters;
	m = floor(total_meters);
	c = (total_meters - m) * meters_to_centimeters;
}

void display_metric(int f, double i, int m, double c)
{
	magic_formula();

	cout << f << " feet and " << i << " inches convert to" << endl;
	cout << m << " meters and " << c << " centimeters." << endl;
}