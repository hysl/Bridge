/*
Helen Li
September 14, 2018
Homework #9 - Question 4
*/

#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main()
{
	int* arr = new int[100];
	int nums;
	int arrSize = 0;

	cout << "Enter integers, each one in a separate line:" << endl;
	cout << "End your sequence by typing 1234567890" << endl;

	while(nums != 1234567890)
	{
		cin >> nums;
		if(nums == 1234567890)
			break;
		else
		{
			arr[arrSize] = nums;
			arrSize++;
		}
	}

	oddsKeepEvensFlip(arr, arrSize);

	return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize)
{
	int* temp = new int[arrSize];
	int index = 0;
	int tempArrSize = arrSize - 1;

	for(int i = 0; i < arrSize; i++)
	{
		if(arr[i] % 2 == 1 || arr[i] % 2 == -1)
		{
			temp[index] = arr[i];
			index++;
		}
	}

	for(int i = 0; i < arrSize; i++)
	{
		if(arr[i] % 2 == 0)
		{
			temp[tempArrSize] = arr[i];
			tempArrSize--;
		}
	}

	for(int i = 0; i < arrSize; i++)
		cout << temp[i] << " ";

	cout << endl;
}
