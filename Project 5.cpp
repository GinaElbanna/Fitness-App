/*Mar Elbanna
*/

/*Extend the functionality of Project 4 to store and view weekly fitness data (assume each input is for one day):
store a history of up to 7 most recent fitness data inputs (i.e., weight, exercise type and time). If there are more than 7 inputs via selecting option 1 multiple times, the program just saves the 7 most recent ones. If there are less than 7 inputs, then save the exact number of inputs.
add an additional option ‘Print History Data’ in the text menu to print the history of inputs from the most recent one to the oldest one. The output format of individual fitness data is the same as option 2 in previous projects.
if users have never selected option 1 before selecting this new option, show a message ‘no fitness data to print.’
if there is data to print, just print users’ name, gender, age, and height once before printing history data
if there are less than 7 inputs, e.g., 3, then just print 3 inputs.
if there are at least 7 inputs, print the 7 most recent ones.
*/

#include<iostream>
#include<string>
using namespace std;

const int DAY = 7;

void shiftArrayToTheLeft(double Array1[], string Array2[], int Array3[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		Array1[i] = Array1[i + 1];
		Array2[i] = Array2[i + 1];
		Array3[i] = Array3[i + 1];
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

void inputData(double weights[], string extypes[], int extimes[], int& day)
{
	cout << "\nDay " << day + 1 << ": " << endl;
	if (day < 7)
	{
		cout << "Enter weight: ";
		weights[day] = getDoubleInput();

		cout << "Enter Exercise Type: ";
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, extypes[day]);

		cout << "Enter Exercise time: ";
		extimes[day] = getIntegerInput();

		cout << endl;
	}
	else
	{
		shiftArrayToTheLeft(weights, extypes, extimes, DAY);

		cout << "Enter weight: ";
		weights[6] = getDoubleInput();

		cout << "Enter Exercise Type: ";
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, extypes[6]);

		cout << "Enter Exercise time: ";
		extimes[6] = getIntegerInput();


		cout << endl;
	}
	day++;
}

void printHistory(double weights[], string extypes[], int extimes[], int AmountOfDays) {
	for (int i = AmountOfDays - 1; i >= 0; i--)
	{
		cout << "\nDay " << i + 1 << ": " << endl;

		cout << "Weight: " << weights[i] << "kg" << endl
			<< "Exercise: " << extypes[i] << " (" << extimes[i] << " mins)" << endl
			<< endl;
	}
}

void printData(string name, string gender, int age, double height, double weights[], string extypes[], int extimes[], int& LastDayDataWasEntered)
{
	cout << '\n';
	if (LastDayDataWasEntered < 7)
	{
		cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl
			<< "Weight: " << weights[LastDayDataWasEntered - 1];
		cout << "kg" << endl << "Exercise: " << extypes[LastDayDataWasEntered - 1] << " (" << extimes[LastDayDataWasEntered - 1] << " mins)" << endl;
	}
	else 
	{
		cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl
			<< "Weight: " << weights[6];
		cout << "kg" << endl << "Exercise: " << extypes[6] << " (" << extimes[6] << " mins)" << endl;
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

	int day = 0;
	int days = 7;

	double weights[7];
	string extypes[7];
	int extimes[7];
	getBasicInfo(name, gender, age, height);
	cin.ignore(1000, '\n');

	printMenu();

	while (x != "exit the program")
	{
		x = selectMenu();

		if (x == "add data")
		{
			option1 = true;

			inputData(weights, extypes, extimes, day);
			cin.ignore(1000, '\n');
		}
		else if (x == "print data")
		{
			cout << day << endl;
			if (option1 == true)
			{
				printData(name, gender, age, height, weights, extypes, extimes, day);
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

				if (day < 7)
				{
					cout << endl;
					printHistory(weights, extypes, extimes, day);
				}
				else
				{
					cout << endl;
					printHistory(weights, extypes, extimes, 7);
				}

			}
			else
				cout << "no fitness data to print. \n";
		}
	}
	cout << "You have exited the app";
	return 0;
}