/*
Helen Li
September 7, 2018
Homework #8 - Question 5
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string firstName, middleName, lastName;

	cout << "Please enter your first name, middle name, and last name: " << endl;
	cin >> firstName >> middleName >> lastName;

	cout << lastName << ", " << firstName << " " << middleName[0] << "." << endl;

	return 0;
}
