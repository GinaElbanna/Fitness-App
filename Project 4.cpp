#include<iostream>
#include<string>
using namespace std;

int getIntegerInput()
{
	int input;
	//cout << "Enter an integer: ";
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "It is not a vaid inreger! Try one more time: ";
		cin >> input;
	}
	return input;
}

double getDoubleInput()
{
	double input;
	//cout << "Enter an integer: ";
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "It is not a vaid input! Try one more time: ";
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
	string Option3 = "exit the program.\n";
	cout << "You can " << Option1 << Option2 << Option3;
}

void inputData(double& weight, string& extype, int& extime)
{
	extype = "";

	cout << "Enter weight: ";
	weight = getDoubleInput();

	cout << "Enter Exercise Type: ";
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, extype);

	cout << "Enter Exercise time: ";
	extime = getIntegerInput();
}

void printData(string name, string gender, int age, double height, double weight, string extype, int extime)
{
	cout << '\n';
	cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl
		<< "Weight: " << weight << "kg" << endl << "Excercise: " << extype << " (" << extime << " mins)" << endl;
}

string selectMenu()
{  
	cout << "What would you like to do? ";

	string x;
	getline(cin, x);

	while (x != "add data" && x != "print data" && x != "exit the program")
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
	int age;
	double height;

	double weight;
	string extype ;
	int extime ;

	getBasicInfo(name, gender, age, height);

	printMenu();
	cin.ignore(1000, '\n');

	while (x != "exit the program")
	{
		x = selectMenu();

		if (x == "add data")
		{
			inputData(weight, extype, extime);
			option1 = true;
			cin.ignore(1000, '\n');
		}
		else if (x == "print data")
		{
			if (option1 == true)
			{
				printData(name, gender, age, height, weight, extype, extime);
			}
			else
			{
				cout << "There is no fitness data to print. \n";
			}
		}
	}
	cout << "You have exited the app";
	return 0;
}