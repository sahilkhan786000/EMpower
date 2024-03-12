#include<iostream>
#include<windows.h>
#include<unistd.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cstdio>
#include<fstream>

using namespace std;

class EmployeeManagement {
	private:
		char empName[30];
		char empId[5];
		char empDesignation[10];
		int empAge, empCtc;
		char empExperience[20];
		
	public:
		void showMenu();
		void waitForEnter();
		void addRecord();
		void displayRecord();
		void modifyRecord();
		void searchRecord();
		void deleteRecord();
};

void EmployeeManagement::showMenu()
{
	int userPassword();
	userPassword();
	while(true)
	{
		int choice;
		char x;
		system("cls");
			cout << "\n\t\t\t*******************************************************";
			cout << "\n\t\t\t>>               EMPLOYEE MANAGEMENT SYSTEM            <<";
			cout << "\n\t\t\t*******************************************************";
		cout << "\n\t\t\t\t 1. Enter New Record " <<endl;
		cout << "\n\t\t\t\t 2. Display Record " <<endl;
		cout << "\n\t\t\t\t 3. Modify Record " <<endl;
		cout << "\n\t\t\t\t 4. Search Record " <<endl;
		cout << "\n\t\t\t\t 5. Delete Record " <<endl;
		cout << "\n\t\t\t\t 6. Exit " <<endl;
		
			cout << "\n\t\t\t......................................................." << endl;
			cout << "\n\t\t\t>>	    	Choose Option: [1/2/3/4/5/6]    	<<" <<endl;
			cout << "\n\t\t\t......................................................." << endl;
		cout << "\n Enter Your Choice : ";
		cin>>choice;
	
		switch(choice)
		{
			case 1:
				do{
					addRecord();
					cout << "\n\n\t\t\t Add Another Employee Record Press (Y, N) : ";
					cin >> x;
				}while(x=='y' || x=='Y');
				waitForEnter();
				break;
			case 2:
				displayRecord();
				break;
			case 3:
				modifyRecord();
				break;
			case 4:
				searchRecord();
				break;
			case 5:
				deleteRecord();
				break;
			case 6:
				system("cls");
				cout << "\n\n\n\n\t**************************************************************************"<<endl;
				cout << "\n\t\t\t>> EMPLOYEE MANAGEMENT SYSTEM * By Parth Developer <<";
				cout << "\n\n\t**************************************************************************"<<endl;
				for(int i=10; i>=1; i--) {
					cout << i << " Second remaining...\r" << flush;
					sleep(1);
				}
				exit(0);
				break;
			default:
				cout << "\n\n\n\t\t\t\t Invaild Choice... Please Try Again... \n";
		}
		getch();
	}
}

void EmployeeManagement::addRecord()
{
	system("cls");
	fstream file;
	cout << "\n**************************************************************************"<<endl;
	cout << "********************************Employee Insert Data**********************"<<endl;
	cout << "\n Enter Name of Employee : ";
	cin >> empName;
	cout << "\n Enter Employee ID [max 4 digits] : ";
	cin >> empId;
	cout << "\n Enter Designation : ";
	cin >> empDesignation;
	cout << "\n Enter Employee Age : ";
	cin >> empAge;
	cout << "\n Enter Employee CTC : ";
	cin >> empCtc;
	cout << "\n Enter Employee Experience : ";
	cin >> empExperience;
	file.open("Employee_Record.txt", ios::app | ios::out);
	file << " " << empName << " " << empId << " " << empDesignation << " " << empAge << " " << empCtc << " " << empExperience << "\n";
	file.close();
}

void EmployeeManagement::displayRecord()
{
	system("cls");
	int total = 1;
	fstream file;
	cout << "\n\t\t\t\t*******************************************************************" << endl;
	cout << "\t\t\t\t************************** Employee Record Data *******************" << endl;
	file.open("Employee_Record.txt", ios::in);
	if(!file)
	{
		cout << "\n\t\t\t No Data is Present...";
		file.close();
	}
	else{
		file >> empName >> empId >> empDesignation >> empAge >> empCtc >> empExperience;
		cout << "\n*********************************************************************************************************************" << endl;
		cout << "\n||	NAME   ||	 ID   ||	 DESIGNATION	  ||	  AGE   ||   CTC   ||	EXPERIENCE	 ||";
		cout << "\n*********************************************************************************************************************" << endl;
		while(!file.eof())
		{
			cout << "\n";
			cout << total++ << ". " << empName << "\t\t " << empId << "\t\t " << empDesignation << "\t\t\t " << empAge << "\t\t " << empCtc << "\t\t " << empExperience << "\n";
			file >> empName >> empId >> empDesignation >> empAge >> empCtc >> empExperience;
		}
	}
	cout << "\n\n\n";
	for(int i=10; i>=1; i--) {
		cout << i << " Second remaining...\r" << flush;
		sleep(1);
	}
	file.close();
	waitForEnter();
}

