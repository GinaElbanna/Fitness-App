#include<iostream>
#include<string>
using namespace std;

int main()
{
	string name;
	cout << "Enter Name: ";
	getline(cin, name);

	string gender;
	cout << "Enter Gender: ";
	cin >> gender;

	int age;
	cout << "Enter age: ";
	cin >> age;
	cout << "Extraction unsuccessful? " << cin.fail() << endl;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter numerical value for age: ";
		cin >> age;
	}

	double height;
	cout << "Enter height: ";
	cin >> height;
	cout << "Extraction unsuccessful? " << cin.fail() << endl;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter numerical value for height: ";
		cin >> height;
	}

	string x;
	cout << "For this program you can add data, print data, or exit the program. "
		<< "\nWhat would you like to do? ";
	cin.ignore(1000, '\n');
	getline(cin, x);

	double weight = 0;
	string extype = "";
	int extime = 0;
	bool option1 = false;

	while (x != "exit the program")
	{
		if (x == "add data")
		{
			option1 = true;

			cout << "Enter weight: ";
			cin >> weight;
			cout << "Extraction Unsuccessful?" << cin.fail() << endl;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter a numerical value for weight: ";
				cin >> weight;
			}
			cout << "Enter Exercise Type: ";
			cin.clear();
			cin.ignore(1000, '\n');
			getline(cin, extype);

			cout << "Enter Exercise time: ";
			cin >> extime;
			cout << "Extraction unsuccessful? " << cin.fail() << endl;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter numerical value for exercise time: ";
				cin >> extime;
			}
			cin.ignore(1000, '\n');
		}
		else if (x == "print data")
		{
			if (option1 == true)
			{
				cout << '\n';
				cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl
					<< "Weight: " << weight << "kg" << endl << "Excercise: " << extype << " (" << extime << " mins)" << endl;
			}
			else
			{
				cout << "There is no fitness data to print. \n";
			}
		}
		else
		{
			cout << "The selected option is invalid.\n";
		}
		cout << "What would you like to do? ";
		getline(cin, x);
	}
	cout << "You have exited the app";
	return 0;
}