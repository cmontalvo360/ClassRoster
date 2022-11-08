#include <iostream>
#include "roster.h"
using namespace std;

int main()
{
    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Cesar,Montalvo,Cambam12@gmail.com,31,22,40,32,SOFTWARE" };


    cout << "Course: C867 - Scripting & Programming - Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 010770189" << endl;
    cout << "Name: Cesar Montalvo" << endl;
    cout << endl;


    Roster classRoster;


    // parses each string in studentData[] and creates a student object from it and adds to class roster array
    for (string student : studentData) {
        classRoster.parse(student);
    }

    // print all class roster
    classRoster.printAll();

    // print invalid emails
    classRoster.printInvalidEmails();

    // loop through roster print average days in course
    Student* roster = classRoster.getClassRosterArray();
    cout << "Displaying average days in course:" << endl << endl;

    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(roster[i].getStudentID());
    }
    
    // print students by entered degree program
    classRoster.printByDegreeProgram(SOFTWARE);
  
    // remove a student
    classRoster.remove("A3");

    // showing removed student
    classRoster.printAll();

    // try removing same student again
    classRoster.remove("A3");

    return 0;
}