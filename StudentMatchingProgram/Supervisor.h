#ifndef SUPERVISOR_H_
#define SUPERVISOR_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


class Supervisor
{
private:														//Private access specifiers
	int ID;
	string Name;
	string Job;
	string Department;
	string Email;
	int Projects;
	int AvailableProjects;

public:															//Public access Specifiers
	Supervisor();												//default constructor
	Supervisor(int, string, string, string, string, int, int); //overloaded constructor

	void setSupervisorName(string);
	void setSupervisorJob(string);
	void setSupervisorID(int);
	void setNumberOfProjects(int);
	void setDepartment(string);
	void setSupervisorEmail(string);
	void setAvailableProjects(int);

	string getSupervisorName();
	string getSupervisorJob();
	int getSupervisorID();
	string getDepartment();
	string getSupervisorEmail();
	int getNumberOfProjects();
	int getAvailableProjects();

	~Supervisor(); // destructor
};


#endif /*SUPERVISOR_H_*/
