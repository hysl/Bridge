/*
Helen Li
August 17, 2018
Homework #5 - Question 2
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main ()
{
    int num;
    int guess;
    int lowerBound, upperBound;
    int guessCount, guessesLeft;
    bool seenEndOfSeq;
    
    srand(time(0));
    
    num = (rand() % 100) + 1;
    
    lowerBound = 1;
    upperBound = 100;
    seenEndOfSeq = false;
    guessCount = 0;
    guessesLeft = 5;
    
    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;
    
    while (seenEndOfSeq == false)
    {
        cout << "Range: [" << lowerBound << ", " << upperBound << "], Number of guesses left: " << guessesLeft << endl;
        cout << "Your guess: ";
        cin >> guess;
        guessCount++;
        guessesLeft--;
        if (guess == num)
        {
            cout << "Congrats! You guessed my number in " << guessCount << " guesses." <<endl;
            seenEndOfSeq = true;
        }
        else
        {
            if (guessesLeft == 0)
            {
                cout << "Out of guesses! My number is " << num << endl;
                seenEndOfSeq = true;
            }
            else
            {
                if (guess < num)
                {
                    cout << "Wrong! My number is bigger." << endl;
                    if (guess >= lowerBound)
                        lowerBound = guess + 1;
                }
                else
                {
                    cout << "Wrong! My number is smaller." << endl;
                    if (guess <= upperBound)
                        upperBound = guess - 1;
                }
            }
        }
    }
    
    return 0;
}
