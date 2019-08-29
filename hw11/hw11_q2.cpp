/*
Helen Li
September 28, 2018
Homework #11 - Question 2
*/

#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main()
{
	int arr[4] = {2, -1, 3, 10};
	int arrSize = 4;

	cout << "Part A:" << endl;
	int sum = sumOfSquares(arr, arrSize);
	cout << "The sum of the squares is " << sum << "." << endl;

	cout << endl << "Part B:" << endl;

	bool sorted = isSorted(arr, arrSize);

	if(sorted == true)
	{
		cout << "The array is sorted." << endl;
	}
	else
	{
		cout << "The array is not sorted." << endl;
	}

	return 0;
}

int sumOfSquares(int arr[], int arrSize)
{
	int sum = 0;
	sum = arr[arrSize - 1] * arr[arrSize - 1];

	if(arrSize > 1)
	{
		sum = sum + sumOfSquares(arr, arrSize - 1);
	}

	return sum;
}

bool isSorted(int arr[], int arrSize)
{
	if(arrSize == 0 || arrSize == 1)
	{
		return true;
	}
	else
	{
		if(arr[arrSize - 1] < arr[arrSize - 2])
		{
			return false;
		}
		else
		{
			return isSorted(arr, arrSize - 1);
		}
	}
}
