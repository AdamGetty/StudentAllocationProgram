#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Student
{
private: //Private access specifier containing instances of Supervisor Data Members
	int Name;
	int RegNum;
	int ID;
	string RegStatus;
	string Email;
	vector<int> Choices;

public:
	Student();											//Default Constructor
	Student(int, int, int, vector<int> ,string, string);//Overloaded Constructor

	//Setter methods used to assign data to private data members.

	void setStudentName(int);
	void setStudentRegNum(int);
	void setStudentID(int);
	void setStudentRegStatus(string);
	void setStudentEmail(string);
	void setStudentChoices(vector <int> &choice) { Choices = choice; };

	//Getter methods used to extract data from private data members.

	int getStudentName();
	int getStudentRegNum();
	int getStudentID();
	string getStudentRegStatus();
	string getStudentEmail();

	//Prints out the Student Choices vector

	void getStudentChoices() { for (int i = 0; i < Choices.size(); i++) { cout << "Choice " << i + 1 << " is: " << Choices[i] << endl; } }

	~Student(); //Destructor
};

#endif /*STUDENT_H_*/