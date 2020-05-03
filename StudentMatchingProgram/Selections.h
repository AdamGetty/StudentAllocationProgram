#ifndef SELECTIONS_H_
#define SELECTIONS_H_
#include<string>
#include<iostream>
#include "Students.h"
#include "Supervisor.h"

using namespace std;

class Selections : public Student, public Supervisor //Inheritance of public methods from Student and Supervisor Classes
{
private:

	int ProjectID;
	string ProjectName;
	string Class;


public:
	Selections(); //default constructor
	Selections(int, string); //overloaded constructor

	void setProjectID(int);
	void setProjectName(string);
	void setClass(string);

	int getProjectID();
	string getProjectName();
	string getClass();

	~Selections();			//Destructor
};

#endif SELECTIONS_H_

