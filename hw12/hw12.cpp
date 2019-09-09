/* 
Helen Li
October 12, 2018
Homework #12 
*/

#include <iostream>
using namespace std;

class Money
{
public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1, const Money& amount2);
    friend bool operator <(const Money& amount1, const Money& amount2);
    friend bool operator >(const Money& amount1, const Money& amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    double get_value() const;
    void set_value(double amount);

private:
    long all_cents;
};

class Check
{
public:
    Check(int checkNum, Money checkAmount, bool isCashed);
    Check(int checkNum, Money checkAmount);
    Check(int checkNum);
    Check();
    int getCheckNum() const;
    double getCheckAmount() const;
    bool getCashedStat() const;
    void set(int checkNum);
    void set(int checkNum, Money checkAmount);
    void set(int checkNum, Money checkAmount, bool isCashed);

private:
    int checkNum;
    Money checkAmount;
    bool isCashed;
};


//Math is incorrect - need to fix!
int main()
{
    Money moneys[100];
    Check checks[100];
    bool cashed[100];

    int num;

    int arr1num;
    double arr2num;
    bool arr3num;

    cout << "How many checks were not cashed as of the last time " << endl;
    cout << "you balanced your checkbook?" << endl;
    cin >> num;

    for(int i = 0; i < num; i++)
    {
        cout << "Enter Check " << (i + 1) << "'s Check Amount: " << endl;
        cout << "$";
        cin >> arr2num;
        moneys[i].set_value(arr2num);

        cout << "Enter Check " << (i + 1) << "'s Check Number: " << endl;
        cin >> arr1num;
        checks[i].set(arr1num);
        
        cout << "Was the check cashed? Enter 0 for no, 1 for yes:" << endl;
        cin >> arr3num;
        cashed[i] = arr3num;

        checks[i].set(checks[i].getCheckNum(), checks[i].getCheckAmount(), checks[i].getCashedStat());
    }

    double cashedTotal = 0;

    for (int i = 0; i < num; i++)
    {
        if(cashed[i] == true)
            cashedTotal += (double)((double)moneys[i].get_value() * 100.0);
    }

    Money deposits[100];

    int num2;
    double value;
    double depositsTotal = 0;

    cout << "\nHow many deposits did you make?" << endl;
    cin >> num2;

    cout << "Enter each amount as a separate line:" << endl;
    cout << "(Do not enter the $ sign)" << endl;

    for(int i = 0; i < num2; i++)
    {
        cout << "$";
        cin >> value;
        deposits[i].set_value(value);
        depositsTotal += (deposits[i].get_value() * 100.0);
    }

    double oldBalance, bankNewBalance, newBalance, difference;

    cout << "\nEnter in the old balance: $";
    cin >> oldBalance;
    cout << endl;
    cout << "Enter in the bank's new balance: $";
    cin >> bankNewBalance;
    cout << endl;

    newBalance = oldBalance + depositsTotal - cashedTotal;
    difference = newBalance - bankNewBalance;

    cout << "Total of checks cashed: $" << cashedTotal << endl;
    cout << "Total of deposits: $" << depositsTotal << endl;
    cout << "The new bank balance should be: $" << newBalance << endl;

    if(difference == 0)
        cout << "The new balance and the bank's balance are the same!" << endl;
    else
    {
        cout << "The difference between the new balance and the bank's balance is ";
        cout << difference << "." << endl;
    }

    //need to make two lists - cashed vs not cashed checks
    //need to sort and print check numbers
    Check cashedArray[100];
    int cashedArrayIndex = 0;
    Check notCashedArray[100];
    int notCashedArrayIndex = 0;

    for(int i = 0; i < num; i++)
    {
        if(cashed[i] == true)
        {
            int temp = checks[i].getCheckNum();
            cashedArray[cashedArrayIndex].set(temp);
            cashedArrayIndex++;
        }
        else
        {
            int temp = checks[i].getCheckNum();
            notCashedArray[notCashedArrayIndex].set(temp);
            notCashedArrayIndex++;
        }
    }

    cout << "\nThe checks cashed since the last time you balanced your checkbook are:" << endl;

    for(int i = 0; i <= cashedArrayIndex; i++)
        cout << cashedArray[i].getCheckNum() << endl;

    cout << "The checks not cashed since the last time you balanced your checkbook are:" << endl;

    for(int i = 0; i <= notCashedArrayIndex; i++)
        cout << notCashedArray[i].getCheckNum() << endl;
}

Money::Money()
{
    all_cents = 0.0;
}

Money::Money(long dollars)
{
    all_cents = dollars * 100;
}

Money::Money(long dollars, int cents)
{
    all_cents = dollars * 100 + cents;
}

double Money::get_value() const
{
    return (all_cents * 0.01);
}

void Money::set_value(double amount)
{
    all_cents = amount;
}

Money operator +(const Money& amount1, const Money& amount2)
{
    Money newAmount;
    newAmount.all_cents = amount1.all_cents + amount2.all_cents;
    return newAmount;
}

Money operator -(const Money& amount1, const Money& amount2)
{
    Money newAmount;
    newAmount.all_cents = amount1.all_cents - amount2.all_cents;
    if(newAmount.all_cents > 0)
        return newAmount;
    else
        return 0;
}

bool operator <(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents < amount2.all_cents);
}

bool operator >(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents > amount2.all_cents);
}

Check::Check()
{
    checkNum = 0;
    Money checkAmount;
    isCashed = false;
}

Check::Check(int checkNumInput)
{
    checkNum = checkNumInput;
}

Check::Check(int checkNumInput, Money checkAmountInput)
{
    checkNum = checkNumInput;
    checkAmount = checkAmountInput;
    isCashed = false;
}

Check::Check(int checkNumInput, Money checkAmountInput, bool isCashedInput)
{
    checkNum = checkNumInput;
    checkAmount = checkAmountInput;
    isCashed = isCashedInput;
}

int Check::getCheckNum() const
{
    return checkNum;
}

double Check::getCheckAmount() const
{
    return checkAmount.get_value();
}

bool Check::getCashedStat() const
{
    return isCashed;
}

void Check::set(int checkNumInput)
{
    int checkNum = checkNumInput;
}

void Check::set(int checkNumInput, Money checkAmountInput)
{
    int checkNum = checkNumInput;
    Money checkAmount = checkAmountInput;
}

void Check::set(int checkNumInput, Money checkAmountInput, bool isCashedInput)
{
    int checkNum = checkNumInput;
    Money checkAmount = checkAmountInput;
    bool isCashed = isCashedInput;
}
