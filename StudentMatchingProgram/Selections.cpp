#include <iostream>
#include "Selections.h"
#include <string>

using namespace std;
//Constructors and Destructor

Selections::Selections() {};

Selections::Selections(int a, string b)   
{
	a = ProjectID;
	b = ProjectName;
}

Selections::~Selections(){}

//Setters

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

//Getters

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