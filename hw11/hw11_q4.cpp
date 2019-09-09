/* 
Helen Li
September 28, 2018
Homework #11 - Question 4
*/

#include <iostream>
using namespace std;

int jumpIt(int arr[], int arrSize);

int main()
{
	int arr[6] = {0, 3, 80, 6, 57, 10};
	int arrSize = 6;
	int sum;

	if(arrSize % 2 == 0)
	{
		sum = jumpIt(arr, arrSize);
	}
	else
	{
		sum = jumpIt(arr, arrSize - 1);
		sum += arr[arrSize - 1];
	}

	cout << "The lowest cost of this sequence is " << sum << "." << endl;

	return 0;
}

int jumpIt(int arr[], int arrSize)
{
	int sum;

	if(arrSize > 2)
	{
		sum = jumpIt(arr, arrSize - 2);
		if(arr[arrSize - 1] < arr[arrSize - 2])
		{
			sum += arr[arrSize - 1];
		}
		else
		{
			sum += arr[arrSize - 2];
		}
	}
	else
	{
		return arr[arrSize - 1];
	}

	return sum;
}
