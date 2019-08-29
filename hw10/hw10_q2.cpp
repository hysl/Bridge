/*
Helen Li
September 21, 2018
Homework #10 - Question 2
*/

#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main()
{
	int* arr = new int[100];
	int num;
	int n = 0;
	int resArrSize;
	int* missingNums;

	cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
	cout << "End your input by typing -1." << endl;

	while(num != -1)
	{
		if(num == -1)
			break;
		else
		{
			cin >> num;
			if(num < -1)
			{
				cout << "Error! Please enter positive integers only" << endl;
			}
			else
			{
				arr[n] = num;
				n++;
			}
		}
	}

	missingNums = findMissing(arr, n, resArrSize);

	cout << "There are " << resArrSize << " missing numbers:" << endl;
	for(int i = 0; i < resArrSize; i++)
		cout << missingNums[i] << " ";

	cout << endl;

	return 0;
}

int* findMissing(int arr[], int n, int& resArrSize)
{
	int max = arr[0];

	for(int i = 1; i < n; i++)
	{
		if(arr[i] > max)
			max = arr[i];
	}

	int* missingNums = new int[max];
	int count = 0;

	for(int j = 0; j < max; j++)
	{
		int i = 0;
		while(i < n)
		{
			if(j != arr[i])
			{
				if(i == (n - 1))
				{
					missingNums[count] = j;
					count++;
				}
				i++;
			}
			else
				break;
		}
	}
	resArrSize = count;

	return missingNums;
}
