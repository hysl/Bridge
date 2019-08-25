/*
Helen Li
August 10, 2018
Homework #4 - Question 1
*/

#include <iostream>
using namespace std;

int main ()
{
	int n;
	int counter;

	cout << "Section a\n" << endl;

	cout << "Please enter a positive integer: ";
	cin >> n;

	counter = 1;

	while (counter <= n)
	{
		cout << counter * 2 << endl;
		counter++;
	}

	cout << "\nSection b\n" << endl;
	
	cout << "Please enter a positive integer: ";
	cin >> n;

	for (counter = 1; counter <= n; counter++)
	{
		cout << counter * 2 << endl;
	}

	return 0;
}
