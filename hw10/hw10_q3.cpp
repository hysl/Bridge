/*
Helen Li
September 21, 2018
Homework #10 - Question 3
*/

#include <iostream>
#include <vector>
using namespace std;

int main1();
int main2();

int main()
{
	cout << "Version 1: " << endl << endl;
	main1();
	cout << endl << endl;

	cout << "Version 2: " << endl << endl;
	main2();
	cout << endl;

	return 0;
}

int main1()
{
	int* arr1 = new int[100];
	int numbers1;
	int count1 = 0;
	int findNum1;

	cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
	cout << "End your input by typing -1." << endl;

	while(numbers1 != -1)
	{
		if(numbers1 == -1)
			break;
		else
		{
			cin >> numbers1;
			arr1[count1] = numbers1;
			count1++;
		}
	}
	count1++;

	cout << "Please enter a number you want to search." << endl;
	cin >> findNum1;

	int* tempArr1 = new int[100];
	int tempArrCount1 = 0;

	for(int i = 0; i < count1; i++)
	{
		if(findNum1 == arr1[i])
		{
			tempArr1[tempArrCount1] = i + 1;
			tempArrCount1++;
		}
	}

	if(tempArrCount1 > 0)
	{
		cout << findNum1 << " shows in lines ";
		for(int j = 0; j < tempArrCount1; j++)
		{
			if(j == tempArrCount1 - 1)
				cout << tempArr1[j] << "." << endl;
			else
				cout << tempArr1[j] << ", ";
		}
	}
	else
		cout << findNum1 << " does not show in any lines." << endl;

	return 0;
}

int main2()
{
	vector<int> arr2;
	int numbers2;
	int findNum2;

	cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
	cout << "End your input by typing -1." << endl;

	while(numbers2 != -1)
	{
		cin >> numbers2;
		arr2.push_back(numbers2);
	}

	cout << "Please enter a number you want to search." << endl;
	cin >> findNum2;

	int* tempArr2 = new int[100];
	int tempArrCount2 = 0;

	for(int i = 0; i < arr2.size(); i++)
	{
		if(findNum2 == arr2[i])
		{
			tempArr2[tempArrCount2] = i + 1;
			tempArrCount2++;
		}
	}

	if(tempArrCount2 > 0)
	{
		cout << findNum2 << " shows in lines ";
		for(int j = 0; j < tempArrCount2; j++)
		{
			if(j == tempArrCount2 - 1)
				cout << tempArr2[j] << "." << endl;
			else
				cout << tempArr2[j] << ", ";
		}
	}
	else
		cout << findNum2 << " does not show in any lines." << endl;

	return 0;
}
