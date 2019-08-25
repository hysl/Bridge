/*
Helen Li
August 10, 2018
Homework #4 - Question 4
*/

#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
	int length;
	double num;
	double mean;
	double geometricMean;
	bool seenEndOfSeq;

	cout << "Section a\n" << endl;

	cout << "Please enter the length of the sequence: ";
	cin >> length;
	cout << "Please enter your sequence:" << endl;

	mean = 1;

	for (int i = 1; i <= length; i++)
	{
		cin >> num;
		mean *= num;
	}

	geometricMean = pow(mean, (double)1/length);

	cout << "The geometric mean is: " << geometricMean << endl;

	cout << "\nSection b\n" << endl;
	
	mean = 1;
	length = 0;

	cout << "Please enter a non-empty sequence of positive integers, each one in a separate line." << endl;
	cout << "End your sequence by typing -1:" << endl;

	seenEndOfSeq = false;

	while (seenEndOfSeq == false)
	{
		cin >> num;
		if (num == -1)
			seenEndOfSeq = true;
		else
		{
			mean *= num;
			length++;
		}
	}

	geometricMean = pow(mean, (double)1/length);

	cout << "The geometric mean is: " << geometricMean << endl;

	return 0;
}
