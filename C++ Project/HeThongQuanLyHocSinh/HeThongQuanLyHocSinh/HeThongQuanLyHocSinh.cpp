#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Functions.cpp"
using namespace std;

int numberOfClasses, numberOfStudents, classid, searchStudentOptions, searchTeacherOptions, options;
string  studentSearchID, studentSearchName, teacherSearchID, teacherSearchName, s1 = "System has been shut down", s2 = "\nThank you for using this system", s3 = "Made by ecl1pseiwnl.";
struct classes {
	string className, classID, classMajor;
	Teacher t[3];
	Student s[46];
};
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
vector<classes> Class(21);

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
			cout << "Please insert number of classes you want to add: "; cin >> numberOfClasses;
			for (int i = 0; i < numberOfClasses; i++) {
				cout << "Class No." << i + 1 << "'s ID: "; cin >> Class[i + 1].classID;
				cout << "Class No." << i + 1 << "'s name: ";
				cin.ignore();
				getline(cin, Class[i + 1].className);
				cout << "Class No." << i + 1 << "'s major: ";
				getline(cin, Class[i + 1].classMajor);
				cout << "--------------------------------------------------------------------------\n";
				cout << "Please insert teacher's information: \n";
				for (int j = 0; j < 2; j++) {
					Class[i + 1].t[j + 1].TInput();
				}
				cout << "-------------------------------------------------------\n";
				cout << "Please insert number of students you want to add: \n"; cin >> numberOfStudents;
				cout << "Please insert student's information: \n";
				for (int k = 0; k < numberOfStudents; k++) {
					Class[i + 1].s[k + 1].SInput();
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
		case 2:
			bool check = false;
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			cout << "Please choose one of these options\n 1. Search by ID\n 2. Search by name \n"; cin >> searchStudentOptions;
			if (searchStudentOptions == 1) {
				cout << "Please insert a student's ID you want to search\n";  cin >> studentSearchID;
				for (int i = 1; i < sizeof(Class[classid]); i++) {
					if (Class[classid].s[i].studentID.find(studentSearchID) != string::npos) {
						check = true;
						Class[classid].s[i].SPrint();
					}
				}
			}
			else if (searchStudentOptions == 2) {
				cout << "Please insert a student's name you want to search\n";  cin.ignore(); getline(cin, studentSearchName);
				for (int i = 1; i < sizeof(Class[classid]); i++) {
					if (Class[classid].s[i].name.find(studentSearchName) != string::npos) {
						check = true;
						Class[classid].s[i].SPrint();
					}
				}
			}
			if (!check) cout << "This student does not existed\n";
			break;
		case 3:
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			cout << "Please choose one of these options\n 1. Search by ID\n 2. Search by name \n"; cin >> searchTeacherOptions;
			if (searchTeacherOptions == 1) {
				cout << "Please insert a teacher's ID you want to search\n";  cin >> teacherSearchID;
				for (int i = 1; i < sizeof(Class[classid]); i++) {
					if (Class[classid].t[i].teacherID.find(teacherSearchID) != string::npos) {
						Class[classid].t[i].TPrint();
					}
					else cout << "This teacher does not existed\n";
				}
			}
			else if (searchStudentOptions == 2) {
				cout << "Please insert a teacher's name you want to search\n";  cin.ignore(); getline(cin, teacherSearchName);
				for (int i = 1; i < sizeof(Class[classid]); i++) {
					if (Class[classid].t[i].name.find(teacherSearchName) != string::npos) {
						Class[classid].t[i].TPrint();
					}
					else cout << "This teacher does not existed\n";
				}
			}
			break;
		case 4:
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			for (int i = 1; i < sizeof(Class[classid].s); i++) {
				if (Class[classid].s[i].name == "") continue;
				Class[classid].s[i].SPrint();
				cout << "\n";
			}
			break;
		case 5:
			cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
			for (int i = 1; i < sizeof(Class[classid].s); i++) {
				if (Class[classid].t[i].name == "") continue;
				Class[classid].t[i].TPrint();
				cout << "\n";
			}
			break;
		case 6:
			break;
		case 7:
			break;
		case 0:
			system("cls");
			textDisplay(s1, 100, 75, false);
			textDisplay(s2, 100, 75, true);
			textDisplay(s3, 100, 75, true);
			exit(0);
			break;
			cout << "\n";
		default:
			cout << "\n\nError! Please insert again a number from 0 to 7!\n\n\n";
		}
	}
	return 0;
}