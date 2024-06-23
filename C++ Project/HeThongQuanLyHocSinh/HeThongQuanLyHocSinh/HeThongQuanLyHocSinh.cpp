//                                                                                              
//  8 8888888888       ,o888888o.    8 8888         8 888888888o     d888888o.   8 8888888888   
//  8 8888            8888     `88.  8 8888         8 8888    `88. .`8888:' `88. 8 8888         
//  8 8888         ,8 8888       `8. 8 8888         8 8888     `88 8.`8888.   Y8 8 8888         
//  8 8888         88 8888           8 8888         8 8888     ,88 `8.`8888.     8 8888         
//  8 888888888888 88 8888           8 8888         8 8888.   ,88'  `8.`8888.    8 888888888888 
//  8 8888         88 8888           8 8888         8 888888888P'    `8.`8888.   8 8888         
//  8 8888         88 8888           8 8888         8 8888            `8.`8888.  8 8888         
//  8 8888         `8 8888       .8' 8 8888         8 8888        8b   `8.`8888. 8 8888         
//  8 8888            8888     ,88'  8 8888         8 8888        `8b.  ;8.`8888 8 8888         
//  8 888888888888     `8888888P'    8 888888888888 8 8888         `Y8888P ,88P' 8 888888888888 
//
#include "Functions.cpp"
#include "MySQL_Queries.cpp"
using namespace std;

int numberOfClasses, numberOfStudents, numberOfTeachers, searchStudentOptions, searchTeacherOptions, options, temp, cnt, tempIndex, classid, classID;
double midTerm, finalTerm, tempGPA;
string s1 = "System has been shut down", s2 = "\nThank you for using this system", s3 = "Made by ecl1pseiwnl.", ID;

struct classes {
	int classID = NULL, ordinal_number = NULL;
	string className, classMajor;
	vector<Teacher> TList;
	vector<Student> SList;
	Teacher t[23];
	Student s[46];
};
vector<Admins> Admin(26);
vector<classes> Class(80);
// ------------------------------------------------------------------------------------------------------------

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
	if (Options == 1) {
		cout << "Please insert a teacher's ID you want to search\n";  cin >> searchID;
		for (auto it : Class[classid].TList) {
			if (it.teacherID == searchID) {
				it.TPrint();
				return;
			}
		}
	}
	else if (Options == 2) {
		cout << "Please insert a teacher's name you want to search\n";  cin.ignore(); getline(cin, searchName);
		for (auto it : Class[classid].TList) {
			if (it.name == searchName) {
				it.TPrint();
				return;
			}
		}
	}
	return cout << "This teacher does not existed\n", void();
}

void SearchStudent(int Options, int classid) {
	string searchID, searchName;
	if (searchStudentOptions == 1) {
		cout << "Please insert a student's ID you want to search\n";  cin >> searchID;
		for (auto it : Class[classid].SList) {
			if (it.studentID == searchID) {
				it.SPrint();
				return;
			}
		}
	}
	else if (searchStudentOptions == 2) {
		cout << "Please insert a student's name you want to search\n";  cin.ignore(); getline(cin, searchName);
		for (auto it : Class[classid].SList) {
			if (it.name == searchName) {
				it.SPrint();
				return;
			}
		}
	}
	return cout << "This student does not existed\n", void();
}

bool SearchClass(int ID) {
	for (int i = 1; i <= 79; i++) {
		if (Class[i].ordinal_number == ID) return true;
	}
	return false;
}

void dev_options(string user, string password) {
	bool temp = false;
	for (auto it : Admin) {
		if (it.username == user && it.password == password) {
			temp = true;
		}
	}
	if (temp == false) {
		system("cls");
		return textDisplay("Access Denied",75,200,true), void();
	}
	system("cls");
	int ops;
	while (temp) {
		cout << "===========================================================================\n";
		cout << "		         Developer Settings\n";
		cout << "===========================================================================\n";
		cout << "Please choose an option\n";
		cout << "1. Check DB's status\n";
		cout << "2. Check DB's connection\n";
		cout << "3. Check UserID and Password of database\n";
		cout << "0. Exit to normal mode\n";
		cout << "==========================================================================\n";
		cout << "Your option: "; cin >> ops;
		cout << "--------------------------------------------------------------------------\n";
		switch (ops) {
			case 1:
			{
				break;
			}
			case 2:
			{
				break;
			}
			case 3:
			{
				break;
			}
			case 0:
			{
				system("cls");
				temp = false;
				break;
			}
		}
	}
}

