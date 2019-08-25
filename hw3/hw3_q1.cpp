/*
Helen Li
August 3, 2018
Homework #3 - Question 1
*/

#include <iostream>
using namespace std;

const double DISCOUNT_RATE = 0.50;
const double CLUB_DISCOUNT = 0.90;
const double TAX_RATE_IN_DECIMAL = 0.01;

int main ()
{
	double itemOnePrice, itemTwoPrice;
	char clubCard;
	double taxRate;
	double basePrice;
	double discountedPrice;
	double totalPrice;
	cout.setf(ios::fixed);

	cout << "Enter price of first item: ";
	cin >> itemOnePrice;
	cout << "Enter price of second item: ";
	cin >> itemTwoPrice;
	cout << "Does customer have a club card? (Y/N): ";
	cin >> clubCard;
	cout << "Enter tax rate, e.g. 5.5 for 5.5\% tax: ";
	cin >> taxRate;

	cout.precision(1);
	basePrice = itemOnePrice + itemTwoPrice;
	cout << "Base price: " << basePrice << endl;

	if (itemOnePrice >= itemTwoPrice)
		itemTwoPrice *= DISCOUNT_RATE;
	else
		itemOnePrice *= DISCOUNT_RATE;

	switch (clubCard)
	{
		case 'y': case 'Y':
			discountedPrice = (itemOnePrice + itemTwoPrice) * CLUB_DISCOUNT;
			break;
		case 'n': case 'N':
			discountedPrice = itemOnePrice + itemTwoPrice;
			break;
		default:
			cout << "Invalid agrument" << endl;
			break;
	}

	totalPrice = discountedPrice + ((taxRate * TAX_RATE_IN_DECIMAL) * discountedPrice);

	cout << "Price after discounts: " << discountedPrice << endl;
	
	cout.precision(5);
	cout << "Total price: " << totalPrice << endl;

	return 0;
}
