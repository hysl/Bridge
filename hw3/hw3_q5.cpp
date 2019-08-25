/*
Helen Li
August 3, 2018
Homework #3 - Question 5
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const double POUNDS_TO_KILOGRAMS = 0.453592;
const double INCHES_TO_METERS = 0.0254;

int main ()
{
	double weightInPounds, heightInInches;
	double weightInKilograms, heightInMeters;
	double bmiValue;
	string weightStatus;

	cout << "Please enter weight (in pounds): ";
	cin >> weightInPounds;

	cout << "Please enter height (in inches): ";
	cin >> heightInInches;

	weightInKilograms = weightInPounds * POUNDS_TO_KILOGRAMS;
	heightInMeters = heightInInches * INCHES_TO_METERS;

	bmiValue = weightInKilograms / (heightInMeters * heightInMeters);

	if (bmiValue < 18.5)
		weightStatus = "Underweight";
	else if (bmiValue >= 18.5 && bmiValue < 25)
		weightStatus = "Normal";
	else if (bmiValue >= 25 && bmiValue < 30)
		weightStatus = "Overweight";
	else
		weightStatus = "Obese";

	cout << "The weight status is: " << weightStatus << endl;

	return 0;
}
