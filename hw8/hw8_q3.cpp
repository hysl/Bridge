/*
Helen Li
September 7, 2018
Homework #8 - Question 3
*/

#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main()
{
	int arr1[10] = {9, 2, 14, 12, -3};
	int arr1Size = 5;

	int arr2[10] = {21, 12, 6, 7, 14};
	int arr2Size = 5;

	int arr3[10] = {3, 6, 4, 1, 12};
	int arr3Size = 5;

	reverseArray(arr1, arr1Size);
	printArray(arr1, arr1Size);

	removeOdd(arr2, arr2Size);
	printArray(arr2, arr2Size);

	splitParity(arr3, arr3Size);
	printArray(arr3, arr3Size);

	return 0;
}

void reverseArray(int arr[], int arrSize)
{
	int temp;
	int last = arrSize - 1;

	for(int i = 0; i < (arrSize - 1) / 2; i++, last--)
	{
		temp = arr[i];
		arr[i] = arr[last];
		arr[last] = temp;
	}
}

void removeOdd(int arr[], int& arrSize)
{
	int newArrSize = 0;

	for(int i = 0; i < arrSize; i++)
	{
		if(arr[i] % 2 == 0)
		{
			arr[newArrSize] = arr[i];
			newArrSize++;
		}
	}

	arrSize = newArrSize;
}

void splitParity(int arr[], int arrSize)
{
	int temp;
	int last = arrSize - 1;

	for(int i = 0; i < last; i++)
	{
		if(arr[i] % 2 == 0)
		{
			while(arr[last] % 2 == 0)
				last--;
			if(arr[last] % 2 != 0)
			{
				temp = arr[i];
				arr[i] = arr[last];
				arr[last] = temp;
				last--;
			}
		}
	}
}

void printArray(int arr[], int arrSize)
{
	int i;

	for(i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
	cout << endl;
}
