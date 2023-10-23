#include <iostream>
using namespace std;

int main() {
	long long TienGoc;
	double TienLai;
	int SoNamGui;
	cout << "Nhap So Tien Goc: ";
	cin >> TienGoc;
	cout << "Nhap So Phan Tram Lai: ";
	cin >> TienLai;
	cout << "Nhap So Nam Gui Tien: ";
	cin	>> SoNamGui;
	for (int i = 0; i < SoNamGui; i++) {
		TienGoc += TienGoc * TienLai;
	}
	cout << "So Tien Nhan Duoc Sau " << SoNamGui << " Nam Gui La " << TienGoc << endl;
}