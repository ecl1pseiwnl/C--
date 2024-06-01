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
	Teacher t[23];
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
	vector<Student> v;
	for (auto it : Class[classid].SList) {
		v.push_back(it);
	}
	sort(v.begin(), v.end(), cmp1);
	for (auto it : v) {
		it.SPrint();
	}
}
void sortLowToHighStudent(int classid) {
	vector<Student> v;
	for (auto it : Class[classid].SList) {
		v.push_back(it);
	}
	sort(v.begin(), v.end(), cmp2);
	for (auto it : v) {
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
void fillClass() {
	for (int i = 1; i < 21; i++) {
		Class[i].classID = to_string(i) + to_string(i) + to_string(i);
		Class[i].classMajor = to_string(i) + to_string(i) + to_string(i) + to_string(i);
		Class[i].className = to_string(i) + to_string(i) + to_string(i) + to_string(i) + to_string(i);
	}
	for (int i = 1; i < 21; i++) {
		Class[i].s[i].studentID = to_string(i);
		Class[i].s[i].name = to_string(i) + to_string(i);
		Class[i].s[i].gender = to_string(i) + to_string(i) + to_string(i);
		Class[i].s[i].birthday = to_string(i) + "2";
		Class[i].s[i].major = to_string(i);
		Class[i].s[i].nationality = to_string(i) + "3";
		Class[i].s[i].gpa = i + 1;
		Class[i].SList.push_back(Class[i].s[i]);
	}
	for (int i = 1; i < 21; i++) {
		Class[i].t[i].teacherID = to_string(i);
		Class[i].t[i].name = to_string(i) + to_string(i);
		Class[i].t[i].gender = to_string(i) + to_string(i) + to_string(i);
		Class[i].t[i].birthday = to_string(i) + "2";
		Class[i].t[i].major = to_string(i);
		Class[i].t[i].nationality = to_string(i) + "3";
		Class[i].TList.push_back(Class[i].t[i]);
	}
}
void delClass() {
	for (int i = 1; i < 21; i++) {
		Class[i].classID = "";
		Class[i].classMajor = "";
		Class[i].className = "";
	}
	for (int i = 1; i < 21; i++) {
		Class[i].s[i].studentID = "";
		Class[i].s[i].name = "";
		Class[i].s[i].gender = "";
		Class[i].s[i].birthday = "";
		Class[i].s[i].major = "";
		Class[i].s[i].nationality = "";
		Class[i].s[i].gpa = 0;
	}
	for (int i = 1; i < 21; i++) {
		Class[i].t[i].teacherID = "";
		Class[i].t[i].name = "";
		Class[i].t[i].gender = "";
		Class[i].t[i].birthday = "";
		Class[i].t[i].major = "";
		Class[i].t[i].nationality = "";
	}
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
		cout << "4. List of classes\n";
		cout << "5. List of students from a class\n";
		cout << "6. List of teachers from a class\n";
		cout << "7. List the highest to the lowest GPA of a class\n";
		cout << "8. List the lowest to the highest GPA of a class\n";
		cout << "9. Calculate GPA\n";
		cout << "10. Add/Edit student's GPA\n";
		cout << "11. Extract a class's information to a file\n";
		cout << "0. Exit \n";
		cout << "==========================================================================\n";
		cout << "Your option: "; cin >> options;
		cout << "--------------------------------------------------------------------------\n";
		switch (options) {
			case 1:
			{
				cout << "Please insert number of classes you want to add: "; cin >> numberOfClasses;
				cout << "Please insert number of teachers of that class you want to add: "; cin >> numberOfTeachers;
				for (int i = 1; i <= numberOfClasses; i++) {
					if (Class[i].classID == "") {
						cout << "Class No." << i << "'s ID: "; cin >> Class[i].classID;
						cout << "Class No." << i << "'s name: ";
						cin.ignore();
						getline(cin, Class[i].className);
						cout << "Class No." << i << "'s major: ";
						getline(cin, Class[i].classMajor);
						cout << "--------------------------------------------------------------------------\n";
						cout << "Please insert teacher's information: \n";
						for (int j = 1; j <= numberOfTeachers; j++) {
							Class[i].t[j].TInput();
							Class[i].TList.push_back(Class[i].t[j]);
						}
						cout << "-------------------------------------------------------\n";
						cout << "Please insert number of students you want to add: \n"; cin >> numberOfStudents;
						cout << "Please insert student's information: \n";
						for (int k = 1; k <= numberOfStudents; k++) {
							Class[i].s[k].SInput();
							Class[i].SList.push_back(Class[i].s[k]);
						}
					}
					else {
						numberOfClasses++;
						continue;
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
				int check = 0;
				cout << "\n\n\n======================================================\n";
				for (auto it : Class) {
					if (it.classID == "") {
						continue;
					}
					else {
						check++;
						cout << "Class ID: " << it.classID << "\n" << "Class's name: " << it.className << "\n" << "Class's major: " << it.classMajor << "\n" << "Students: " << it.SList.size() << "\n";
						cout << "------------------------------------------------------\n\n\n";
					}
				}
				if (!check) cout << "\n\nCan not find any class!\n\n\n";
				break;
			}
			case 5:
			{
				cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
				for (auto it : Class[classid].SList) {
					it.SPrint();
				}
				break;
			}
			case 6:
			{
				cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
				for (auto it : Class[classid].TList) {
					it.TPrint();
				}
				break;
			}
			case 7:
			{
				cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
				sortHighToLowStudent(classid);
				break;
			}
			case 8:
			{
				cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
				sortLowToHighStudent(classid);
				break;
			}
			case 9: 
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
			case 10:
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
			case 11:
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
					File << "-------------------------------------------------------\n";
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
						string x = to_string(it.gpa), tmp;
						tmp = tmp + x[0] + x[1] + x[2] + x[3];
						File << "Student's ID: " + it.studentID + "\n";
						File << "Student's name: " + it.name + "\n";
						File << "Student's gender: " + it.gender + "\n";
						File << "Student's birthday: " + it.birthday + "\n";
						File << "Student's nationality: " + it.nationality + "\n";
						File << "Student's major: " + it.major + "\n";
						File << "Student's GPA: " + tmp + "\n";
						File << "------------------------------------------------------\n";
					}
					File.close();
					cout << "\n\n      Class's information has been extracted to file!\n";
					cout << "  Please check the code file to see the file\n";
					cout << "  -	Teachers: " << Class[tempIndex].TList.size() << "\n";
					cout << "  -	Students: " << Class[tempIndex].SList.size() << "\n\n\n\n";
				}
				break;
			}
			case 1017:
			{
				system("cls");
				system("Color 0A");
				textDisplay("Welcome, you just glitched things or you typed the secret number lmao", 250, 75, true);
				break;
			}
			case 2008:
			{
				fillClass();
				system("cls");
				cout << "Command has been executed\n\n\n";
				break;
			}
			case 1710:
			{
				delClass();
				system("cls");
				cout << "Command has been executed\n\n\n";
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
			default: 
			{
				system("cls");
				system("Color 04");
				textDisplay("\n\nError! Please insert again a number from 0 to 11!\n\n\n\n\n\n\n\n", 50, 75, true);
				break;
			}
		}
	}
	return 0;
}
