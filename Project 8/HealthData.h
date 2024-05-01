#pragma once
#include<iostream>
#include <string>
using namespace std;

class HealthData
{
private:
	double weight;
	string exerciseType;
	int exerciseTime;

public:
	HealthData();
	HealthData(double newWeight, string newExerciseType, int newExerciseTime);
	void setWeight(double newWeight);
	void setExerciseType(string newExerciseType);
	void setExerciseTime(int newExerciseTime);
	double getWeight();
	string getExerciseType();
	int getExerciseTime();
	void print();
};

