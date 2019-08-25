/*
Helen Li
September 7, 2018
Homework #8 - Question 6
*/

#include <iostream>
#include <string>
using namespace std;

void evaluate(string arr[], int arrSize);

int main()
{
	string text;

	string arr[100];
	int arrSize = 0;

	cout << "Please enter a line of text:" << endl;
	getline(cin, text);

	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] != ' ')
		{
			arr[arrSize] += text[i];
		}
		else
		{
			arrSize++;
		}
	}
	arrSize++;

	evaluate(arr, arrSize);

	return 0;
}

void evaluate(string arr[], int arrSize)
{
	for(int i = 0; i < arrSize; i++)
	{
		string temp = "";
		for(int j = 0; j < arr[i].length(); j++)
		{
			if(arr[i][j] == '0' || arr[i][j] == '1' || arr[i][j] == '2' || 
				arr[i][j] == '3' || arr[i][j] == '4' || arr[i][j] == '5' || 
				arr[i][j] == '6' || arr[i][j] == '7' || arr[i][j] == '8' || arr[i][j] == '9')
				temp += arr[i][j];
			else
				temp += "x";
		}
		
		if(temp == arr[i])
		{
			for(int j = 0; j < arr[i].length(); j++)
				cout << "x";
			cout << " ";
		}
		else
			cout << arr[i] << " ";
	}

	cout << endl;
}
