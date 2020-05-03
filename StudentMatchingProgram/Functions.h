#ifndef _PROJECT_FUNCTIONS_H_
#define _PROJECT_FUNCTIONS_H_

#include <vector>
#include <string>  
#include <algorithm>
#include "Students.h"
#include "Supervisor.h"
#include "Selections.h"

using namespace std;

void printStudentVector(vector<Student> &input);

void fillStudentVector(vector<Student> &input);

void fillSupervisorVector(vector<Supervisor> &input, vector<int> &AllStaff);

void fillSelectionVector(vector<Selections> &input, vector<int> &sizeofselections);

void AllocationFunction(vector<Selections> &choicelist, vector<int> &sizeofvector, vector<int> &AllocatedStudentName, vector<int> &AllocatedProjectID, vector<int> &AllocatedStaffID, vector<int> &UnallocatedStudents, vector<int> &UnallocatedStaff, vector<int> &UnallocatedProject, int maxsupervisorlimit, int maxprojectlimit);

void AllocateUnallocatedStudents(vector<int> &AllocatedStudentName, vector<int> &AllocatedProjectID, vector<int> &AllocatedStaffName, vector<int> &UnallocatedStudents, vector<int> &UnallocatedProject, vector<int> &UnallocatedStaff, vector<int> &staffnamevector, int maxsupervisorlimit, int maxprojectlimit);

void tidyUnallocatedStudents(vector<int> &AllocatedStudentName, vector<int> &UnallocatedStudents);

float defaultSupervisorValue(vector<Supervisor> &supervisorvector, vector<Student> &studentvector);

void removeduplicates(vector<int> &input);

#endif /*_PROJECT_FUNCTIONS_H_*/


