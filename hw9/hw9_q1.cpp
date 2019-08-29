/*
Helen Li
September 14, 2018
Homework #9 - Question 1
*/

#include <iostream>
using namespace std;

int numOfWords(string text);
void printCount(string text, char letter);

int main()
{
	string text;
	int wordCount;

	cout << "Please enter a line of text: " << endl;
	getline(cin, text);

	for(int i = 0; i < text.length(); i++)
	{
		if((text[i] >= 'A' && text[i] <= 'Z') && text[i] != ' ')
			text[i] += 'a' - 'A';
	}

	wordCount = numOfWords(text);
	cout << wordCount << "\twords" << endl;

	for(int j = 'a'; j <= 'z'; j++)
		printCount(text, j);

	return 0;
}

int numOfWords(string text)
{
	int wordCount = 1;
	char space = ' ';

	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] == space)
			wordCount++;
	}

	return wordCount;
}

void printCount(string text, char letter)
{
	int letterCount = 0;

	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] == letter)
			letterCount++;
	}

	if(letterCount > 0)
		cout << letterCount << "\t" << letter << endl;
}
