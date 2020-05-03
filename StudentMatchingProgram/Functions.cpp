#include "Functions.h"

using namespace std;

//User Defined Operators

struct less_than_key
{
	inline bool operator()(Selections &project1, Selections &project2)
	{
		return (project1.getSupervisorID() < project2.getSupervisorID());
	}
}; 

struct equal_to_key
{
	inline bool operator()(Selections &project1, Selections &project2)
	{
		return(project1.getSupervisorID() == project2.getSupervisorID());
	}
};

//Fill and Print Functions

void fillStudentVector(vector<Student> &input)
{
	string filename;
	cout << "Student Filename: " << endl;
	cin >> filename;

	ifstream inFile;
	inFile.open(filename.c_str());

	if (!inFile.is_open())
	{
		cout << "ERROR with file" << endl;
	}


	while (!inFile.eof())
	{
		string row;
		getline(inFile, row);
		stringstream ss(row);

		Student a;

		string name;
		string regnumber;
		string idnumber;
		string choice;
		string status;
		string mail;

		while (!ss.eof())
		{

			getline(ss, idnumber, ',');
			getline(ss, name, ',');
			getline(ss, regnumber, ',');
			getline(ss, status, ',');
			getline(ss, mail, ',');
			getline(ss, choice, '\n');

			int nameval = atoi(name.c_str());
			a.setStudentName(nameval);
			int regval = atoi(regnumber.c_str());
			a.setStudentRegNum(regval);
			int idval = atoi(idnumber.c_str());
			a.setStudentID(idval);
			int choiceval = atoi(choice.c_str());
			a.setStudentRegStatus(status);
			a.setStudentEmail(mail);

			input.push_back(a);
		}

	}
	inFile.close();
}

void printStudentVector(vector<Student> &input)
{
	int size = input.size();

	for (int i = 1; i < size - 1; i++)
	{
		cout << input[i].getStudentName() << endl;
		cout << input[i].getStudentRegNum() << endl;
		cout << input[i].getStudentID() << endl;
		cout << input[i].getStudentRegStatus() << endl;
		cout << input[i].getStudentEmail() << endl;
		input[i].getStudentChoices();
	}
}

//Fills an integer vector of all staff members ID numbers
void fillSupervisorVector(vector<Supervisor> &input, vector<int> &AllStaff)
{
	string filename;
	cout << "Supervisor Filename: " << endl;
	cin >> filename;

	ifstream inFile;
	inFile.open(filename.c_str());

	if (!inFile.is_open())
	{
		cout << "ERROR with file" << endl;
	}


	while (!inFile.eof())
	{
		string row;
		getline(inFile, row);
		stringstream ss(row);

		Supervisor a;

		string id;
		string nameval;
		string job;
		string department;
		string mail;
		string projects;
		string availableprojects;

		while (!ss.eof())
		{

			getline(ss, id, ',');
			getline(ss, nameval, ',');
			getline(ss, job, ',');
			getline(ss, department, ',');
			getline(ss, mail, ',');
			getline(ss, projects, ',');
			getline(ss, availableprojects, '\n');

			int idval = atoi(id.c_str());
			a.setSupervisorID(idval);
			a.setSupervisorName(nameval);
			a.setSupervisorJob(job);
			a.setDepartment(department);
			a.setSupervisorEmail(mail);
			int numprojects = atoi(projects.c_str());
			a.setNumberOfProjects(numprojects);
			int availableprojectsint = atoi(availableprojects.c_str());
			a.setAvailableProjects(availableprojectsint);

			AllStaff.push_back(idval);
			input.push_back(a);
		}

	}
	inFile.close();
}  

//Fills an integer vector of index value of Selections Vector size(used for random iteration)
void fillSelectionVector(vector<Selections> &input, vector<int> &sizeofselections)
{
	string filename;
	cout << "Selections Filename: " << endl;
	cin >> filename;

	ifstream inFile;
	inFile.open(filename.c_str());

	if (!inFile.is_open())
	{
		cout << "ERROR with file" << endl;
	}

	int i = 0;

	while (!inFile.eof())
	{
		string row;
		getline(inFile, row);
		stringstream ss(row);
		Selections a;          //Create temporary Object of Selections
		i = i++;				//Increment i to fill index vector
		string studID;
		string studName;
		string RegNum;

		string projid;

		string Class;

		string projname;
		string supervisorid;
		string supervisorname;
		string selection;

		while (!ss.eof())
		{
			getline(ss, studID, ',');
			getline(ss, studName, ',');
			getline(ss, RegNum, ',');

			getline(ss, projid, ',');

			getline(ss, Class, ',');

			getline(ss, projname, ',');
			getline(ss, supervisorid, ',');
			getline(ss, supervisorname, ',');
			getline(ss, selection, '\n');

			int studentID = atoi(studID.c_str());
			a.setStudentID(studentID);
			int studentname = atoi(studName.c_str());
			a.setStudentName(studentname);
			int studentregnum = atoi(RegNum.c_str());
			a.setStudentRegNum(studentregnum);
			int idproject = atoi(projid.c_str());
			a.setProjectID(idproject);
			a.setClass(Class);
			a.setProjectName(projname);
			int superid = atoi(supervisorid.c_str());
			a.setSupervisorID(superid);
			a.setSupervisorName(supervisorname);

			input.push_back(a);    //Selections destructor called here
			sizeofselections.push_back(i - 1);
		}
	}
	inFile.close();
}

