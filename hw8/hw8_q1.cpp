/*
Helen Li
September 7, 2018
Homework #8 - Question 1
*/

#include <iostream>
using namespace std;

const int MAX_VALUES = 20;

int minInArray(int arr[], int arrSize);
void minIndices(int arr[], int arrSize);

int main()
{
	int num;
	int arr[MAX_VALUES];
	int minValue;

	cout << "Please enter " << MAX_VALUES << " integers separated by a space: " << endl;

	for(int i = 0; i < MAX_VALUES; i++)
	{
		cin >> num;
		arr[i] = num;
	}

	minIndices(arr, MAX_VALUES);

	return 0;
}

int minInArray(int arr[], int arrSize)
{
	int temp = arr[0];

	for(int i = 1; i < arrSize; i++)
	{
		if (arr[i] < temp)
			temp = arr[i];
	}

	return temp;
}

void minIndices(int arr[], int arrSize)
{
	int minValue = minInArray(arr, arrSize);

	cout << "The minimum value is " << minValue << " and it is located in the following indices: ";

	for(int j = 0; j < MAX_VALUES; j++)
	{
		if(arr[j] == minValue)
			cout << j << " ";
	}

	cout << endl;
}
