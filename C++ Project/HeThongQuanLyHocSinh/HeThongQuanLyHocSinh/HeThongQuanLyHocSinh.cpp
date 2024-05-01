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

void sortHighToLowStudent(Student a[], int numberOfStudents) {
	vector<Student> v;
	for (int i = 1; i <= numberOfStudents; i++) {
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end(), cmp1);
	for (auto it : v) {
		it.SPrint();
	}
}
void sortLowToHighStudent(Student a[], int numberOfStudents) {
	vector<Student> v;
	for (int i = 1; i <= numberOfStudents; i++) {
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end(), cmp2);
	for (auto it : v) {
		it.SPrint();
	}
}

void SearchTeacher(Teacher a[], int Options, int classid) {
	string searchID, searchName;
	bool check = false;
	if (Options == 1) {
		cout << "Please insert a teacher's ID you want to search\n";  cin >> searchID;
		for (int i = 1; i < sizeof(Class[classid]); i++) {
			if (Class[classid].t[i].teacherID.find(searchID) != string::npos) {
				Class[classid].t[i].TPrint();
				check = true;
			}
		}
	}
	else if (Options == 2) {
		cout << "Please insert a teacher's name you want to search\n";  cin.ignore(); getline(cin, searchName);
		for (int i = 1; i < sizeof(Class[classid]); i++) {
			if (Class[classid].t[i].name.find(searchName) != string::npos) {
				Class[classid].t[i].TPrint();
				check = true;
			}
		}
	}
	if (!check) cout << "This teacher does not existed\n";
}

void SearchStudent(Student a[], int Options, int classid) {
	string searchID, searchName;
	bool check = false;
	if (searchStudentOptions == 1) {
		cout << "Please insert a student's ID you want to search\n";  cin >> searchID;
		for (int i = 1; i < sizeof(Class[classid]); i++) {
			if (Class[classid].s[i].studentID.find(searchID) != string::npos) {
				check = true;
				Class[classid].s[i].SPrint();
			}
		}
		if (!check) cout << "This student does not existed\n";
	}
	else if (searchStudentOptions == 2) {
		cout << "Please insert a student's name you want to search\n";  cin.ignore(); getline(cin, searchName);
		for (int i = 1; i < sizeof(Class[classid]); i++) {
			if (Class[classid].s[i].name.find(searchName) != string::npos) {
				check = true;
				Class[classid].s[i].SPrint();
			}
		}
		if (!check) cout << "This student does not existed\n";
	}
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
				for (int i = 1; i <= numberOfTeachers; i++) {
					Class[i + 1].t[i + 1].TInput();
				}
				cout << "-------------------------------------------------------\n";
				cout << "Please insert number of students you want to add: \n"; cin >> numberOfStudents;
				cout << "Please insert student's information: \n";
				for (int j = 0; j < numberOfStudents; j++) {
					Class[i + 1].s[j + 1].SInput();
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
			SearchStudent(Class[classid].s, searchStudentOptions, classid);
			break;
		}
		case 3:
		{
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			cout << "Please choose one of these options\n 1. Search by ID\n 2. Search by name \n"; cin >> searchTeacherOptions;
			SearchTeacher(Class[classid].t, searchTeacherOptions, classid);
			break;
		}
		case 4:
		{
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			for (int i = 1; i < sizeof(Class[classid].s); i++) {
				if (Class[classid].s[i].name != "") {
					Class[classid].s[i].SPrint();
					cout << "\n";
				}
			}
			break;
		}
		case 5:
		{
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			for (int i = 1; i < sizeof(Class[classid].s); i++) {
				if (Class[classid].t[i].name != "") {
					Class[classid].t[i].TPrint();
					cout << "\n";
				}
			}
			break;
		}
		case 6:
		{
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			int tmp = sizeof(Class[classid].s);
			sortHighToLowStudent(Class[classid].s, tmp);
			break;
		}
		case 7:
		{
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			int temp = sizeof(Class[classid].s);
			sortLowToHighStudent(Class[classid].s, temp);
			break;
		}
		case 1017:
		{
			system("cls");
			system("Color 0A");
			textDisplay("Welcome, my owner", 100, 75, true);
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