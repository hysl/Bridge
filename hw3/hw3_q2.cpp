/*
Helen Li
August 3, 2018
Homework #3 - Question 2
*/

#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string name;
	int gradYear, currentYear, difference;

	cout << "Please enter your name: ";
	cin >> name;
	cout << "Please enter your graduation year: ";
	cin >> gradYear;
	cout << "Please enter current year: ";
	cin >> currentYear;

	difference = gradYear - currentYear;

	if (gradYear == currentYear)
		cout << name << ", you Graduated" << endl;
	else if (difference > 4)
		cout << name << ", you are not in college yet" << endl;
	else if (difference == 4)
		cout << name << ", you are a Freshman" << endl;
	else if (difference == 3)
		cout << name << ", you are a Sophomore" << endl;
	else if (difference == 2)
		cout << name << ", you are a Junior" << endl;
	else if (difference == 1)
		cout << name << ", you are a Senior" << endl;
	else
		cout << name << ", you Graduated" << endl;

	return 0;
}
