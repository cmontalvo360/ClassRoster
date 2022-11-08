#include "student.h"
using namespace std;

Student::Student()
	: age(0),
	daysInCourse{},
	degreeProgram(SOFTWARE) {
};

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) :
	studentID(studentID),
	firstName(firstName),
	lastName(lastName),
	emailAddress(emailAddress),
	age(age),
	degreeProgram(degreeProgram) {
	daysInCourse = new int[3] {daysInCourse1, daysInCourse2, daysInCourse3};
};

Student::~Student() {
};

//setters
void Student::setStudentID(string studentID) { this->studentID = studentID; };
void Student::setFirstName(string firstName) { this->firstName = firstName; };
void Student::setLastName(string lastName) { this->lastName = lastName; };
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; };
void Student::setAge(int age) { this->age = age; };
void Student::setDaysInCourse(int element, int days) { this->daysInCourse[element] = days; };
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; };
void Student::Print() const {
	string days = "{";
	string program;

	for (int i = 0; i < 3; i++) {
		days += to_string(daysInCourse[i]);
		if (i < 2) {
			days += ",";
		}
	}
	days += "}";

	switch (degreeProgram) {
	case DegreeProgram::NETWORK: program = "NETWORK";
		break;
	case DegreeProgram::SECURITY: program = "SECURITY";
		break;
	case DegreeProgram::SOFTWARE: program = "SOFTWARE";
		break;
	}

	cout << studentID << " ";
	cout << firstName << " ";
	cout << lastName << " ";
	cout << age << " "; 
	cout << days << " ";
	cout << program << endl;
};

//getters
string Student::getStudentID() const { return studentID; };
string Student::getFirstName() const { return firstName; };
string Student::getLastName() const { return lastName; };
string Student::getEmailAddress() const { return emailAddress; };
int Student::getAge() const { return age; };
int* Student::getDaysInCourse() { return daysInCourse; };
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; };