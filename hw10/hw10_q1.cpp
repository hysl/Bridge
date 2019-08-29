/*
Helen Li
September 21, 2018
Homework #10 - Question 1
*/

#include <iostream>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main()
{
	string sentence;
	string* arrSentence;
	int outWordsArrSize = 0;

	cout << "Enter a sentence:" << endl;
	getline(cin, sentence);

	arrSentence = createWordsArray(sentence, outWordsArrSize);

	cout << "There are " << outWordsArrSize << " words in your sentence:" << endl;

	for(int i = 0; i < outWordsArrSize; i++)
		cout << arrSentence[i] << endl;

	cout << endl;

	return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize)
{
	string* arrSentence = new string[100];

	for(int i = 0; i < sentence.length(); i++)
	{
		if(sentence[i] == ' ')
			outWordsArrSize++;
		else
		{
			if((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= '0' && sentence[i] <= '9'))
				arrSentence[outWordsArrSize] += sentence[i];
		}
	}

	outWordsArrSize++;

	return arrSentence;
}
