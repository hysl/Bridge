/*
Helen Li
August 10, 2018
Homework #4 - Question 3
*/

#include <iostream>
#include <string>
using namespace std;

int main ()
{
	int num, remainder;
	string binaryRep;
	int originalNum;

	cout << "Enter decimal number:" << endl;
	cin >> num;

	originalNum = num;

	binaryRep = "";

	while (num != 0)
	{
		remainder = num % 2;
		num = num / 2;
		binaryRep = std::to_string(remainder) + binaryRep;
	}

	cout << "The binary representation of " << originalNum << " is " << binaryRep << endl;

	return 0;
}
