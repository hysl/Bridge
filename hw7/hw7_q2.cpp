/*
Helen Li
August 31, 2018
Homework #7 - Question 2
*/

#include <iostream>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main()
{
	int num, countDivs, sumDivs;
	countDivs = 0;
	sumDivs = 0;

	cout << "Please enter a positive integer greater than or equal to 2: ";
	cin >> num;

	analyzeDividors(num, countDivs, sumDivs);

	for(int i = 2; i < num; i++)
	{
		if(isPerfect(i) == true)
			cout << i << " is a perfect number" << endl;
	}

	for(int j = 2; j < num; j++)
	{
		int countDivs2 = 0;
		int sumDivs2 = 0;

		analyzeDividors(j, countDivs2, sumDivs2);

		for(int k = num; k > 1; k--)
		{
			int countDivs3 = 0;
			int sumDivs3 = 0;

			analyzeDividors(k, countDivs3, sumDivs3);

			if(sumDivs2 == k && sumDivs3 == j && j != k)
				cout << j << " and " << k << " are amicable numbers" << endl;
		}
	}
	return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
{
	for(int i = 1; i <= (num / 2); i++)
	{
		if(num % i == 0)
		{
			outCountDivs++;
			outSumDivs += i;
		}
	}
}

bool isPerfect(int num)
{
	int countDivs, sumDivs;
	countDivs = 0;
	sumDivs = 0;

	analyzeDividors(num, countDivs, sumDivs);

	if(sumDivs == num)
		return true;
	else
		return false;
}
