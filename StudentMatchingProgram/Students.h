#ifndef STUDENTS_H_
#define STUDENTS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include<vector>

using namespace std;

class Student
{
private:
	int Name;
	int RegNum;
	int ID;
	string RegStatus;
	string Email;
	int Choice;

public:								//Public access Specifiers
	Student();						//default constructor
	Student(int, int, int, int, string, string); //overloaded constructor

	void setStudentName(int);
	void setStudentRegNum(int);
	void setStudentID(int);
	void setStudentRegStatus(string);
	void setStudentEmail(string);
	void setStudentChoices(int choice) { Choice = choice; };

	int getStudentName();
	int getStudentRegNum();
	int getStudentID();
	string getStudentRegStatus();
	string getStudentEmail();
	int getStudentChoices() { return Choice; }

	~Student();  //Destructor
};

#endif /*STUDENTS_H_*/
