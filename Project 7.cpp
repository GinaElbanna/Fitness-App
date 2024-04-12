/*The implementation requires a structure data type to represent one record of fitness data, including members: weight, exercise type and exercise time.
Instead of several arrays in Project 6, for this project, only one array of the structure type is needed.*/

#include<iostream>
#include<string>
using namespace std;

const int DAY = 7;

struct Exercise
{
	double weight;
	string extype;
	int extime;
};

void shiftArrayToTheLeft(Exercise Array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		Array[i] = Array[i + 1];
	}
}

int getIntegerInput()
{
	int input;
	//cout << "Enter an integer: ";
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "It is not a valid integer! Try one more time: ";
		cin >> input;
	}
	return input;
}

double getDoubleInput()
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

void getBasicInfo(string& name, string& gender, int& age, double& height)
{
	cout << "Enter Name: ";
	getline(cin, name);

	cout << "Enter Gender: ";
	cin >> gender;

	cout << "Enter age: ";
	age = getIntegerInput();

	cout << "Enter height: ";
	height = getDoubleInput();
}

void printMenu()
{
	string Option1 = "add data, ";
	string Option2 = "print data, ";
	string Option3 = "exit the program, ";
	string option4 = "Print History Data.\n";
	cout << "You can " << Option1 << Option2 << Option3 << option4;
}

void inputData(Exercise exercise[], int& day, int days)
{
	cout << "\nDay " << day + 1 << ": " << endl;
	if (day < days)
	{
		cout << "Enter weight: ";
		exercise[day].weight = getDoubleInput();

		cout << "Enter Exercise Type: ";
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, exercise[day].extype);

		cout << "Enter Exercise time: ";
		exercise[day].extime = getIntegerInput();

		cout << endl;
	}
	else
	{
		shiftArrayToTheLeft(exercise, days);

		cout << "Enter weight: ";
		exercise[days - 1].weight = getDoubleInput();

		cout << "Enter Exercise Type: ";
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, exercise[days - 1].extype);

		cout << "Enter Exercise time: ";
		exercise[days - 1].extime = getIntegerInput();

		cout << endl;
	}
	day++;
}

void printHistory(Exercise exercise[], int AmountOfDays) {
	for (int i = AmountOfDays - 1; i >= 0; i--)
	{
		cout << "\nDay " << i + 1 << ": " << endl;

		cout << "Weight: " << exercise[i].weight << "kg" << endl
			<< "Exercise: " << exercise[i].extype << " (" << exercise[i].extime << " mins)" << endl
			<< endl;
	}
}

void printData(string name, string gender, int age, double height, Exercise exercise[], int& LastDayDataWasEntered, int days)
{

	cout << '\n';
	if (LastDayDataWasEntered < days)
	{
		cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl
			<< "Weight: " << exercise[LastDayDataWasEntered - 1].weight;
		cout << "kg" << endl << "Exercise: " << exercise[LastDayDataWasEntered - 1].extype 
			<< " (" << exercise[LastDayDataWasEntered - 1].extime<< " mins)" << endl;
	}
	else
	{
		cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl
			<< "Weight: " << exercise[days - 1].weight;
		cout << "kg" << endl << "Exercise: " << exercise[days - 1].extype 
			<< " (" << exercise[days - 1].extime << " mins)" << endl;
	}
}

string selectMenu()
{
	cout << "What would you like to do? ";

	string x;
	getline(cin, x);

	while (x != "add data" && x != "print data" && x != "exit the program" && x != "Print History Data")
	{
		cout << "The selected option is invalid. ";
		cout << "enter correct input: ";
		cin.clear();
		getline(cin, x);
	}
	return x;
}

int main()
{
	string x;
	bool option1 = false;

	string name;
	string gender;
	int age = 0;
	double height = 0;

	getBasicInfo(name, gender, age, height);
	cin.ignore(1000, '\n');

	int day = 0;
	int* days = new int;

	cout << "How many days would you like to keep track of? ";
	cin >> *days;
	cin.ignore(1000, '\n');

	Exercise* exercise = new Exercise[*days];

	printMenu();

	while (x != "exit the program")
	{
		x = selectMenu();

		if (x == "add data")
		{
			option1 = true;

			inputData(exercise, day, *days);
			cin.ignore(1000, '\n');
		}
		else if (x == "print data")
		{
			cout << "Day " << day << endl;
			if (option1 == true)
			{
				printData(name, gender, age, height, exercise, day, *days);
			}
			else
			{
				cout << "There is no fitness data to print. \n";
			}
		}
		else if (x == "Print History Data")
		{
			if (option1 == true)
			{

				cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl;

				if (day < *days)
				{
					cout << endl;
					printHistory(exercise, day);
				}
				else
				{
					cout << endl;
					printHistory(exercise, *days);
				}

			}
			else
				cout << "no fitness data to print. \n";
		}
	}
	cout << "You have exited the app";

	delete[] exercise;
	delete days;
	return 0;
}