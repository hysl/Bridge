/* 
Helen Li
July 27, 2018
Homework #2 - Question 3
*/

#include <iostream>
using namespace std;

const int HOURS_IN_DAY = 24;
const int MINUTES_IN_HOUR = 60;

int main ()
{
	int johnDays;
	int johnHours;
	int johnMinutes;

	int billDays;
	int billHours;
	int billMinutes;

	cout << "Please enter the number of days John has worked: ";
	cin >> johnDays;

	cout << "Please enter the number of hours John has worked: ";
	cin >> johnHours;

	cout << "Please enter the number of minutes John has worked: ";
	cin >> johnMinutes;
	cout << endl;

	cout << "Please enter the number of days Bill has worked: ";
	cin >> billDays;

	cout << "Please enter the number of hours Bill has worked: ";
	cin >> billHours;

	cout << "Please enter the number of minutes Bill has worked: ";
	cin >> billMinutes;
	cout << endl;

	int johnTotal = (((johnDays * HOURS_IN_DAY) * MINUTES_IN_HOUR) + 
		(johnHours * MINUTES_IN_HOUR) + johnMinutes);
	int billTotal = (((billDays * HOURS_IN_DAY) * MINUTES_IN_HOUR) + 
		(billHours * MINUTES_IN_HOUR) + billMinutes);

	int total = johnTotal + billTotal;

	int daysTotal = total / (HOURS_IN_DAY * MINUTES_IN_HOUR);
	int hoursTotal = (total % (HOURS_IN_DAY * MINUTES_IN_HOUR)) / MINUTES_IN_HOUR;
	int minutesTotal = (total % (HOURS_IN_DAY * MINUTES_IN_HOUR)) - (hoursTotal * MINUTES_IN_HOUR);

	cout << "The total time both of them worked together is: " << daysTotal << " days, " 
		<< hoursTotal << " hours and " << minutesTotal << " minutes." << endl;

	return 0;
}
