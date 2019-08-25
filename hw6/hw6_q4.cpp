/*
Helen Li
August 24, 2018
Homework #6 - Question 4
*/

#include <iostream>
using namespace std;

void printDivisors(int num);

int main()
{
	int num;

	cout << "Please enter a positive integer >= 2: ";
	cin >> num;

	printDivisors(num);

	return 0;
}

void printDivisors(int num)
{
	for (int i = 1; i <= (num / 2); i++)
	{
		if (num % i == 0)
			cout << i << " ";
	}

	cout << num << endl;
}
