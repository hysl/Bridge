/* 
Helen Li
July 27, 2018
Homework #2 - Question 1 
*/

#include <iostream>
using namespace std;

const int QUARTERS_VALUE = 25;
const int DIMES_VALUE = 10;
const int NICKELS_VALUE = 5;
const int DOLLAR_TO_CENTS = 100;
// do not need PENNIES_VALUE because it is 1 to 1

int main()
{
	int quarters;
	int dimes;
	int nickels;
	int pennies;

	cout << "Please enter number of coins:" << endl;
	cout << "# of quarters: ";
	cin >> quarters;
	cout << "# of dimes: ";
	cin >> dimes;
	cout << "# of nickels: ";
	cin >> nickels;
	cout << "# of pennies: ";
	cin >> pennies;

	int valueOfQuarters = quarters * QUARTERS_VALUE;
	int valueOfDimes = dimes * DIMES_VALUE;
	int valueOfNickels = nickels * NICKELS_VALUE;

	int valueTotal = valueOfQuarters + valueOfDimes + valueOfNickels + pennies;

	int valueTotalDollars = valueTotal / DOLLAR_TO_CENTS;
	int valueTotalCents = valueTotal % DOLLAR_TO_CENTS;

	cout << "The total is " << valueTotalDollars << " dollars and " 
		<< valueTotalCents << " cents" << endl;

	return 0;
}
