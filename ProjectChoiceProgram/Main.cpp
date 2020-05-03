#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Supervisor.h"
#include "Student.h"
#include "Selections.h"
#include "Project_Functions.h"
using namespace std;

int main()
{
	vector<Student> StudentObjectVector;
	vector<Selections> SelectionsObjectVector;

	//Fill and Sort Selection Vector Objects//

	fillSelectionVector(SelectionsObjectVector);
	sortSelectionVector(SelectionsObjectVector);
	removeDuplicates(SelectionsObjectVector);
	sortSupervisorSelectionVector(SelectionsObjectVector);

	//Fill and Diplay Student Vector Objects//

	fillStudentVector(StudentObjectVector);

	//Student Limits//
	int projectchoicelimit;
	int supervisorlimit;
	cout << "Enter how many project choices a student can make:" << endl;
	cin >> projectchoicelimit;
	cout << "Enter how many projects a student can select by the same supervisor:" << endl;
	cin >> supervisorlimit;
	
	vector <int> choices;
	vector<Selections> Choices;

	for (int studentvectorsize = 0; studentvectorsize < StudentObjectVector.size(); studentvectorsize++)
	{
		int StudentID;
		cout << "Enter your student ID: ";
		cin >> StudentID;

		for (int i = 1; i < StudentObjectVector.size(); i++)
		{
			int prev = StudentObjectVector[i].getStudentID();
			if (prev == StudentID)
			{
				cout << "Hello " << StudentObjectVector[i].getStudentName() << endl;
				cout << "Please choose from " << projectchoicelimit << " projects and no more than " << supervisorlimit << " from the same supervisor." << endl;

				char confirm;
				cout << "Confirm? (y/n)" << endl;
				cin >> confirm;

				if(!(confirm != 'y'))
				{
					cout << "Options presented in format Supervisor ID.Project ID" << endl;
					for (int j = 2; j < SelectionsObjectVector.size(); j++)
					{
						cout << "Option " << j - 1 << ": " << SelectionsObjectVector[j].getSupervisorID() << "." << SelectionsObjectVector[j].getProjectID() << endl;
					}

					for (int k = 0; k < projectchoicelimit; k++)
					{
						int supervisorID, chosenproject;
						cout << "Enter chosen Project ID " << k + 1 << ": "; //Prompts for project choices
						cin >> chosenproject;
						cout << "Enter the matching Supervisor ID " << k + 1 << ": "; //Required for correct output format for file
						cin >> supervisorID;

						Selections ChoiceInformation;  //Create temporary Selections Object for write to file
						ChoiceInformation.setStudentID(StudentID);
						ChoiceInformation.setStudentName(StudentObjectVector[i].getStudentName());
						ChoiceInformation.setStudentRegNum(0);
						ChoiceInformation.setProjectID(chosenproject);
						ChoiceInformation.setClass("0");
						ChoiceInformation.setProjectName("0");
						ChoiceInformation.setSupervisorID(supervisorID);
						ChoiceInformation.setSupervisorName("0");

						Choices.push_back(ChoiceInformation); // Destructor called here
						choices.push_back(chosenproject);
					}
					StudentObjectVector[i].setStudentChoices(choices); // Adds Choices to Student Object
					choices.clear();									// Clears choices vector to be refilled for following student
				}
				else
				{
					break;
				}
			}
		}
		char confirm;
		cout << "Would you like to add another student's choices? (y/n)" << endl;
		cin >> confirm;

		if (!(confirm != 'y'))
		{
			continue;
		}
		else
		{
			break;
		};
	}

	//Print Functions For Obtained Data
	printStudentVector(StudentObjectVector);
	printSelectionVector(Choices);

	//Write to file Function
	writetoAllocationFile(Choices);
		
	char stopchar;
	cin >> stopchar;

	return 0;
}