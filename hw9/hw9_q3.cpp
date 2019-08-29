/*
Helen Li
September 14, 2018
Homework #9 - Question 3
*/

#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printArray(int* arr, int arrSize);

int main()
{
	int* arr = new int[100];
	int nums;
	int arrSize = 0;
	int outPosArrSize;
	int* outPosArr;

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

	cout << "Version #1:" << endl;
	outPosArr = getPosNums1(arr, arrSize, outPosArrSize);
	printArray(outPosArr, outPosArrSize);

	cout << endl << endl;

	cout << "Version #2:" << endl;
	getPosNums2(arr, arrSize, outPosArr, outPosArrSize);
	printArray(outPosArr, outPosArrSize);

	cout << endl << endl;

	cout << "Version #3:" << endl;
	outPosArr = getPosNums3(arr, arrSize, &outPosArrSize);
	printArray(outPosArr, outPosArrSize);

	cout << endl << endl;

	cout << "Version #4:" << endl;
	getPosNums4(arr, arrSize, &outPosArr, &outPosArrSize);
	printArray(outPosArr, outPosArrSize);

	cout << endl;

	return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
{
	outPosArrSize = 0;

	for(int i = 0; i < arrSize; i++)
	{
		if(arr[i] > 0)
			outPosArrSize++;
	}

	int* outPosArr = new int[outPosArrSize];

	int newArr = 0;

	for(int j = 0; j < arrSize; j++)
	{
		if(arr[j] > 0)
		{
			outPosArr[newArr] = arr[j];
			newArr++;
		}
	}

	return outPosArr;
}

void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
{
	outPosArrSize = 0;

	for(int i = 0; i < arrSize; i++)
	{
		if(arr[i] > 0)
			outPosArrSize++;
	}

	outPosArr = new int[outPosArrSize];

	int newArr = 0;

	for(int j = 0; j < arrSize; j++)
	{
		if(arr[j] > 0)
		{
			outPosArr[newArr] = arr[j];
			newArr++;
		}
	}
}

int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr)
{
	*outPosArrSizePtr = 0;

	for(int i = 0; i < arrSize; i++)
	{
		if(arr[i] > 0)
			(*outPosArrSizePtr)++;
	}

	int* outPosArr = new int[*outPosArrSizePtr];

	int newArr = 0;

	for(int j = 0; j < arrSize; j++)
	{
		if(arr[j] > 0)
		{
			outPosArr[newArr] = arr[j];
			newArr++;
		}
	}

	return outPosArr;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
{
	*outPosArrSizePtr = 0;

	for(int i = 0; i < arrSize; i++)
	{
		if(arr[i] > 0)
			(*outPosArrSizePtr)++;
	}

	(*outPosArrPtr) = new int[(*outPosArrSizePtr)];

	int newArr = 0;

	for(int j = 0; j < arrSize; j++)
	{
		if(arr[j] > 0)
		{
			(*outPosArrPtr)[newArr] = arr[j];
			newArr++;
		}
	}
}

void printArray(int* arr, int arrSize)
{
	for(int i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
}
