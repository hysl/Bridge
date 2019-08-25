/*
Helen Li
August 10, 2018
Homework #4 - Question 6
*/

#include <iostream>
using namespace std;

int main ()
{
	int num;
	int remainder;
	int evenCount, oddCount;

	cout << "Please enter a positive integer: ";
	cin >> num;

	cout << "All numbers from 1 to " << num << " that have more even digits than odd digits are:" << endl;

	for (int i = 1; i <= num; i++)
	{
		int currentNum = i;
		evenCount = 0;
		oddCount = 0;

		while (currentNum > 0)
		{
			remainder = currentNum % 10;
			if (remainder % 2 == 0)
				evenCount++;
			else
				oddCount++;
			currentNum = currentNum / 10;
		}

		if (evenCount > oddCount)
			cout << i << endl;
	}

	return 0;
}
