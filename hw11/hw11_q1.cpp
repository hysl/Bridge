/*
Helen Li
September 28, 2018
Homework #11 - Question 1
*/

#include <iostream>
using namespace std;

void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);

int main()
{
	cout << "Part A:" << endl << endl;
	printTriangle(4);
	cout << endl;

	cout << "Part B:" << endl << endl;
	printOpositeTriangles(4);
	cout << endl;

	cout << "Part C:" << endl << endl;
	printRuler(4);

	return 0;
}

void printTriangle(int n)
{
	if(n - 1 > 0)
	{
		printTriangle(n - 1);
	}

	for(int i = 0; i < n; i++)
	{
		cout << "*";
	}

	cout << endl;
}

void printOpositeTriangles(int n)
{
	for(int i = n; i > 0; i--)
	{
		cout << "*";
	}

	cout << endl;

	if(n - 1 > 0)
	{
		printOpositeTriangles(n - 1);
	}

	for(int i = 0; i < n; i++)
	{
		cout << "*";
	}

	cout << endl;
}

void printRuler(int n)
{
	if(n - 1 > 0)
	{
		printRuler(n-1);
	}

	for(int i = 0; i < n; i++)
	{
		cout << "-";
	}

	cout << endl;

	if (n - 1 > 0)
	{
		printRuler(n - 1);
	}
}
