/*
Helen Li
August 3, 2018
Homework #3 - Question 6
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const double RATE_BETWEEN_WEEKDAYS = 0.40;
const double RATE_OUTSIDE_WEEKDAYS = 0.25;
const double RATE_WEEKENDS = 0.15;

int main ()
{
	string dayOfWeek;
	int startHour, startMinute;
	int numberOfMinutes;
	char colon;
	int startTime;
	double costOfCall;
	cout.setf(ios::fixed);

	cout << "Enter the day of the week (ie: Mo Tu We Th Fr Sa Su): ";
	cin >> dayOfWeek;

	cout << "Enter the time the call started in 24-hour notation (ie: 12:30 AM is 00:30): ";
	cin >> startHour >> colon >> startMinute;

	cout << "Enter the length of the call in minutes: ";
	cin >> numberOfMinutes;

	startTime = (startHour * 100) + startMinute;

	if (dayOfWeek == "Sa" || dayOfWeek == "sa" || dayOfWeek == "Su" || dayOfWeek == "su")
		costOfCall = numberOfMinutes * RATE_WEEKENDS;
	else
	{
		if (startTime >= 800 && startTime <= 1800)
			costOfCall = numberOfMinutes * RATE_BETWEEN_WEEKDAYS;
		else
			costOfCall = numberOfMinutes * RATE_OUTSIDE_WEEKDAYS;
	}

	cout.precision(2);
	cout << "The cost of the call is: $" << costOfCall << endl;

	return 0;
}