void EmployeeManagement::modifyRecord()
{
	system("cls");
	char checkId[5];
	int found = 0;
	fstream file, file1;
	cout << "\n******************************************************************************************" << endl;
	cout << "************************************* Employee Modify Data *****************************" << endl;
	file.open("Employee_Record.txt",ios::in);
	if(!file) {
		cout << "\n\t\t No Data is Present....";
		file.close();
	}
	else{
		cout << "\nEnter Employee id : ";
		cin >> checkId;
		file1.open("record.txt", ios::app | ios::out);
		file >> empName >> empId >> empDesignation >> empAge >> empCtc >> empExperience;
		while(!file.eof()) {
			if(strcmp(checkId, empId) == 0)
			{
				cout << "\n Enter Name of Employee : ";
				cin >> empName;
				cout << "\n Enter Employee ID [max 4 digits] : ";
				cin >> empId;
				cout << "\n Enter Designation : ";
				cin >> empDesignation;
				cout << "\n Enter Employee Age : ";
				cin >> empAge;
				cout << "\n Enter Employee CTC : ";
				cin >> empCtc;
				cout << "\n Enter Employee Experience : ";
				cin >> empExperience;
				cout << "\n\n Successfully Modify Details of Employee";
				file1 << " " << empName << " " << empId << " " << empDesignation << " " << empAge << " " << empCtc << " " << empExperience << "\n";
				found++;
			}
			else{
				file1 << " " << empName << " " << empId << empDesignation << " " << empAge <<				" " << empCtc << " " << empExperience << "\n";
			}
			file >> empName >> empId >> empDesignation >> empAge >> empCtc >> empExperience;
		}
		if(found == 0) {
			cout << "\n\n\t Employee ID Not Found... Please Try Again ";
		}
		file1.close();
		file.close();
		remove("Employee_Record.txt");
		remove("record.txt");
	}
	waitForEnter();
}

void EmployeeManagement::searchRecord()
{
	system("cls");
	fstream file; 
	char checkId[5];
	cout << "\n****************************************************************************************************" << endl;
	cout << "****************************************** Employee Search Data *************************************" << endl;
	file.open("Employee_Record.txt", ios::in);
	cout << "\n\n Enter Employee ID : ";
	cin >> checkId;
	if(!file) {
		cout << "\n\t\t\t No Data is Present... ";
		file.close();
	}
	else{
			file >> empName >> empId >> empDesignation >> empAge >> empCtc >> empExperience;	
			while(!file.eof())
			{
				if(strcmp(checkId, empId) == 0)
				{
					cout << "\n******************************\n\n";
					cout << "Employee Name: " << empName << endl;
					cout << "Employee ID: " << empId << endl;
					cout << "Employee Designation: " << empDesignation << endl;
					cout << "Employee Age: " << empAge << endl;
					cout << "Employee CTC: " << empCtc << endl;
					cout << "Employee Experience: " << empExperience << endl;
					cout << "\n******************************\n";
				}
				file >> empName >> empId >> empDesignation >> empAge >> empCtc >> empExperience;	
			}
	}
	for(int i=10; i>=1; i--) {
		cout << i << " Second remaining...\r" << flush;
		sleep(1);
	}
	file.close();
	waitForEnter();
}

