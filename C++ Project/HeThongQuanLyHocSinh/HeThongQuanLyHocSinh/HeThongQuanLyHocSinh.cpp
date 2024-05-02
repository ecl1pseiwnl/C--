/*
			   _ _                _                _
	  ___  ___| / |_ __  ___  ___(_)_      ___ __ | |
	 / _ \/ __| | | '_ \/ __|/ _ \ \ \ /\ / / '_ \| |
	|  __/ (__| | | |_) \__ \  __/ |\ V  V /| | | | |
	 \___|\___|_|_| .__/|___/\___|_| \_/\_/ |_| |_|_|
				  |_|
*/
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Functions.cpp"
using namespace std;

int numberOfClasses, numberOfStudents,numberOfTeachers, classid, searchStudentOptions, searchTeacherOptions, options;
string s1 = "System has been shut down", s2 = "\nThank you for using this system", s3 = "Made by ecl1pseiwnl.";
struct classes {
	string className, classID, classMajor;
	vector<Teacher> TList;
	vector<Student> SList;
	Teacher t[12];
	Student s[46];
};
vector<classes> Class(21);

void textDisplay(const string text, int typeSpeed, int pauseDur, bool clearConsole) {
	for (int i = 0; i < text.size(); i++) {
		cout << text[i] << flush;
		Sleep(typeSpeed);
	}
	Sleep(pauseDur);
	if (clearConsole) {
		system("cls");
	}
}

bool cmp1(Student a, Student b) {
	return a.gpa > b.gpa;
}
bool cmp2(Student a, Student b) {
	return a.gpa < b.gpa;
}

void sortHighToLowStudent(int classid) {
	sort(Class[classid].SList.begin(), Class[classid].SList.end(), cmp1);
	for (auto it : Class[classid].SList) {
		it.SPrint();
	}
}
void sortLowToHighStudent(int classid) {
	sort(Class[classid].SList.begin(), Class[classid].SList.end(), cmp2);
	for (auto it : Class[classid].SList) {
		it.SPrint();
	}
}

void SearchTeacher(int Options, int classid) {
	string searchID, searchName;
	bool check = false;
	if (Options == 1) {
		cout << "Please insert a teacher's ID you want to search\n";  cin >> searchID;
		for (auto it : Class[classid].TList) {
			if (it.teacherID == searchID) {
				it.TPrint();
				check = true;
				return;
			}
		}
	}
	else if (Options == 2) {
		cout << "Please insert a teacher's name you want to search\n";  cin.ignore(); getline(cin, searchName);
		for (auto it : Class[classid].TList) {
			if (it.name == searchName) {
				it.TPrint();
				check = true;
				return;
			}
		}
	}
	if (!check) cout << "This teacher does not existed\n";
}

void SearchStudent(int Options, int classid) {
	string searchID, searchName;
	bool check = false;
	if (searchStudentOptions == 1) {
		cout << "Please insert a student's ID you want to search\n";  cin >> searchID;
		for (auto it : Class[classid].SList) {
			if (it.studentID == searchID) {
				it.SPrint();
				check = true;
				return;
			}
		}
	}
	else if (searchStudentOptions == 2) {
		cout << "Please insert a student's name you want to search\n";  cin.ignore(); getline(cin, searchName);
		for (auto it : Class[classid].SList) {
			if (it.name == searchName) {
				it.SPrint();
				check = true;
				return;
			}
		}
	}
	if (!check) cout << "This student does not existed\n";
}









int main() {
	while (true) {
		system("color 0E");
		cout << "===========================================================================\n";
		cout << "        Managing Students and Teachers system\n";
		cout << "===========================================================================\n";
		cout << "Please choose an option\n";
		cout << "1. Add classes\n";
		cout << "2. Search a student's information\n";
		cout << "3. Search a teacher's information\n";
		cout << "4. List of students from a class\n";
		cout << "5. List of teachers from a class\n";
		cout << "6. List the highest to the lowest GPA of a class\n";
		cout << "7. List the lowest to the highest GPA of a class\n";
		cout << "0. Exit \n";
		cout << "==========================================================================\n";
		cout << "Your option: "; cin >> options;
		cout << "--------------------------------------------------------------------------\n";
		switch (options) {
		case 1:
		{
			cout << "Please insert number of classes you want to add: "; cin >> numberOfClasses;
			cout << "Please insert number of teachers of that class you want to add: "; cin >> numberOfTeachers;
			for (int i = 0; i < numberOfClasses; i++) {
				cout << "Class No." << i + 1 << "'s ID: "; cin >> Class[i + 1].classID;
				cout << "Class No." << i + 1 << "'s name: ";
				cin.ignore();
				getline(cin, Class[i + 1].className);
				cout << "Class No." << i + 1 << "'s major: ";
				getline(cin, Class[i + 1].classMajor);
				cout << "--------------------------------------------------------------------------\n";
				cout << "Please insert teacher's information: \n";
				for (int j = 0; j < numberOfTeachers; j++) {
					Class[i + 1].t[j + 1].TInput();
					Class[i + 1].TList.push_back(Class[i + 1].t[j + 1]);
				}
				cout << "-------------------------------------------------------\n";
				cout << "Please insert number of students you want to add: \n"; cin >> numberOfStudents;
				cout << "Please insert student's information: \n";
				for (int k = 0; k < numberOfStudents; k++) {
					Class[i + 1].s[k + 1].SInput();
					Class[i + 1].SList.push_back(Class[i + 1].s[k + 1]);
				}
			}
			cout << "------------------------------------------------------\n";
			if (numberOfClasses > 1) {
				cout << numberOfClasses << " classes have been added \n";
			}
			else if (numberOfClasses == 1) {
				cout << numberOfClasses << " class has been added \n";
			}
			break;
		}
		case 2:
		{
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			cout << "Please choose one of these options\n 1. Search by ID\n 2. Search by name \n"; cin >> searchStudentOptions;
			SearchStudent(searchStudentOptions, classid);
			break;
		}
		case 3:
		{
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			cout << "Please choose one of these options\n 1. Search by ID\n 2. Search by name \n"; cin >> searchTeacherOptions;
			SearchTeacher(searchTeacherOptions, classid);
			break;
		}
		case 4:
		{
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			for (auto it : Class[classid].SList) {
				it.SPrint();
			}
			break;
		}
		case 5:
		{
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			for (auto it : Class[classid].TList) {
				it.TPrint();
			}
			break;
		}
		case 6:
		{
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			sortHighToLowStudent(classid);
			break;
		}
		case 7:
		{
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			sortLowToHighStudent(classid);
			break;
		}
		case 1017:
		{
			system("cls");
			system("Color 0A");
			textDisplay("Welcome, my owner", 500, 75, true);
			break;
		}
		case 0:
		{
			system("cls");
			textDisplay(s1, 75, 75, false);
			textDisplay(s2, 75, 75, true);
			textDisplay(s3, 75, 75, true);
			exit(0);
			break;
		}
		default: {
			cout << "\n\nError! Please insert again a number from 0 to 7!\n\n\n";
			break;
		}
		}
	}
	return 0;
}