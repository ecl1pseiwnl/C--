#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>

class Human {
private:
	std::string name;
	std::string id;
	std::string gender;
	int age;
public:
	Human() {

	}
	Human(std::string name, std::string id, std::string gender , int age) {
		this->name = name;
		this->id = id;
		this->age = age;
	}
	std::string getName() {
		return name;
	}
	std::string getID() {
		return id;
	}
	std::string getGender() {
		return gender;
	}
	int getAge() {
		return age;
	}
	void setName(std::string name) {
		this->name = name;
	}
	void setID(std::string id) {
		this->id = id;
	}
	void setGender(std::string gender) {
		this->gender = gender;
	}
	void setAge(int age) {
		this->age = age;
	}
	void display() {
		std::cout << "Ten: " << getName() << std::endl;
		std::cout << "Gioi tinh cua nguoi can tim: " << getGender() << std::endl;
		std::cout << "Tuoi cua nguoi can tim: " << getAge() << std::endl;
		std::cout << "Ma so cua nguoi can tim: " << getID() << std::endl;
	}
};

class Student : Human {
private:
	double gpa;
	double Math, Physic, English, Literature, Chemistry;
	int rank;
public:
	Student() {

	}
	Student(std::string name, std::string id, std::string gender, int age, double Math, double Physic, double English, double Literature, double Chemistry) :Human(name,id,gender,age) {
		this->Math = Math;
		this->Physic = Physic;
		this->Chemistry = Chemistry;
		this->English = English;
		this->Literature = Literature;
	}
	double getMath() {
		return Math;
	}
	double getPhysic() {
		return Physic;
	}
	double getEnglish() {
		return English;
	}
	double getLiterature() {
		return Literature;
	}
	double getChemistry() {
		return Chemistry;
	}
	void setMath(double Math) {
		this->Math = Math;
	}
	void setPhysic(double Physic) {
		this->Physic = Physic;
	}
	void setEnglish(double English) {
		this->English = English;
	}
	void setLiterature(double Literature) {
		this->Literature = Literature;
	}
	void setChemistry(double Chemistry) {
		this->Chemistry = Chemistry;
	}
	double getGPA_Plan1(double Math,double Physic,double English) {
		std::cout << std::fixed << std::setprecision(1) << (Math + Physic + English) / 3;
	}
	double getGPA_Plan2(double Math, double Literature, double English) {
		std::cout << std::fixed << std::setprecision(1) << (Math + Literature + English) / 3;
	}
	double getGPA_Plan3(double Math, double Physic, double Chemistry) {
		std::cout << std::fixed << std::setprecision(1) << (Math + Physic + Chemistry) / 3;
	}
	double getGPA_Plan4(double Math, double Literature, double Physic) {
		std::cout << std::fixed << std::setprecision(1) << (Math + Literature + Physic) / 3;
	}
	void display(){
		Human::display();
		std::cout << "Tong diem GPA theo phuong an 1: " << getGPA_Plan1(Math, Physic, English) << std::endl;
		std::cout << "Tong diem GPA theo phuong an 2: " << getGPA_Plan2(Math, Literature, English) << std::endl;
		std::cout << "Tong diem GPA theo phuong an 3: " << getGPA_Plan3(Math, Physic, Chemistry) << std::endl;
		std::cout << "Tong diem GPA theo phuong an 4: " << getGPA_Plan4(Math, Literature, Physic) << std::endl;
	}
};