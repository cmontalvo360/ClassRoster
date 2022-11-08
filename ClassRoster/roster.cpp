#include "roster.h"
#include <sstream>
#include <vector>
#include <regex>
#include <iostream>
#include <string>

using namespace std;

Roster::Roster() {
};

Roster::~Roster() {
};

// parses student data, creates students and adds to classRoster array
void Roster::parse(string str) {
	string studentID, firstName, lastName, emailAddress;
	int age, days1, days2, days3;
	DegreeProgram degreeProgram = NETWORK;
	vector<string> result;

	stringstream ss(str);
	while (ss.good()) {
		string substr;
		getline(ss, substr, ',');
		result.push_back(substr);
	}

	studentID = result.at(0);
	firstName = result.at(1);
	lastName = result.at(2);
	emailAddress = result.at(3);
	age = stoi(result.at(4));
	days1 = stoi(result.at(5));
	days2 = stoi(result.at(6));
	days3 = stoi(result.at(7));

	if (result.at(8) == "NETOWRK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (result.at(8) == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (result.at(8) == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, degreeProgram);
};

// creates student and adds to roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int dayInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int index = int(studentID.at(1)-48);
	student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, dayInCourse2, daysInCourse3, degreeProgram);
	classRosterArray[index - 1] = student;
};

// removes student by deleting pointer and setting to nullptr
void Roster::remove(string studentID) {
	bool found = false;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			cout << "Removed student with ID: " << studentID << endl;
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			found = true;
		}
	}

	if (!found) {
		cout << "student with ID " << studentID << " wasnt found!" << endl;
	}
	cout << endl;
};

void Roster::printAll() {
	cout << "Displaying all students:" << endl;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
	}

	cout << endl;
};

void Roster::printAverageDaysInCourse(string studentID) {
	int id = int(studentID.at(1) - 48);
	int* days;
	
	days = classRosterArray[id-1]->getDaysInCourse();
	int sum = 0;

	for (int i = 0; i < 3; i++) {
		sum += days[i];
	}

	int avg = sum / 3;

	cout << "Student ID: " << studentID << ", average days in course is: " << avg << endl;
};

void Roster::printInvalidEmails() {

	cout << "Displaying invalid emails:" << endl << endl;
	const regex pattern( "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.((\\w+))+)" );

	for (int i = 0; i < 5; i++) {
		if (!regex_match(classRosterArray[i]->getEmailAddress(), pattern)) {
			cout << classRosterArray[i]->getEmailAddress() << " invalid email" << endl;
		}
	}
	cout << endl;
};

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	string program;

	switch (degreeProgram) {
	case DegreeProgram::NETWORK: program = "NETWORK";
		break;
	case DegreeProgram::SECURITY: program = "SECURITY";
		break;
	case DegreeProgram::SOFTWARE: program = "SOFTWARE";
		break;
	}

	cout << endl << "Showing students in degree program: " << program << endl << endl;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->Print();
		}
	}
	cout << endl;
};

Student* Roster::getClassRosterArray() {
	static Student arr[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = *classRosterArray[i];
	}

	return arr; };
