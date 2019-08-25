/*
Helen Li
August 3, 2018
Homework #3 - Question 3
*/

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	double a, b, c;
	double discriminant, root1, root2;
	cout.setf(ios::fixed);

	cout << "Please enter value of a: ";
	cin >> a;

	cout << "Please enter value of b: ";
	cin >> b;

	cout << "Please enter value of c: ";
	cin >> c;

	discriminant = (b * b) - (4 * a * c);

	cout.precision(1);

	if (a == 0 && b == 0 && c == 0)
		cout << "There are infinite number of solutions" << endl;
	else if (a == 0 && b == 0 && c !=0)
		cout << "There are no solutions" << endl;
	else if (a != 0)
	{
		if (discriminant > 0)
		{
			root1 = (-b + sqrt(discriminant)) / (2 * a);
			root2 = (-b - sqrt(discriminant)) / (2 * a);
			cout << "This equation has two real solutions x = " << root1 << ", x = " << root2 << endl;
		}
		else if (discriminant == 0)
		{
			root1 = (-b + sqrt(discriminant)) / (2 * a);
			cout << "This equation has a single real solution x = " << root1 << endl;
		}
		else
			cout << "There are no real solutions" << endl;
	}

	return 0;
}
