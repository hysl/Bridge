/* 
Helen Li
October 26, 2018
Homework #14 
*/

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> arr, int n);
int findMax(vector<int> arr, int n);
vector<int> findMinMax(vector<int> arr, int lower, int upper);

int main()
{
	int count, num;
	vector<int> v, arr;

	cout << "How many numbers are in the vector?" << endl;
	cin >> count;
	cout << "Enter each number on a separate line: " << endl;

	for(int i = 0; i < count; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	arr = findMinMax(v, 0, (v.size() - 1));

	cout << "Min: " << arr[0] << endl;
	cout << "Max: " << arr[1] << endl;

	return 0;
}

int findMin(vector<int> arr, int n)
{
	int min;

	if(n == 1)
	{
		return arr[0];
	}
	else
	{
		min = findMin(arr, n - 1);
		if(arr[n - 1] < min)
			return arr[n - 1];
		else
			return min;
	}
}

int findMax(vector<int> arr, int n)
{
	int max;

	if(n == 1)
	{
		return arr[0];
	}
	else
	{
		max = findMax(arr, n - 1);
		if(arr[n - 1] > max)
			return arr[n - 1];
		else
			return max;
	}
}

vector<int> findMinMax(vector<int> arr, int lower, int upper)
{
	int mid = (lower + upper) / 2;

	vector<int> v, v1, v2;

	if(lower == upper)
	{
		v.push_back(arr[lower]);
		v.push_back(arr[upper]);
		return v;
	}
	else if(upper - lower == 1)
	{
		if(arr[lower] < arr[upper])
		{
			v.push_back(arr[lower]);
			v.push_back(arr[upper]);
		}
		else
		{
			v.push_back(arr[upper]);
			v.push_back(arr[lower]);
		}
		return v;
	}

	v1 = findMinMax(arr, lower, mid);
	v2 = findMinMax(arr, mid + 1, upper);

	int v1min = findMin(v1, v1.size());
	int v2min = findMin(v2, v2.size());
	int v1max = findMax(v1, v1.size());
	int v2max = findMax(v2, v2.size());

	if(v1min < v2min)
		v.push_back(v1min);
	else
		v.push_back(v2min);

	if(v1max > v2max)
		v.push_back(v1max);
	else
		v.push_back(v2max);

	return v;
}
