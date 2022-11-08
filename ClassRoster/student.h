#include <string>
#include <array>
#include <iostream>
#include "degree.h"

using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* daysInCourse;
	DegreeProgram degreeProgram;


public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	~Student();

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int element, int days);
	void setDegreeProgram(DegreeProgram degreeProgram);
	void Print() const;


	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram() const;
};