//Main Algorithm for Topic Allocation
void AllocationFunction(vector<Selections> &choicelist, vector<int> &sizeofvector,vector<int> &allocatedstudents,vector<int> &allocatedstaff,vector<int> &allocatedprojects,vector<int> &unallocatedstudents,vector<int> &unallocatedstaff,vector<int> &unallocatedprojects,int maxsupervisorlimit, int maxprojectlimit)

	//Currently 6 empty lists at the beginning of the function
{
	int previousStudentName;
	int previousProjectID;
	int previousStaffID;

	random_shuffle(sizeofvector.begin(), sizeofvector.end());
	for (vector<int>::iterator it = sizeofvector.begin(); it != (sizeofvector.end()-1); it++)
	 {
		if(*it != 0)
		{
		previousStudentName = choicelist[*it].getStudentName();
		previousStaffID = choicelist[*it].getSupervisorID();
		previousProjectID = choicelist[*it].getProjectID();
		
		if (find(allocatedstudents.begin(), allocatedstudents.end(), previousStudentName) != allocatedstudents.end())
		{
			//Student has been Assigned Already. Moving to Next Check
		}
		else if ((count(allocatedstaff.begin(), allocatedstaff.end(), previousStaffID) > (maxsupervisorlimit -1)))
		{
			//Staff has too many students. Cannot Allocate this student this Project
			if (find(allocatedstudents.begin(), allocatedstudents.end(), previousStudentName) != allocatedstudents.end()){} // check again if student exists in allocated vector
			else
			{
				//pushback unallocated list with information
				unallocatedstudents.push_back(previousStudentName);
				unallocatedstaff.push_back(previousStaffID);
				unallocatedprojects.push_back(previousProjectID);
			}
		}
		else if ((count(allocatedprojects.begin(), allocatedprojects.end(), previousProjectID) > (maxprojectlimit - 1)))
		{
			//Project Has already been assigned to a student, pushnback on unallocated vector so a second pass can be made
			unallocatedstudents.push_back(previousStudentName);
			unallocatedstaff.push_back(previousStaffID);
			unallocatedprojects.push_back(previousProjectID);
		}
		else
		{
			//Student can be allocated with project based on constraints, push allocated vector back with information.
			allocatedstudents.push_back(previousStudentName);
			allocatedstaff.push_back(previousStaffID);
			allocatedprojects.push_back(previousProjectID);	
		}
	}
	}
}

//Second pass algorithm to allocated as many unallocated students as possible to supervisors that are available
void AllocateUnallocatedStudents(vector<int> &AllocatedStudentName, vector<int> &AllocatedProjectID, vector<int> &AllocatedStaffName, vector<int> &UnallocatedStudents, vector<int> &UnallocatedProject, vector<int> &UnallocatedStaff, vector<int> &staffnamevector, int maxsupervisorlimit, int maxprojectlimit)
{
	int AllStaffNames;
	int unallocatedstudentname;
	int UnallocatedStaffName;
	int unallocatedproject;

	for (int i = 1; i < UnallocatedStudents.size(); i++) 
	{
		unallocatedstudentname = UnallocatedStudents[i];
		unallocatedproject = UnallocatedProject[i];
		UnallocatedStaffName = UnallocatedStaff[i];

		for (int j = 1; j < staffnamevector.size(); j++)
		{
			AllStaffNames = staffnamevector[j];

			if (find(AllocatedStudentName.begin(), AllocatedStudentName.end(), unallocatedstudentname) != AllocatedStudentName.end())
			{
				//Student has already been Assigned
			}
			else
			{
				if (count(AllocatedProjectID.begin(), AllocatedProjectID.end(), unallocatedproject) < (maxprojectlimit)) //
				{
					//Project Available
					if (count(AllocatedStaffName.begin(), AllocatedStaffName.end(), AllStaffNames) < (maxsupervisorlimit))
					{
						//Student can be allocated 
						AllocatedProjectID.push_back(unallocatedproject);
						AllocatedStudentName.push_back(unallocatedstudentname);
						AllocatedStaffName.push_back(AllStaffNames);
					}
					else
					{
						//Supervisor is still oversuscribed so
						if (find(staffnamevector.begin(), staffnamevector.end(), AllStaffNames) != staffnamevector.end())
						{
							//Remove the staff member from the list o it cannot be iterated again
							staffnamevector.erase(remove(staffnamevector.begin(), staffnamevector.end(), AllStaffNames), staffnamevector.end());

							//push_back the unallocated lists with details
							UnallocatedProject.push_back(unallocatedproject);
							UnallocatedStudents.push_back(unallocatedstudentname);
							UnallocatedStaff.push_back(AllStaffNames);
						}
					continue;
					}
				}

			}
		}
	}
}

//Function will organise the list of students that remain unallocated so they can be written to a seperate file
void tidyUnallocatedStudents(vector<int> &AllocatedStudentName, vector<int> &UnallocatedStudents)
{
	int unallocatedstudentname;;

	for (int i = 0; i < UnallocatedStudents.size() - 1; i++) 
	{
		unallocatedstudentname = UnallocatedStudents[i];

			if (find(AllocatedStudentName.begin(), AllocatedStudentName.end(), unallocatedstudentname) != AllocatedStudentName.end())
			{
				UnallocatedStudents.erase(remove(UnallocatedStudents.begin(), UnallocatedStudents.end(), unallocatedstudentname), UnallocatedStudents.end());
			}
	}
} 

//Function to determine the default supervisor limit of students given (nstudents/nstaff+1)
float defaultSupervisorValue(vector<Supervisor> &supervisorvector, vector<Student> &studentvector)
{
	float i = (studentvector.size() / supervisorvector.size()) + 1;

	return i;
}

//Function to remove duplicates from an integer vector
void removeduplicates(vector<int> &input)
{
	sort(input.begin(), input.end());
	vector<int>::iterator it;
	it = unique(input.begin(), input.end());
	input.resize(distance(input.begin(), it));
}



