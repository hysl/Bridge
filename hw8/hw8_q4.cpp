/*
Helen Li
September 7, 2018
Homework #8 - Question 4
*/

#include <iostream>
using namespace std;

const int YOUR_PIN[5] = {1, 2, 3, 4, 5};

void printPinArr(int pinArr[], int pinArrSize);
void printNumArr(int numArr[], int numArrSize);
bool checkMatch(int numArr[], string enteredPin);

int main()
{
	srand(time(0));

	string enteredPin;	

	int pinArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int pinArrSize = 10;

	cout << "Please enter your PIN according to the following mapping:" << endl;
	printPinArr(pinArr, pinArrSize);
	cout << endl;

	int numArr[10];
	int numArrSize = 10;

	printNumArr(numArr, numArrSize);
	cout << endl;

	cin >> enteredPin;

	bool pinMatched = checkMatch(numArr, enteredPin);

	if(pinMatched == true)
		cout << "Your PIN is correct" << endl;
	else
		cout << "Your PIN is not correct" << endl;

	return 0;
}

void printPinArr(int pinArr[], int pinArrSize)
{	
	cout << "PIN:\t";
	for(int i = 0; i < pinArrSize; i++)
		cout << pinArr[i] << " ";
}

void printNumArr(int numArr[], int numArrSize)
{
	cout << "NUM:\t";
	for(int i = 0; i < numArrSize; i++)
	{
		numArr[i] = (rand() % 3) + 1;
		cout << numArr[i] << " ";
	}
}

bool checkMatch(int numArr[], string enteredPin)
{
	bool pinMatched = true;

	while(pinMatched)
	{
		for(int i = 0; i <= enteredPin.length() - 1; i++)
		{
			if(enteredPin[i] - '0' != numArr[YOUR_PIN[i]])
			{
				pinMatched = false;
				return false;
			}
		}
		break;
	}
	return true;
}
