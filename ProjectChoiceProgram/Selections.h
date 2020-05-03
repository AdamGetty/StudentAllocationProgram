#ifndef SELECTIONS_H_
#define SELECTIONS_H_
#include<string>
#include<iostream>
#include "Student.h"
#include "Supervisor.h"

using namespace std;

class Selections : public Student, public Supervisor // Inheritance from public access specifiers in Supervisor and Student Classes
{
private:

	int ProjectID;
	string ProjectName;
	string Class;


public:
	Selections();				//default constructor
	Selections(int, string);	//overloaded constructor

	//Setter methods used to assign data to private data members.

	void setProjectID(int);
	void setProjectName(string);
	void setClass(string);

	//Getter methods used to extract data from private data members.

	int getProjectID();
	string getProjectName();
	string getClass();

	~Selections(); //Destructor

};

#endif SELECTIONS_H_

