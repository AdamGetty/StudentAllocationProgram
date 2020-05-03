#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Supervisor.h"
#include "Students.h"
#include "Selections.h"
#include "Functions.h"
#include "Allocation.h"
using namespace std;


int main()
{
	//Initialize Vectors
	vector <Supervisor> SupervisorObjectVector;
	vector<Student> StudentObjectVector;
	vector<Selections> SelectionsObjectVector;
	vector<int> sizeofselections;
	vector<int> AllStaff;

	//Fill Vectors with information from File
	fillSelectionVector(SelectionsObjectVector, sizeofselections);
	fillStudentVector(StudentObjectVector);
	fillSupervisorVector(SupervisorObjectVector, AllStaff);

	//Calculate Default supervisor limit ((nstudents/nstaff)+1)
	cout << SupervisorObjectVector.size() << " " << StudentObjectVector.size() << endl;
	cout << "Maximum students each staff member can supervise defaults to: " << defaultSupervisorValue(SupervisorObjectVector, StudentObjectVector) << endl;

	//Initialize Empty lists to be filled with Allocation/Unallocation Information
	vector<int> AllocatedProjectID;
	vector<int> AllocatedStudentName;
	vector<int> AllocatedStaffID;

	vector<int> UnallocatedStudents;
	vector<int> UnallocatedStaff;
	vector<int> UnallocatedProject;

	//Prompt User for SupervisorChoice and How many Students can be assigned to one project
	int SupervisorUserChoice;
	int ProjectStudentLimit;
	cout << "Enter the number of students a single staff member can supervise: "; 
	cin >> SupervisorUserChoice;
	cout << "Enter the maximum number of students that can be assigned to a single project: ";
	cin >> ProjectStudentLimit;

	//First pass of allocation Algorithm
	int allocations = 0;
	AllocationFunction(SelectionsObjectVector, sizeofselections, AllocatedStudentName, AllocatedStaffID, AllocatedProjectID, UnallocatedStudents, UnallocatedStaff, UnallocatedProject, SupervisorUserChoice, ProjectStudentLimit);
	cout << AllocatedStudentName.size() << endl;
	if (UnallocatedStudents.size() > 0)
	{
		//Second pass to allocate as many unallocated students as possible
		AllocateUnallocatedStudents(AllocatedStudentName, AllocatedProjectID, AllocatedStaffID, UnallocatedStudents, UnallocatedProject, UnallocatedStaff, AllStaff, SupervisorUserChoice, ProjectStudentLimit);

		string filename;
		cout << "Input Filename to write allocated students to: "; 
		cin >> filename;

		ofstream outFile(filename, ios::app);
		cout <<"\n" << "Student Name: " << "\t" << " Allocated Project ID: " << "\t" << " Assigned Supervisor ID: " << endl;
		for (int i = 0; i < AllocatedStudentName.size(); i++)
		{
			allocations = allocations + 1;
			outFile << AllocatedStudentName[i] << "," << AllocatedProjectID[i] << "," << AllocatedStaffID[i] << "\n";
			cout << AllocatedStudentName[i] << "\t\t\t" << AllocatedProjectID[i] << "\t\t\t" << AllocatedStaffID[i] << endl;
		}
		outFile.close();
		cout << "Total number of student allocated is : " << allocations << endl;
	}

	//Sort the Unallocated Student list to provide the names of students who were unallocated
	tidyUnallocatedStudents(AllocatedStudentName, UnallocatedStudents);
	removeduplicates(UnallocatedStudents);
	
	//Print the list of Students who remain without a selection and append them to a file
	string filename;
	cout << "Input Filename to attach the Unallocated Students to: ";
	cin >> filename;

	ofstream outFile(filename, ios::app);

	int unallocations = 0;
	outFile <<  "Unallocated StudentName" << "\n";
	cout << "\n" << "Unallocated Student Name: " << endl;
	for (int i = 0; i < UnallocatedStudents.size(); i++)
	{
		unallocations = unallocations + 1;
		outFile << UnallocatedStudents[i] << "\n";
		cout << UnallocatedStudents[i] << endl;
	}
	cout << "Total number of Students Unallocated is : " << unallocations << endl;
	outFile.close();

	char stopchar;
	cin >> stopchar;

	return 0;

}
