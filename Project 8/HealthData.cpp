#include "HealthData.h"
#include <iostream>
#include<string>
using namespace std;

HealthData::HealthData()
{
	weight = 0;
	exerciseType = "";
	exerciseTime = 0;
}
HealthData::HealthData(double newWeight, string newExerciseType, int newExerciseTime)
{
	weight = newWeight;
	exerciseType = newExerciseType;
	exerciseTime  = newExerciseTime ;
}
void HealthData::setWeight(double newWeight)
{
	weight = newWeight;
}
void HealthData::setExerciseType(string newExerciseType)
{
	exerciseType = newExerciseType;
}
void HealthData::setExerciseTime(int newExerciseTime)
{
	exerciseTime = newExerciseTime;
}
double HealthData::getWeight()
{
	return weight;
}
string HealthData::getExerciseType()
{
	return exerciseType;
}
int HealthData::getExerciseTime()
{
	return exerciseTime;
}
void HealthData::print()
{
	cout << "Weight: " << weight;
	cout << "kg" << endl << "Exercise: " << exerciseType << " (" << exerciseTime<< " mins)" << endl;
}