/*
Helen Li
September 14, 2018
Homework #9 - Question 2
*/

#include <iostream>
using namespace std;

void lowercase(string text);
void letterCount(string text, int letterCounter[]);
bool isAnagram(int letterCount1[], int letterCount2[], int arrLength);

int main()
{
	string text1, text2;

	int letterCount1[26] = {0};
	int letterCount2[26] = {0};

	cout << "Please enter 1st line of text:" << endl;
	getline(cin, text1);

	cout << "Please enter 2nd line of text:" << endl;
	getline(cin, text2);

	lowercase(text1);
	lowercase(text2);

	letterCount(text1, letterCount1);
	letterCount(text2, letterCount2);

	bool anagram = isAnagram(letterCount1, letterCount2, 26);

	if(anagram == false)
		cout << "The two lines of text are not anagrams" << endl;
	else
		cout << "The two lines of text are anagrams" << endl;

	return 0;
}

void lowercase(string text)
{
	for(int i = 0; i < text.length(); i++)
	{
		if((text[i] >= 'A' && text[i] <= 'Z') && text[i] != ' ')
			text[i] += 'a' - 'A';
	}
}

void letterCount(string text, int letterCounter[])
{
	for(int i = 0; i < text.length(); i++)
	{
		if(((int) text[i] >= 'a') && ((int) text[i] <= 'z'))
			letterCounter[((int) text[i]) - 97] += 1;
	}
}

bool isAnagram(int letterCount1[], int letterCount2[], int arrLength)
{
	for(int i = 0; i < arrLength; i++)
	{
		if(letterCount1[i] != letterCount2[i])
			return false;
	}

	return true;
}