void addClass() {
	cout << "Please insert number of classes you want to add: "; cin >> numberOfClasses;
	cout << "Please insert number of teachers of that class you want to add: "; cin >> numberOfTeachers;
	for (int i = 1; i <= numberOfClasses; i++) {
		if (Class[i].classID == NULL) {
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
}

void fillClass() {
	for (int i = 1; i < 21; i++) {
		Class[i].classID = i*i*i;
		Class[i].ordinal_number = i;
		Class[i].classMajor = to_string(i) + to_string(i) + to_string(i) + to_string(i);
		Class[i].className = to_string(i) + to_string(i) + to_string(i) + to_string(i) + to_string(i);
		for (int j = 1; j < 46; j++) {
			Class[i].s[j].studentID = to_string(i);
			Class[i].s[j].name = to_string(i) + to_string(i);
			Class[i].s[j].gender = to_string(i) + to_string(i) + to_string(i);
			Class[i].s[j].birthday = to_string(i) + "2";
			Class[i].s[j].major = to_string(i);
			Class[i].s[j].nationality = to_string(i) + "3";
			Class[i].s[j].gpa = i + 1;
			Class[i].SList.push_back(Class[i].s[j]);
		}
		for (int k = 1; k < 21; k++) {
			Class[i].t[k].teacherID = to_string(i);
			Class[i].t[k].name = to_string(i) + to_string(i);
			Class[i].t[k].gender = to_string(i) + to_string(i) + to_string(i);
			Class[i].t[k].birthday = to_string(i) + "2";
			Class[i].t[k].major = to_string(i);
			Class[i].t[k].nationality = to_string(i) + "3";
			Class[i].TList.push_back(Class[i].t[k]);
		}
	}
}

void delClass() {
	for (int i = 1; i < 21; i++) {
		Class[i].classID = NULL;
		Class[i].ordinal_number = NULL;
		Class[i].classMajor = "";
		Class[i].className = "";
		for (int j = 1; j < 46; j++) {
			Class[i].s[j].studentID = "";
			Class[i].s[j].name = "";
			Class[i].s[j].gender = "";
			Class[i].s[j].birthday = "";
			Class[i].s[j].major = "";
			Class[i].s[j].nationality = "";
			Class[i].s[j].gpa = 0;
		}
		for (int k = 1; k < 21; k++) {
			Class[i].t[k].teacherID = "";
			Class[i].t[k].name = "";
			Class[i].t[k].gender = "";
			Class[i].t[k].birthday = "";
			Class[i].t[k].major = "";
			Class[i].t[k].nationality = "";
		}
	}
}








int main() {
	while (true) {
		Admin[1].LoadAdminInfo();
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
		cout << "11. Insert a class's information from database\n";
		cout << "12. Extract a class's information to a file\n";
		cout << "0. Exit \n";
		cout << "==========================================================================\n";
		cout << "Your option: "; cin >> options;
		cout << "--------------------------------------------------------------------------\n";
		switch (options) {
			case 1:
			{
				addClass();
				break;
			}
			case 2:
			{
				cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
				if (SearchClass(classid) == true) {
					cout << "Please choose one of these options\n 1. Search by ID\n 2. Search by name \n"; cin >> searchStudentOptions;
					cout << endl;
					cout << "------------------------------------------------------\n";
					SearchStudent(searchStudentOptions, classid);
					cout << "\n\n\n";
				}
				else if (SearchClass(classid) == false) {
					cout << "The class with ID '" << classid << "' does not exist!\n";
					cout << "------------------------------------------------------\n";
				}
				break;
			}
			case 3:
			{
				cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
				if (SearchClass(classid) == true) {
					cout << "Please choose one of these options\n 1. Search by ID\n 2. Search by name \n"; cin >> searchTeacherOptions;
					cout << endl;
					cout << "------------------------------------------------------\n";
					SearchTeacher(searchTeacherOptions, classid);
					cout << "\n\n\n";;
				}
				else if (SearchClass(classid) == false) {
					cout << "The class with ID '" << classid << "' does not exist!\n";
					cout << "------------------------------------------------------\n";
				}
				break;
			}
			case 4:
			{
				bool check = false;
				cout << "\n\n\n======================================================\n";
				for (auto it : Class) {
					if (it.classID == NULL) {
						continue;
					}
					else {
						check = true;
						cout << "Class's ordinal number: " << it.ordinal_number << "\n" << "Class ID: " << it.classID << "\n" << "Class's name: " << it.className << "\n" << "Class's major: " << it.classMajor << "\n" << "Students: " << it.SList.size() << "\n";
						cout << "------------------------------------------------------\n\n\n";
					}
				}
				if (!check) cout << "\n\nCan not find any class!\n\n\n";
				break;
			}
			case 5:
			{
				cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
				cout << "------------------------------------------------------\n";
				if (SearchClass(classid) == true) {
					for (auto it : Class[classid].SList) {
						it.SPrint();
					}
					cout << "\n\n\n";
				}
				else if (SearchClass(classid) == false) {
					cout << "The class with ID '" << classid << "' does not exist!\n";
					cout << "------------------------------------------------------\n";
				}
				break;
			}
			case 6:
			{
				cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
				if (SearchClass(classid) == true) {
					for (auto it : Class[classid].TList) {
						it.TPrint();
					}
					cout << "\n\n\n";
				}
				else if (SearchClass(classid) == false) {
					cout << "The class with ID '" << classid << "' does not exist!\n";
					cout << "------------------------------------------------------\n";
				}
				break;
			}
			case 7:
			{
				cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
				if (SearchClass(classid) == true) {
					sortHighToLowStudent(classid);
					cout << "\n\n\n";
				}
				else if (SearchClass(classid) == false) {
					cout << "The class with ID '" << classid << "' does not exist!\n";
					cout << "------------------------------------------------------\n";
				}
				break;
			}
			case 8:
			{
				cout << "Please insert class's ordinal number you want to search: \n"; cin >> classid;
				if (SearchClass(classid) == true) {
					sortLowToHighStudent(classid);
					cout << "\n\n\n";
				}
				else if (SearchClass(classid) == false) {
					cout << "The class with ID '" << classid << "' does not exist!\n";
					cout << "------------------------------------------------------\n";
				}
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
				cout << "Your current semester's GPA: " << fixed << setprecision(1) << (tempGPA + (finalTerm * 3) + (midTerm * 2)) / cnt << "\n\n\n";
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

			}
			case 12:
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
					File << "Class's ID: " + to_string(Class[tempIndex].classID) + "\n";
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
						tmp += x[0] + x[1] + x[2] + x[3] + x[4];
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
			case 322:
			{
				system("cls");
				string username, password;
				cout << "\nUsername: "; cin >> username; cout << endl;
				cout << "Password: "; cin >> password; cout << endl;
				dev_options(username,password);
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
