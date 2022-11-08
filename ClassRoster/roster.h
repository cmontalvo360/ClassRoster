#include "student.h"

using namespace std;

class Roster {
	private:
		Student* classRosterArray[5];
		Student* student;

	public:
		Roster();
		~Roster();

		void parse(string row);
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int dayInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);

		Student* getClassRosterArray();
};
