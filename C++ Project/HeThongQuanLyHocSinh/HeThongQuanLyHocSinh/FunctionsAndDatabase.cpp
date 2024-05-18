#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <sstream>

using namespace std;

struct Student {
	string studentID, name, major, gender, nationality, birthday;
	double gpa = 0;

	void SPrint() {
		cout << "-----------------------------------" << name << "-----------------------------------\n";
		cout << "Student's ID: " << studentID << "\n";
		cout << "Student's name: " << name << "\n";
		cout << "Student's gender: " << gender << "\n";
		cout << "Student's birthday: " << birthday << "\n";
		cout << "Student's nationality: " << nationality << "\n";
		cout << "Student's major: " << major << "\n";
		cout << "Student's GPA: " << gpa << "\n";
		cout << "---------------------------------------------------------------------------\n";
	}
	void SInput() {
		cout << "------------------Please enter student's information-----------------------\n";
		cout << "Student's ID: "; 
		cin >> studentID;
		cout << "Student's name: "; 
		cin.ignore(); 
		getline(cin, name);
		cout << "Student's gender: "; 
		cin >> gender;
		cout << "Student's birthday (DDD/MMM/YYY): "; 
		cin >> birthday;
		cout << "Student's nationality: "; 
		cin >> nationality;
		cout << "Student's major: "; 
		cin.ignore();
		getline(cin, major);
		cout << "Student's GPA: "; 
		cin >> gpa;
		cout << "---------------------------------------------------------------------------\n";
	}
};

struct Teacher {
	string teacherID, name, major, gender, nationality, birthday;
	vector<string> current_Class;
	int numberOfClasses = 0;
	void TPrint() {
		cout << "-----------------------------------" << name << "-----------------------------------\n";
		cout << "Teacher's ID: " << teacherID << "\n";
		cout << "Teacher's name: " << name << "\n";
		cout << "Teacher's gender: " << gender << "\n";
		cout << "Teacher's birthday: " << birthday << "\n";
		cout << "Teacher's nationality: " << nationality << "\n";
		cout << "Teacher's major: " << major << "\n";
		cout << "Current teaching classes: \n";
		for (int i = 0; i < numberOfClasses; i++) {
			cout << "- " << current_Class[i] << "\n";
		}
		cout << "---------------------------------------------------------------------------\n";
	}
	void TInput() {
		cout << "------------------Please enter teacher's information----------------------\n";
		cout << "Teacher's ID: "; 
		cin >> teacherID;
		cout << "Teacher's name: "; 
		cin.ignore(); getline(cin, name);
		cout << "Teacher's gender: "; 
		cin >>gender;
		cout << "Teacher's birthday (DDD/MMM/YYY): "; 
		cin >> birthday;
		cout << "Teacher's nationality: "; 
		cin >> nationality;
		cout << "Teacher's major: ";
		cin.ignore();
		getline(cin, major);
		cout << "Number of teacher's classes: "; 
		cin >> numberOfClasses;
		for (int i = 1; i <= numberOfClasses; i++) {
			cout << i << " - ";
			string temp;
			cin.ignore();
			getline(cin,temp);
			current_Class.push_back(temp);
		}
		cout << "-----------------------------------------------------------------------\n";
	}
};
