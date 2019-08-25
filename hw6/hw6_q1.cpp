/*
Helen Li
August 24, 2018
Homework #6 - Question 1
*/

#include <iostream>
using namespace std;

int fib(int n);

int main()
{
	int num;

	cout << "Please enter a positive integer: ";
	cin >> num;

	cout << fib(num) << endl;

	return 0;
}

int fib(int n)
{
	int fib1, fib2, fibSum;

	fib1 = 0;
	fib2 = 1;
	fibSum = 0;

	for (int i = 0; i <= n; i++)
	{
		if (i <= 1)
			fibSum = i;
		else
		{
			fibSum = fib1 + fib2;
			fib1 = fib2;
			fib2 = fibSum;
		}
	}

	return fibSum;
}