void EmployeeManagement::deleteRecord()
{
	system("cls");
	char checkId[5];
	fstream file, file1;
	int found = 0;
	cout << "\n****************************************************************************************************" << endl;
	cout << "****************************************** Employee Delete Data *************************************" << endl;
	file.open("Employee_Record.txt", ios::in);
	if(!file) {
		cout << "\n\t\t\t No Data is Present... ";
		for(int i=5; i>=1; i--) {
			cout << i << " Second remaining...\r" << flush;
			sleep(1);
		}
		file.close();
	}
	else{
		cout << "\nEnter Employee Id To Remove Data : ";
		cin >> checkId;
		file1.open("record.txt", ios::app | ios::out);
		file >> empName >> empId >> empDesignation >> empAge >> empCtc >> empExperience;	
		while(!file.eof())
		{
			if(strcmp(checkId, empId) != 0)
			{
				file1 << " " << empName << " " << empId << " " << empDesignation << " " << empAge << " " << empCtc << " " << empExperience << "\n";		
			}else{
				found++;
				cout << "\n\t\t\t Successfully Delete Data";
			}
			file >> empName >> empId >> empDesignation >> empAge >> empCtc >> empExperience;
		}
		if(found == 0) {
			cout << "\n\n\t Employee ID Not Found... Please Try again";
		}
		cout << "\n\n\n";
		for(int i=5; i>=1; i--) {
			cout << i << " Second remaining...\r" << flush;
			sleep(1);
		}
		file1.close();
		file.close();
		remove("Employee_Record.txt");
		remove("record.txt");
	waitForEnter();
	}
}

void EmployeeManagement::waitForEnter()
{
	cout << "\n\n Press enter to go back : ";
	cin.get();
}

int userPassword()
{
	string passReg = "";
	string nameReg = "";
	string pass = "";
	string name = "";
	fstream file;
	char ch;
	system("cls");
	
	cout << "\n\t\t\t*******************************************************";
	cout << "\n\t\t\t||       WELCOME TO EMPLOYEE MANAGEMENT SYSTEM         ||";
	cout << "\n\t\t\t*******************************************************";
	cout << "\n\t\t\t		 *| Press: [1] Register & [2] Login |*";
	
	int selection;
	cout << "\n\n Please Enter Value : ";
	cin >> selection;
	
	// if user press 1 then register
	if(selection == 1) 
	{
		system("cls");
		cout << "\n\t\t\t\t*******************************";
		cout << "\n\t\t\t\t>>	REGISTRATION EMPLOYEE	<<";
		cout << "\n\t\t\t\t*******************************";
		cout << "\n\n\t\t\t\t Enter Your Name : ";
		cin >> nameReg;
		cout << "\n\t\t\t\t Enter Your Password : ";
		ch = _getch();
		while(ch != 13)
		{
			passReg.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		
		file.open("Ep_data.txt",ios::app);
		file<< " " << nameReg << " " << passReg << "\n";
		file.close();
		cout << " \n Registration Successfully Saved...";
		getch();
		userPassword();
	}
	else if(selection == 2)
	{
		// if user press 2 then login
		system("cls");
		file.open("Ep_data.txt",ios::in);
		cout << "\n\t\t\t\t*********************************";
		cout << "\n\t\t\t\t>>	  LOGIN EMPLOYEE    <<";
		cout << "\n\t\t\t\t*********************************";
		cout << "\n\n\t\t\t\t Enter Your Name : ";
		cin >> name;
		cout << "\n\t\t\t\t Enter Your Password : ";
		ch = _getch();
		while(ch != 13)
		{
			pass.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		file >> nameReg >> passReg;
		while(!file.eof())
		{
			if(pass == passReg && name == nameReg)
			{
				cout << "\n\n\n\t\t\t\t\t| Verifying EMPLOYEE |\n\t\t\t\t\t";
				for(int a=1; a<8; a++)
				{
					Sleep(500);
					cout << "...";
				}
				cout << "\n\n Access Granted.. \n\n";
				system("PAUSE");
				system("cls");
				break;
			}else{
				cout << "\n\n\n\t\t\t\t\t| Verifying EMPLOYEE |\n\t\t\t\t\t";
				for(int a=1; a<8; a++)
				{
					Sleep(500);
					cout << "...";
				}
				cout << "\n\n Access Aborted.. \n\n";
				system("PAUSE");
				system("cls");
				userPassword();
			}
			file >> nameReg >> passReg;
		}		
		file.close();
	}
	else
	{
		cout << "\nInvalid Input Please try Again..\n";
		userPassword();
	}
	
	return 0;
}

int main()
{
	EmployeeManagement system;
	system.showMenu();
	
	return 0;
}

