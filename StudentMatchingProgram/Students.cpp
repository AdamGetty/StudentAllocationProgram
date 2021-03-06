#include <iostream>
#include <vector>
#include <algorithm>
#include "Students.h"
using namespace std;

//Constructors

Student::Student() {}

Student::Student(int a, int b, int c, int d, string e, string f)
{
	a = Name;
	b = RegNum;
	c = ID;
	d = Choice;
	e = RegStatus;
	f = Email;
}

//Destructor

Student::~Student()	{}

//Setters

void Student::setStudentName(int a)
{
	Name = a;
}

void Student::setStudentRegNum(int a)
{
	RegNum = a;
}

void Student::setStudentID(int a)
{
	ID = a;
}

void Student::setStudentRegStatus(string a)
{
	RegStatus = a;
}

void Student::setStudentEmail(string a)
{
	Email = a;
}

//Getters

int Student::getStudentName()
{
	return Name;
}

int Student::getStudentRegNum()
{
	return RegNum;
}

int Student::getStudentID()
{
	return ID;
}

string Student::getStudentRegStatus()
{
	return RegStatus;
}

string Student::getStudentEmail()
{
	return Email;
}

