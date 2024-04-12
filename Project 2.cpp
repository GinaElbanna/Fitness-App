#include <iostream>
#include <string>
using namespace std;

int main() {
	string name;
	cout << "Enter Name: ";
	getline(cin, name);

	string gender;
	cout << "Enter Gender: ";
	cin >> gender;

	int age = 428;
	cout << "Enter age: ";
	cin >> age;
	cout << "Extraction unsuccessful? " << cin.fail() << endl;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter Int value for your age: ";
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

	double weight;
	cout << "Enter weight: ";
	cin >> weight;
	cout << "Extraction Unsuccessful?" << cin.fail() << endl;

	while (cin.fail()) {
		cin.clear();
		cout << "Enter a numerical value for weight: ";
		cin >> weight;
	}

	string extype;
	cout << "Enter Exercise Type: ";
	cin.ignore(1000, '\n');
	cin >> extype;

	int extime;
	cout << "Enter Exercise time: ";
	cin.ignore(1000, '\n');
	cin >> extime;
	cout << "Extraction unsuccessful? " << cin.fail() << endl;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter numerical value for exercise time: ";
		cin >> extime;
	}
	cout << '\n';
	cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl << "Weight: " << weight << "kg" << endl << "Excercise: " << extype << " (" << extime << " mins)";
	return 0;
}