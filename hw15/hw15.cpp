/* 
Helen Li
November 2, 2018
Homework #15 
*/

//need to fix searching by employee ID
//need to fix printing payroll information

#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class LList;

template <class T>
class LListNode
{
private:
	T data;
	LListNode<T>* next;
public:
	LListNode(T newdata = T(), LListNode<T>* newNext = nullptr) : data(newdata), next(newNext){}
	T getdata()
	{
		return data;
	}
	void setdata(T newdata)
	{
		data = newdata;
	}
	friend class LList<T>;
};

template <class T>
class LList
{
private:
	LListNode<T>* head;
	LListNode<T>* recursiveCopy(LListNode<T>* rhs);
public:
	LList() : head(nullptr) {}
	LList(const LList& rhs) : head(nullptr) 
	{
		*this = rhs;
	}
	LList<T>& operator = (const LList<T>& rhs);
	~LList()
	{
		clear();
	}
	void insertAtHead(T newdata);
	bool isEmpty() const
	{
		return head == nullptr;
	}
	void clear();
	void insertAtEnd(T newdata);
	void insertAtPoint(LListNode<T>* ptr, T newdata);
	int size() const;
	LListNode<T>* getHead();
	LListNode<T>* getNext(LListNode<T>* nodeptr);
};

class Employee
{
private:
	int empID;
	double payRate;
	string employeeName;
	int hoursWorked;
public:
	Employee();
	Employee(int newEmpID, double newPayRate, string newEmployeeName, int newHoursWorked);
	friend bool operator >(const Employee& emp1, const Employee& emp2);
	friend bool operator <(const Employee& emp1, const Employee& emp2);
	friend bool operator ==(const Employee& emp1, const Employee& emp2);

	int getEmpID()
	{
		return empID;
	}
	double getPayRate()
	{
		return payRate;
	}
	string getEmployeeName()
	{
		return employeeName;
	}
	int getHoursWorked()
	{
		return hoursWorked;
	}
  
	void setHoursWorked(int newHoursWorked)
	{
		hoursWorked = newHoursWorked;
	}
	int totalPay()
	{
		return static_cast<int>(payRate * hoursWorked);
	}
};

class EmployeeList
{
private:
	void swap(Employee** arr, int num1, int num2);
	void sort(Employee** arr, int size);
	LList<Employee*>* emp;
public:
	EmployeeList();
	EmployeeList(string filename);
	Employee* searchEmployeeById(int empID);
	void readEmployeeHours(string filename);
	void addHours(int empID, int hoursWorked);
	void printSortedList();
};

int main()
{
	string filename1, filename2;

	cout << "Enter the file name containing the Employee Data:" << endl;
	cin >> filename1;
	cout << "Enter the file name containing the Employee Hours:" << endl;
	cin >> filename2;

	EmployeeList* emp = new EmployeeList(filename1);
	emp -> readEmployeeHours(filename2);

	cout << "**********Payroll Information**********" << endl;
	emp -> printSortedList();
	cout << "**********End payroll******************" << endl;

	return 0;
}

template <class T>
LListNode<T>* LList<T>::recursiveCopy(LListNode<T>* rhs)
{
	if(rhs == nullptr)
		return nullptr;
	else
		return new LListNode<T>(rhs -> data, recursiveCopy(rhs -> next));
}

template <class T>
void LList<T>::clear()
{
	if(isEmpty())
		return;

	LListNode<T>* currentNode = head;
	LListNode<T>* newNode = head;
	while(newNode != nullptr)
	{
		newNode = currentNode -> next;
		if(newNode != nullptr)
			delete currentNode;
		currentNode = newNode;
	}

	head = nullptr;
}

template <class T>
void LList<T>::insertAtHead(T newdata)
{
	LListNode<T>* newNode = new LListNode<T>(newdata);
	LListNode<T>* temp = head;
	head = newNode;
	newNode -> next = temp;
}

template <class T>
void LList<T>::insertAtEnd(T newdata)
{
	if(isEmpty())
	{
		insertAtHead(newdata);
		return;
	}

	LListNode<T>* temp = new LListNode<T>(newdata);
	LListNode<T>* end = head;
	while(end -> next != nullptr)
		end = end -> next;
	end -> next = temp;
}

template <class T>
void LList<T>::insertAtPoint(LListNode<T>* ptr, T newdata)
{
	ptr -> setdata(newdata);
}

