#ifndef SUPERVISOR_H_
#define SUPERVISOR_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


class Supervisor
{
private: //Private access specifier containing instances of Supervisor Data Members
	int ID;
	string Name;
	string Job;
	string Department;
	string Email;
	int Projects;
	int AvailableProjects;

public:
	Supervisor();												//Default constructor
	Supervisor(int, string, string, string, string, int, int); //Overloaded constructor

	//Setter methods used to assign data to private data members.

	void setSupervisorName(string);
	void setSupervisorJob(string);
	void setSupervisorID(int);
	void setNumberOfProjects(int);
	void setDepartment(string);
	void setSupervisorEmail(string);
	void setAvailableProjects(int);

	//Getter methods used to extract data from private data members.

	string getSupervisorName();
	string getSupervisorJob();
	int getSupervisorID();
	string getDepartment();
	string getSupervisorEmail();
	int getNumberOfProjects();
	int getAvailableProjects();

	~Supervisor();
};


#endif /*SUPERVISOR_H_*/
