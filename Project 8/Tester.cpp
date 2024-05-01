#include"HealthTracker.h"
#include"HealthData.h"
#include<iostream>
using namespace std;

void getBasicInfo(string& name, string& gender, int& age, double& height)
{
	cout << "Enter Name: ";
	getline(cin, name);

	cout << "Enter Gender: ";
	cin >> gender;

	cout << "Enter age: ";
	age = HealthTracker::getIntegerInput();

	cout << "Enter height: ";
	height = HealthTracker::getDoubleInput();
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

	int* size = new int;

	cout << "How many days would you like to keep track of? ";
	*size = HealthTracker::getIntegerInput();

	HealthTracker tracker (name, gender, age, height,* size);

	tracker.menu();

	return 0;
}