#include "HealthTracker.h"
#include "HealthData.h"
#include<iostream>
#include <string>
using namespace std;

void HealthTracker::shiftArrayToTheLeft(HealthData history[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		history[i] = history[i + 1];
	}
}

int HealthTracker::getIntegerInput()
{
	int input;
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "It is not a valid integer! Try one more time: ";
		cin >> input;
	}
	cin.ignore(1000, '\n');
	return input;
}

double HealthTracker::getDoubleInput()
{
	double input;
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "It is not a valid input! Try one more time: ";
		cin >> input;
	}
	return input;
}

HealthTracker::HealthTracker(string n, string g, int a, double h, int historyArraySize)
{
	name = n;
	gender = g;
	age = a;
	height = h;
	size = historyArraySize;
	history = new HealthData[historyArraySize];
}

void HealthTracker::input()
{
	string type;
	cout << "\nDay " << counter + 1 << ": " << endl;
	if (counter < size)
	{
		cout << "Enter weight: ";
		history[counter].setWeight(getDoubleInput());

		cout << "Enter Exercise Type: ";
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, type);
		history[counter].setExerciseType(type);

		cout << "Enter Exercise time: ";
		history[counter].setExerciseTime(getIntegerInput());

		cout << endl;
	}
	else
	{
		shiftArrayToTheLeft(history, size);

		cout << "Enter weight: ";
		history[size - 1].setWeight(getDoubleInput());

		cout << "Enter Exercise Type: ";
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, type);
		history[size - 1].setExerciseType(type);

		cout << "Enter Exercise time: ";
		history[size - 1].setExerciseTime(getIntegerInput());

		cout << endl;
	}
	counter++;
}

void HealthTracker::printRecent()
{
	cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl;
	cout << '\n';
	if (counter == 0)
	{
		cout << "There is no data to print!\n";
	}

	else if (counter < size)
	{
		history[counter - 1].print();
;	}
	else
	{
		history[size - 1].print();

	}
}

void HealthTracker::printHistory()
{
	if (counter == 0)
		cout << "no fitness data to print. \n";

	if (counter >= size)
	{
		for (int i = size - 1; i >= 0; i--)
		{
			cout << "\nDay " << i + 1 << ": " << endl;

			history[i].print();
		}
	}
	else
	{
		for (int i = counter - 1; i >= 0; i--)
		{
			cout << "\nDay " << i + 1 << ": " << endl;

			history[i].print();

		}
	}
}

void HealthTracker::menu()
{
	string x;
	bool Option1 = false;
	bool running = true;

	string option1 = "add data ";
	string option2 = "print data ";
	string option3 = "print history data";
	string option4 = "exit the program\n";
	cout << "You can perform one of the following actions:\n";
	cout <<"1. "<< option1 << "\n2. " << option2 << "\n3. " << option3 <<"\n4. " << option4;

	while (running == true)
	{
		cout << "What would you like to do? ";
		getline(cin, x);

		while (x != "1" && x != "2" && x != "3" && x != "4")
		{
			cout << "The selected option is invalid. ";
			cout << "enter correct input: ";
			cin.clear();
			getline(cin, x);
		}

		if (x == "1")
		{
			bool Option1 = true;
			input();
		}

		else if (x == "2")
		{
			printRecent();
		}

		else if (x == "3")
		{
			cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl;
			printHistory();
		}

		else if (x == "4")
		{
			cout << "You have exited the app";
			running = false;

		}
	}
}

HealthTracker::~HealthTracker()
{
	delete[] history;
}