/*
Helen Li
September 7, 2018
Homework #8 - Question 2
*/

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main()
{
	string word;

	cout << "Please enter a word: ";
	getline(cin, word);

	bool palidrome = isPalindrome(word);

	if(palidrome == true)
		cout << word << " is a palidrome" << endl;
	else
		cout << word << " is not a palidrome" << endl;	

	return 0;
}

bool isPalindrome(string str)
{
	string strReversed;

	for(int i = str.length() - 1; i >= 0; i--)
	{
		strReversed += str[i];
	}

	if(strReversed == str)
		return true;
	else
		return false;
}