template <class T>
int LList<T>::size() const
{
	LListNode<T>* temp = head;
	int counter = 0;
	while(temp != nullptr)
	{
		temp = temp -> next;
		counter++;
	}

	return counter;
}

template <class T>
LListNode<T>* LList<T>::getHead()
{
	return head;
}

template <class T>
LListNode<T>* LList<T>::getNext(LListNode<T>* nodeptr)
{
	return nodeptr -> next;
}

Employee::Employee(int newEmpID, double newPayRate, string newEmployeeName, int newHoursWorked)
{
	empID = newEmpID;
	payRate = newPayRate;
	employeeName = newEmployeeName;
	hoursWorked = newHoursWorked;
}

bool operator >(Employee& emp1, Employee& emp2)
{
	return emp1.getHoursWorked() > emp2.getHoursWorked();
}

bool operator <(Employee& emp1, Employee& emp2)
{
	return emp1.getHoursWorked() < emp2.getHoursWorked();
}

bool operator ==(Employee& emp1, Employee& emp2)
{
	return emp1.getHoursWorked() == emp2.getHoursWorked();
}

EmployeeList::EmployeeList(string filename)
{
	fstream fs;
	bool isEOF;
	Employee* currentEmployee;
	int currentEmpID;
	double currentPayRate;
	string currentEmployeeName;

	fs.open(filename);
	emp = new LList<Employee*>;
	if(fs.fail())
	{
		cout << "File " << filename << " does not exist" << endl;
		exit(1);
	}
	else
	{
		isEOF = fs.eof();
		while(isEOF == false)
		{
			fs >> currentEmpID >> currentPayRate;
			getline(fs, currentEmployeeName);
			Employee* currentEmpPtr = new Employee(currentEmpID, currentPayRate, currentEmployeeName, 0);
			emp -> insertAtEnd(currentEmpPtr);
			isEOF = fs.eof();
		}
	}
}

void EmployeeList::swap(Employee** arr, int num1, int num2)
{
	Employee* temp = arr[num1];
	arr[num1] = arr[num2];
	arr[num2] = temp;
}

void EmployeeList::sort(Employee** arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		int j = i;
		while(j > 0 && (arr[j] >= arr[j - 1]))
		{
			swap(arr, j, j - 1);
			j--;
		}
	}
}

Employee* EmployeeList::searchEmployeeById(int empID)
{
	LListNode<Employee*>* current = nullptr;
	Employee* currentEmployee;

	if(emp -> isEmpty())
		return nullptr;
	else
	{
		current = emp -> getHead();
		while(current != nullptr)
		{
			currentEmployee = current -> getdata();
			if(currentEmployee -> getEmpID() == empID)
				return currentEmployee;
			current = emp -> getNext(current);
		}

		return nullptr;
	}
}

void EmployeeList::readEmployeeHours(string filename)
{
	fstream fs;
	bool isEOF;
	Employee* currentEmployee;
	int currentEmpID;
	int currentEmployeeHour;

	fs.open(filename);
	if(fs.fail())
	{
		cout << "File " << filename << " does not exist" << endl;
		exit(1);
	}
	else
	{
		isEOF = fs.eof();
		while(isEOF == false)
		{
			fs >> currentEmpID >> currentEmployeeHour;
			addHours(currentEmpID, currentEmployeeHour);
			isEOF = fs.eof();
		}
	}
}

void EmployeeList::addHours(int empID, int hoursWorked)
{
	Employee* emp = searchEmployeeById(empID);
	int hours;
	if(emp == nullptr)
	{
		cout << "Employee ID " << empID << " does not exist" << endl;
	}
	else
	{
		hours = emp -> getHoursWorked();
		emp -> setHoursWorked(hoursWorked + hours);
	}
}

void EmployeeList::printSortedList()
{
	int listSize = emp -> size();
	LListNode<Employee*>* current = nullptr;
	Employee* currentEmployee;
	Employee** empArr = new Employee*[listSize];
	int count = 0;

	if(!emp -> isEmpty())
	{
		current = emp -> getHead();
		while(current != nullptr)
		{
			currentEmployee = current -> getdata();
			empArr[count] = currentEmployee;
			current = emp -> getNext(current);
			count++;
		}
	}

	sort(empArr, listSize);

	for(int i = 0; i < listSize; i++)
	{
		currentEmployee = empArr[i];
		cout << currentEmployee -> getEmployeeName() << ", $" << currentEmployee -> totalPay() << endl;
	}
}
