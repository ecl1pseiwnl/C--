#pragma once
#include <iostream>
using namespace std;

class HocSinh {
private:
	string HoVaTen, MaSoHocSinh;
	int Tuoi;
	double Toan, Ly, Van, TAnh, Hoa;
public:
	HocSinh(string HoVaTen, string MaSoHocSinh, int Tuoi, double Toan, double Ly, double Van, double TAnh, double Hoa) {
		this->HoVaTen = HoVaTen;
		this->MaSoHocSinh = MaSoHocSinh;
		this->Tuoi = Tuoi;
		this->Toan = Toan;
		this->Ly = Ly;
		this->Van = Van;
		this->TAnh = TAnh;
		this->Hoa = Hoa;
	}
	string getHoVaTen() {
		return HoVaTen;
	}
	string getMaSoHocSinh() {
		return MaSoHocSinh;
	}
	int getTuoi() {
		return Tuoi;
	}
	void setDiemToan(double Toan) {
		this->Toan = Toan;
	}
	void setDiemVan(double Van) {
		this->Van = Van;
	}
	void setDiemLy(double Ly) {
		this->Ly = Ly;
	}
	void setDiemHoa(double Hoa) {
		this->Hoa = Hoa;
	}
	void setDiemTAnh(double TAnh) {
		this->TAnh = TAnh;
	}
	double getDiemToan() {
		return Toan;
	}
	double getDiemLy() {
		return Ly;
	}
	double getDiemVan() {
		return Van;
	}
	double getDiemTAnh() {
		return TAnh;
	}
	double getDiemHoa() {
		return Hoa;
	}
	void display() {
		cout << "Ho va ten hoc sinh la: " << HoVaTen << endl;
		cout << "Ma so hoc sinh la: " << MaSoHocSinh << endl;
		cout << "Tuoi cua hoc sinh la: " << Tuoi << endl;
	}
	void TBM() {
		cout << "Tong diem trung binh cua hoc sinh la: " << (Toan + Hoa + Ly + Van + TAnh) / 5;
	}
};
