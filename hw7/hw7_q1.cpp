/*
Helen Li
August 31, 2018
Homework #7 - Question 1
*/

#include <iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
bool isLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main()
{
	int startingDay;
	int year;

	cout << "Please enter the year: ";
	cin >> year;
	cout << "Please enter the starting day of the week: ";
	cin >> startingDay;
	cout << endl;

	printYearCalender(year, startingDay);

	return 0;
}

int printMonthCalender(int numOfDays, int startingDay)
{
	int lastDayInMonth;

	cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;

	for(int i = 1; i < startingDay; i++)
		cout << " \t";
	for(int j = 1; j <= numOfDays; j++)
	{
		cout << j << "\t";
		if(((j + startingDay) - 1) % 7 == 0)
		{
			if(j != numOfDays)
				cout << endl;
		}
	}

	lastDayInMonth = (((numOfDays - 1) % 7) + startingDay) % 7;
	if(lastDayInMonth == 0)
		lastDayInMonth = 7;

	return lastDayInMonth;
}

bool isLeapYear(int year)
{
	if 	(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	else
		return false;
}

void printYearCalender(int year, int startingDay)
{
	int lastDayInMonth, firstDayInMonth;

	cout << "January " << year << endl;
	lastDayInMonth = printMonthCalender(31, startingDay);
	if(lastDayInMonth == 7)
		firstDayInMonth = 1;
	else
		firstDayInMonth = lastDayInMonth + 1;

	cout << "\n\nFebruary " << year << endl;
	bool leapYear = isLeapYear(year);
	if (leapYear == true)
		lastDayInMonth = printMonthCalender(29, firstDayInMonth);
	else
		lastDayInMonth = printMonthCalender(28, firstDayInMonth);
	if(lastDayInMonth == 7)
		firstDayInMonth = 1;
	else
		firstDayInMonth = lastDayInMonth + 1;

	cout << "\n\nMarch " << year << endl;
	lastDayInMonth = printMonthCalender(31, firstDayInMonth);
	if(lastDayInMonth == 7)
		firstDayInMonth = 1;
	else
		firstDayInMonth = lastDayInMonth + 1;

	cout << "\n\nApril " << year << endl;
	lastDayInMonth = printMonthCalender(30, firstDayInMonth);
	if(lastDayInMonth == 7)
		firstDayInMonth = 1;
	else
		firstDayInMonth = lastDayInMonth + 1;

	cout << "\n\nMay " << year << endl;
	lastDayInMonth = printMonthCalender(31, firstDayInMonth);
	if(lastDayInMonth == 7)
		firstDayInMonth = 1;
	else
		firstDayInMonth = lastDayInMonth + 1;

	cout << "\n\nJune " << year << endl;
	lastDayInMonth = printMonthCalender(30, firstDayInMonth);
	if(lastDayInMonth == 7)
		firstDayInMonth = 1;
	else
		firstDayInMonth = lastDayInMonth + 1;

	cout << "\n\nJuly " << year << endl;
	lastDayInMonth = printMonthCalender(31, firstDayInMonth);
	if(lastDayInMonth == 7)
		firstDayInMonth = 1;
	else
		firstDayInMonth = lastDayInMonth + 1;

	cout << "\n\nAugust " << year << endl;
	lastDayInMonth = printMonthCalender(31, firstDayInMonth);
	if(lastDayInMonth == 7)
		firstDayInMonth = 1;
	else
		firstDayInMonth = lastDayInMonth + 1;

	cout << "\n\nSeptember " << year << endl;
	lastDayInMonth = printMonthCalender(30, firstDayInMonth);
	if(lastDayInMonth == 7)
		firstDayInMonth = 1;
	else
		firstDayInMonth = lastDayInMonth + 1;

	cout << "\n\nOctober " << year << endl;
	lastDayInMonth = printMonthCalender(31, firstDayInMonth);
	if(lastDayInMonth == 7)
		firstDayInMonth = 1;
	else
		firstDayInMonth = lastDayInMonth + 1;

	cout << "\n\nNovember " << year << endl;
	lastDayInMonth = printMonthCalender(30, firstDayInMonth);
	if(lastDayInMonth == 7)
		firstDayInMonth = 1;
	else
		firstDayInMonth = lastDayInMonth + 1;

	cout << "\n\nDecember " << year << endl;
	lastDayInMonth = printMonthCalender(31, firstDayInMonth);
	if(lastDayInMonth == 7)
		firstDayInMonth = 1;
	else
		firstDayInMonth = lastDayInMonth + 1;

	cout << endl;
}
