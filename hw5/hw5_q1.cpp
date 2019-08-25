/*
Helen Li
August 17, 2018
Homework #5 - Question 1
*/

#include <iostream>
using namespace std;

int main ()
{
	int num;

	cout << "Please enter a positive integer:" << endl;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			cout << i * j << "\t";
		}
		cout << endl;
	}

	return 0;
}
