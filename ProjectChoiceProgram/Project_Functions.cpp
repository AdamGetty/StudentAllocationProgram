#include "Project_Functions.h"

using namespace std;
//User defined operator to use vector methods on Object Vectors

struct less_than_key  
{
	inline bool operator()(Selections &project1, Selections &project2)
	{
		return (project1.getProjectID() < project2.getProjectID());
	}
};//Thanks to Alan from Stack Exchange post "Sorting a vector of Custom Objects

struct less_than_key_supervisor
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
		return(project1.getProjectID() == project2.getProjectID());
	}
};

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

		Student a; //Creates Temporary Object

		string name;
		string regnumber;
		string idnumber;
		string choice;
		string status;
		string mail;

		while (!ss.eof())
		{
			//Fill Object with information extracted from file.

			getline(ss, idnumber, ',');
			getline(ss, name, ',');
			getline(ss, regnumber, ',');
			getline(ss, status, ',');
			getline(ss, mail, ',');
			getline(ss, choice, '\n');

			int nameval = atoi(name.c_str());  //Cast string to integer for Class data member compatability.
			a.setStudentName(nameval);
			int regval = atoi(regnumber.c_str());
			a.setStudentRegNum(regval);
			int idval = atoi(idnumber.c_str());
			a.setStudentID(idval);
			int choiceval = atoi(choice.c_str());
			a.setStudentRegStatus(status);
			a.setStudentEmail(mail);

			input.push_back(a); //Push back the object into vector, Destructor called here.
		}

	}


	inFile.close();
}

// To confirm data was push_backed in vector list
void printStudentVector(vector<Student> &input)
{
	int size = input.size();

	for (int i = 1; i < size - 1; i++)
	{
		cout << "Student: " << input[i].getStudentName() << endl;
		input[i].getStudentChoices();
		cout << "************************************" << endl;
	}
} 

void fillSupervisorVector(vector<Supervisor> &input)
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
			int regval = atoi(projects.c_str());
			a.setNumberOfProjects(regval);
			int availableprojectsint = atoi(availableprojects.c_str());
			a.setAvailableProjects(availableprojectsint);


			input.push_back(a);
		}

	}


	inFile.close();
}

void printSupervisorVector(vector<Supervisor> &input)
{
	int size = input.size();

	for (int i = 1; i < size - 1; i++)
	{
		cout << "Name: \t\t" << input[i].getSupervisorName() << endl;
		cout << "Job: \t\t" << input[i].getSupervisorJob() << endl;
		cout << "ID: \t\t" << input[i].getSupervisorID() << endl;
		cout << "Department: \t" << input[i].getDepartment() << endl;
		cout << "Email: \t\t" << input[i].getSupervisorEmail() << endl;
		cout << "Projects: \t" << input[i].getNumberOfProjects() << endl;
		cout << "Available Projects: " << input[i].getAvailableProjects() << endl;
	}
}

void fillSelectionVector(vector<Selections> &input)
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


	while (!inFile.eof())
	{
		string row;
		getline(inFile, row);
		stringstream ss(row);

		Selections a;

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


			input.push_back(a);
		}
	}
	inFile.close();
}

void sortSelectionVector(vector<Selections> &input)
{
	sort(input.begin(), input.end(), less_than_key()); // sort using custom overloaded operator
}

void sortSupervisorSelectionVector(vector<Selections> &input)
{
	sort(input.begin(), input.end(), less_than_key_supervisor()); // sort using custom overloaded operator
}

void removeDuplicates(vector<Selections> &input)
{
	vector<Selections>::iterator it;
	it = unique(input.begin(), input.end(), equal_to_key()); //Remove Duplicates using equal_to_key struct(user defined operator)
	input.resize(distance(input.begin(), it));
}

void printSelectionVector(vector<Selections> &input)
{
	int size = input.size();

	for (int i = 0; i < size; i++)
	{
		cout << "Student Name: " << input[i].getStudentName() << "  Student ID: " << input[i].getStudentID() << endl;
		cout << "Project ID: " << input[i].getProjectID() << " Supervisor ID: " << input[i].getSupervisorID() << endl;
	}
}

void writetoAllocationFile(vector<Selections> &ChoicesFile)
{
	string filename;
	cout << "Input filename to write to: " << endl;
	cin >> filename;

	ofstream outFile(filename, ios::app);

	for (int i = 0; i < ChoicesFile.size(); i++)
	{
		outFile << ChoicesFile[i].getStudentID() << "," << ChoicesFile[i].getStudentName() << "," << ChoicesFile[i].getStudentRegNum() << "," << ChoicesFile[i].getProjectID() << "," << ChoicesFile[i].getClass() << "," << ChoicesFile[i].getProjectName() << "," << ChoicesFile[i].getSupervisorID() << "," << ChoicesFile[i].getSupervisorName() <<"," << "0" << "\n";
	}
	outFile.close();
} 



