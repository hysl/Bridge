/*
Helen Li
August 24, 2018
Homework #6 - Question 3
*/

#include <iostream>
using namespace std;

double eApprox(int n);

int main()
{
	cout.precision(30);

	int num;

	cout << "Please enter a positive integer: ";
	cin >> num;

	for (int n = 1; n <= num; n++)
		cout << "n = " << n << '\t' << eApprox(n) << endl;

	return 0;
}

double eApprox(int n)
{
	double factorial, result;

	factorial = 1;
	result = 1;

	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
		result += (1/factorial);
	}

	return result;
}
