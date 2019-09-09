/* 
Helen Li
November 9, 2018
Homework #16 - Question 1 
*/

#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

bool symbolChecker(ifstream& fs);

int main()
{
	string filename;
	ifstream fs;
	bool balanced;

	cout << "Please enter the file name:" << endl;
	cin >> filename;

	fs.open(filename);
	if(fs.fail())
	{
		cout << "File \"" << filename << "\" does not exist" << endl;
		exit(1);
	}
	else
	{
		balanced = symbolChecker(fs);
		if(balanced)
			cout << "The symbols are balanced" << endl;
		else
			cout << "The symbols are not balanced" << endl;
	}
	fs.close();

	return 0;
}

bool symbolChecker(ifstream& fs)
{
	stack<char> s;
	char x, y;
	while(!fs.eof())
	{
		fs.get(y);
		if(y == '(' || y == '{' || y == '[')
		{
			s.push(y);
		}
		else if(y == ')' || y == '}' || y == ']')
		{
			if(s.empty())
				return false;
			else if(y == ')')
			{
				x = s.top();
				s.pop();
				if(x == '{' || x == '[')
					return false;
			}
			else if(y == '}')
			{
				x = s.top();
				s.pop();
				if(x == '(' || x == '[')
					return false;
			}
			else if(y == ']')
			{
				x = s.top();
				s.pop();
				if(x == '(' || x == '{')
					return false;
			}
			else
				s.pop();
		}
	}

	if(s.empty())
		return true;
	else
		return false;
}
