#include <iostream>
#include <string>
using namespace std;

int main() {
	string name = "Bartholomew";
	string gender = "F";
	int age = 428;;
	double height = 1.94;
	double weight = 69;
	string extype = "Walking";
	int extime = 30;

	cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl << "Weight: " << weight << "kg" << endl << "Excercise: " << extype << " (" << extime << " mins)";
}