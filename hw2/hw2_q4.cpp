/*
Helen Li
July 27, 2018
Homework #2 - Question 4
*/

#include <iostream>
using namespace std;

int main ()
{
	int num1;
	int num2;

	cout << "Please enter two positive integers, separated by a space:" << endl;
	cin >> num1 >> num2;

	cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
	cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
	cout << num1 << " / " << num2 << " = " << num1 / (double) num2 << endl;
	cout << num1 << " div " << num2 << " = " << num1 / num2 << endl;
	cout << num1 << " mod " << num2 << " = " << num1 % num2 << endl;

	return 0;
}
