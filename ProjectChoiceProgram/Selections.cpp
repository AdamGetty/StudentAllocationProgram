#include <iostream>
#include "Selections.h"
#include <string>

using namespace std;

//Constructors

Selections::Selections() {};

Selections::Selections(int a, string b)    
{
	a = ProjectID;
	b = ProjectName;
}

//Setter Methods

void Selections::setProjectID(int a)
{
	ProjectID = a;
}

void Selections::setProjectName(string a)
{
	ProjectName = a;
}

void Selections::setClass(string a)
{
	Class = a;
}

//Getter Methods

int Selections::getProjectID()
{
	return ProjectID;
}

string Selections::getProjectName()
{
	return ProjectName;
}

string Selections::getClass()
{
	return Class;
}

Selections::~Selections() {}; //Destructor