/* 
Helen Li
November 9, 2018
Homework #16 - Question 2 
*/

//Implement a class which uses a vector to store the queue

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Queue
{
public:
	Queue()
	{
		head = -1;
		tail = -1;
	}

	bool isEmpty()
	{
		return (head == -1 && tail == -1);
	}

	int size()
	{
		if(head == -1 && tail == -1)
			return 0;
		else
			return (tail - head) + 1;
	}

	void enqueue(T newItem);

	void dequeue();

	void printQueue();

private:
	vector<T> data;
	int head, tail;
};

template <class T>
void Queue<T>::enqueue(T newItem)
{
	if(isEmpty())
	{
		head = tail = 0;
	}
	else
	{
		tail = tail + 1;
		head = 0;
	}
	data[tail] = newItem;
}

template <class T>
void Queue<T>::dequeue()
{
	if(isEmpty())
	{
		cout << "Error - Queue is Empty" << endl;
		return;
	}
	else if(head == tail)
	{
		tail = head = -1;
	}
	else
	{
		head = head + 1;
	}
}

template <class T>
void Queue<T>::printQueue()
{
	for(int i = 0; i < data.size(); i++)
	{
		cout << data[i] << " ";
	}

	cout << endl;
}
