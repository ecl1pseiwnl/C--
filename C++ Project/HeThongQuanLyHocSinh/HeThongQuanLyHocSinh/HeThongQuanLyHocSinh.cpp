/*
			   _ _                _                _
	  ___  ___| / |_ __  ___  ___(_)_      ___ __ | |
	 / _ \/ __| | | '_ \/ __|/ _ \ \ \ /\ / / '_ \| |
	|  __/ (__| | | |_) \__ \  __/ |\ V  V /| | | | |
	 \___|\___|_|_| .__/|___/\___|_| \_/\_/ |_| |_|_|
				  |_|
*/
#include "FunctionsAndDatabase.cpp"
using namespace std;

int numberOfClasses, numberOfStudents, numberOfTeachers, classid, searchStudentOptions, searchTeacherOptions, options, temp, cnt, tempIndex;
double midTerm, finalTerm, tempGPA;

string classID, s1 = "System has been shut down", s2 = "\nThank you for using this system", s3 = "Made by ecl1pseiwnl.", ID;
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
		cout << "                  Managing Students and Teachers system\n";
		cout << "===========================================================================\n";
		cout << "Please choose an option\n";
		cout << "1. Add classes\n";
		cout << "2. Search a student's information\n";
		cout << "3. Search a teacher's information\n";
		cout << "4. List of students from a class\n";
		cout << "5. List of teachers from a class\n";
		cout << "6. List the highest to the lowest GPA of a class\n";
		cout << "7. List the lowest to the highest GPA of a class\n";
		cout << "8. Calculate GPA\n";
		cout << "9. Add/Edit student's GPA\n";
		cout << "10. Extract a class's information to a file\n";
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
			case 8: 
			{
				int numberOfGrades;
				cout << "Please insert how many grades you want to calculate (Not include midterm & finalterm): \n"; cin >> numberOfGrades;
				cout << "Please insert your final term grade: \n"; cin >> finalTerm;
				cout << "Please insert your middle term grade: \n"; cin >> midTerm;
				tempGPA = 0;
				cnt = numberOfGrades + 3 + 2;
				for (int i = 0; i < numberOfGrades; i++) {
					double x;
					cout << "Please insert your grades: ";
					cin >> x;
					tempGPA += x;
				}
				cout << "------------------------------------------------------\n";
				cout << "Your current semester's GPA: " << fixed << setprecision(1) << (tempGPA + (finalTerm * 3) + (midTerm * 2)) / cnt << "\n";
				break;
			}
			case 9:
			{
				double GPA;
				cout << "Please insert ID of the class you want to add/edit GPA: \n"; cin >> classID;
				cout << "Please insert the student's id you want to add/edit: \n"; cin >> ID;
				cout << "Please insert that student's GPA you want to add/edit: \n"; cin >> GPA;
				for (int i = 1; i < Class.size(); i++) {
					if (Class[i].classID == classID) {
						for (auto it : Class[i].SList) {
							if (it.studentID == ID) {
								it.gpa = GPA;
								cout << "==========================================================\n";
								cout << it.name << "'s GPA has been added/edited!\n";
								cout << it.gpa << " --> " << GPA << "\n";
								it.gpa = GPA;
								it.SPrint();
								break;
							}
						}
					}
				}
				cout << "------------------------------------------------------\n";
				cout << "\n\n\nCan not find the class/student from the given IDs!\n\n\n";
				break;
			}
			case 10:
			{
				bool check = false;
				string fileName = "", t;
				cout << "Please insert the ID of the class you want to extract into file: \n"; cin >> classID;
				for (int i = 1; i < Class.size(); i++) {
					if (Class[i].classID == classID) {
						check = true;
						tempIndex = i;
						stringstream ss(Class[i].className);
						while (ss >> t) {
							fileName += t;
						}
						break;
					}
				}
				if (!check) {
					cout << "------------------------------------------------------\n";
					cout << "Can not find the class !\n";
				}
				else {
					fileName += ".txt";
					ofstream File(fileName);
					File << "Class's ID: " + Class[tempIndex].classID + "\n";
					File << "Class's name: " +Class[tempIndex].className + "\n";
					File << "Class's major: " + Class[tempIndex].classMajor + "\n";
					File << "====================Teachers===========================\n";
					for (auto it : Class[tempIndex].TList) {
						File << "Teacher's ID: " + it.teacherID + "\n";
						File << "Teacher's name: " + it.name + "\n";
						File << "Teacher's gender: " + it.gender + "\n";
						File << "Teacher's birthday: " + it.birthday + "\n";
						File << "Teacher's nationality: " + it.nationality + "\n";
						File << "Teacher's major: " + it.major + "\n";
						File << "------------------------------------------------------\n";
					}
					File << "===================Students===========================\n";
					for (auto it : Class[tempIndex].SList) {
						File << "Student's ID: " + it.studentID + "\n";
						File << "Student's name: " + it.name + "\n";
						File << "Student's gender: " + it.gender + "\n";
						File << "Student's birthday: " + it.birthday + "\n";
						File << "Student's nationality: " + it.nationality + "\n";
						File << "Student's major: " + it.major + "\n";
						File << "Student's GPA: " + to_string(it.gpa) + "\n";
						File << "------------------------------------------------------\n";
					}
					File.close();
					cout << "Class's information has been extracted to file!\n\n\n\n";
				}
				break;
			}
			case int(1017) :
			{
				system("cls");
				system("Color 0A");
				textDisplay("Welcome, you just glitched things or you typed the secret number lmao", 500, 75, true);
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
				cout << "\n\nError! Please insert again a number from 0 to 10!\n\n\n";
				break;
			}
		}
	}
	return 0;
}