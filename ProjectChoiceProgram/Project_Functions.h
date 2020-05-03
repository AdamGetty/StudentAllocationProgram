#ifndef _PROJECT_FUNCTIONS_H_
#define _PROJECT_FUNCTIONS_H_

#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include "Student.h"
#include "Supervisor.h"
#include "Selections.h"

//Header file to add to main for Project Functions
using namespace std;

void printStudentVector(vector<Student> &input);

void fillStudentVector(vector<Student> &input);

void fillSupervisorVector(vector<Supervisor> &input);

void printSupervisorVector(vector<Supervisor> &input);

void fillSelectionVector(vector<Selections> &input);

void sortSelectionVector(vector<Selections> &input);

void sortSupervisorSelectionVector(vector<Selections> &input);

void removeDuplicates(vector<Selections> &input);

void printSelectionVector(vector<Selections> &input);

void writetoAllocationFile(vector<Selections> &input);

#endif /*_PROJECT_FUNCTIONS_H_*/


