/*
Helen Li
August 24, 2018
Homework #6 - Question 2
*/

#include <iostream>
using namespace std;

void printPineTree (int n, char symbol);
void printShiftedTriangle(int n, int m, char symbol);

int main()
{
	int num;
	char symbol;

	cout << "Please enter the number of triangles: ";
	cin >> num;

	cout << "Please enter the character filling the tree: ";
	cin >> symbol;

	printPineTree(num, symbol);

	return 0;
}

void printPineTree(int n, char symbol)
{
	for (int i = 1; i <= n; i++)
		printShiftedTriangle(i, n + 1, symbol);
}

void printShiftedTriangle(int n, int m, char symbol)
{
	for (int i = 0; i <= n; i++)
	{
		int numOfSymbols = (2 * i) + 1;
		for (int j = 1; j < (m - i); j++)
			cout << ' ';
		for (int j = 1; j <= numOfSymbols; j++)
		{
			cout << symbol;
		}
		cout << endl;
	}
}
