/* 
Helen Li
July 27, 2018
Homework #2 - Question 2
*/

#include <iostream>
using namespace std;

const int QUARTERS_VALUE = 25;
const int DIMES_VALUE = 10;
const int NICKELS_VALUE = 5;
const int DOLLAR_TO_CENTS = 100;
// do not need PENNIES_VALUE because it is 1 to 1

int main ()
{
	int dollar;
	int cent;

	cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;
	cin >> dollar >> cent;
	cout << dollar << " dollars and " << cent << " cents are:" << endl;

	int totalInCents = (dollar * DOLLAR_TO_CENTS) + cent;

	int quarters = totalInCents / QUARTERS_VALUE;
	int dimes = (totalInCents % QUARTERS_VALUE) / DIMES_VALUE;
	int nickels = ((totalInCents % QUARTERS_VALUE) - (dimes * DIMES_VALUE)) / NICKELS_VALUE; 
	int pennies = totalInCents - ((quarters * QUARTERS_VALUE) + (dimes * DIMES_VALUE) + 
		(nickels * NICKELS_VALUE));

	cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " 
		<< pennies << " pennies" << endl;

	return 0;
}
