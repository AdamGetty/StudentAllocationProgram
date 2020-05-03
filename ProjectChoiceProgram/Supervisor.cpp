#include <iostream>
#include "Supervisor.h"
using namespace std;

//Constructors

Supervisor::Supervisor() {}

Supervisor::Supervisor(int a, string b, string c, string d, string e, int f, int g)
{
	a = ID;
	b = Name;
	c = Job;
	d = Department;
	e = Email;
	f = Projects;
	g = AvailableProjects;
}

/*Supervisor::~Supervisor()				//Update as necessay
{
cout << "Student Removed" << endl;
}*/

//Setter Methods

void Supervisor::setSupervisorName(string a)
{
	Name = a;
}

void Supervisor::setSupervisorJob(string a)
{
	Job = a;
}

void Supervisor::setSupervisorID(int a)
{
	ID = a;
}

void Supervisor::setNumberOfProjects(int a)
{
	Projects = a;
}

void Supervisor::setDepartment(string a)
{
	Department = a;
}

void Supervisor::setSupervisorEmail(string a)
{
	Email = a;
}

void Supervisor::setAvailableProjects(int a)
{
	AvailableProjects = a;
}

//Getter Methods

string Supervisor::getSupervisorName()
{
	return Name;
}

string Supervisor::getSupervisorJob()
{
	return Job;
}

int Supervisor::getSupervisorID()
{
	return ID;
}

string Supervisor::getDepartment()
{
	return Department;
}

string Supervisor::getSupervisorEmail()
{
	return Email;
}

int Supervisor::getNumberOfProjects()
{
	return Projects;
}

int Supervisor::getAvailableProjects()
{
	return AvailableProjects;
}

Supervisor::~Supervisor() {};