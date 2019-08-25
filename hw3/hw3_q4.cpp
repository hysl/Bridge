/*
Helen Li
August 3, 2018
Homework #3 - Question 4
*/

#include <iostream>
#include <cmath>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main ()
{
	double num1;
	int roundingMethod;
	int roundedNum;

	cout << "Please enter a Real number:" << endl;
	cin >> num1;

	cout << "Choose your rounding method:" << endl;
	cout << "1. Floor round" << endl;
	cout << "2. Ceiling round" << endl;
	cout << "3. Round to the nearest whole number" << endl;
	cin >> roundingMethod;

	switch (roundingMethod)
	{
		case FLOOR_ROUND:
			roundedNum = floor(num1);
			cout << roundedNum << endl;
			break;
		case CEILING_ROUND:
			roundedNum = ceil(num1);
			cout << roundedNum << endl;
			break;
		case ROUND:
			roundedNum = round(num1);
			cout << roundedNum << endl;
			break;
		default:
			cout << "Invalid Rounding Method" << endl;
			break;
	}

	return 0;
}
