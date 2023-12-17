#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double SoLuongDiemThuongXuyen, DiemKiemTraGiuaKi, DiemKiemTraCuoiKi, DiemThuongXuyen, TBM = 0;
	int dem = 0;

	cout << "Nhap so luong diem thuong xuyen: ";
	cin >> SoLuongDiemThuongXuyen;
	cout << endl << "Nhap diem cua bai kiem tra giua ki: ";
	cin >> DiemKiemTraGiuaKi;
	cout << endl << "Nhap diem cua bai kiem tra cuoi ki: ";
	cin >> DiemKiemTraCuoiKi;
	cout << endl;
	dem += SoLuongDiemThuongXuyen + 2 + 3;

	for (int i = 1; i <= SoLuongDiemThuongXuyen; i++) {
		cout << "Hay nhap diem thuong xuyen thu " << i << ":";
		cin >> DiemThuongXuyen;
		TBM += DiemThuongXuyen;
		cout << endl;
	}

	cout << fixed << setprecision(1)<< "Diem trung binh mon la: " << (TBM + (DiemKiemTraGiuaKi * 2) + (DiemKiemTraCuoiKi * 3))/ dem;
	return 0;
}