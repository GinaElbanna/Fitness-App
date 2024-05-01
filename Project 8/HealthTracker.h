#pragma once
#include "HealthData.h"
#include <iostream>
#include <string>

using namespace std;

class HealthTracker
{
private:
	string name;
	string gender;
	int age;
	double height;
	int size = 0;
	HealthData* history;
	int counter = 0;

public:
	void shiftArrayToTheLeft(HealthData array[], int size);
	static int getIntegerInput();
	static double getDoubleInput();
	HealthTracker(string name, string gender, int age, double height, int historyArraySize);
	~HealthTracker();
	void input();
	void printRecent();
	void printHistory();
	void menu();
};

