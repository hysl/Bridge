/*
Helen Li
August 10, 2018
Homework #4 - Question 2
*/

#include <iostream>
#include <string>
using namespace std;

int main ()
{
    int num, originalNum;
    string romanNumerals;

    cout << "Enter decimal number: " << endl;
    cin >> num;

    originalNum = num;

    romanNumerals = "";

    while (num > 0)
    {
        while (num >= 1000)
        {
            num -= 1000;
            romanNumerals += "M";
        }
        while (num >= 500)
        {
            num -= 500;
            romanNumerals += "D";
        }
        while (num >= 100)
        {
            num -= 100;
            romanNumerals += "C";
        }
        while (num >= 50)
        {
            num -= 50;
            romanNumerals += "L";
        }
        while (num >= 10)
        {
            num -= 10;
            romanNumerals += "X";
        }
        while (num >= 5)
        {
            num -= 5;
            romanNumerals += "V";
        }
        while (num >= 1)
        {
            num -= 1;
            romanNumerals += "I";
        }
    }

    if (originalNum == 0)
    	romanNumerals = "0";

    cout << originalNum << " is " << romanNumerals << endl;

    return 0;
}
