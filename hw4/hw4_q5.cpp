/*
Helen Li
August 10, 2018
Homework #4 - Question 5
*/

#include <iostream>
using namespace std;

int main ()
{
    int num;

    cout << "Please enter a positive integer to print a textual image of an hourglass: ";
    cin >> num;

    for (int i = num; i > 0; i--)
    {
        for (int j = num; i < j; j--)
            cout << " ";
        for (int j = 1; j <= ((i * 2) - 1); j++)
            cout << "*";
        cout << endl;
    }

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= (num - i); j++)
            cout << " ";
        for (int j = 1; j <= ((i * 2) - 1); j++)
            cout << "*";
        cout << endl;
    }

    return 0;
}
