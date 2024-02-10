#include <iostream>
#include <string>
#include "Data.cpp"
using namespace std;

string name, mshs;
int age;
double toan, ly, tanh, van, hoa;

void inp() {
    cout << "Vui long nhap ho va ten hoc sinh: ";
    getline(cin, name);
    cout << endl;

    cout << "Vui long nhap ma so hoc sinh: ";
    cin >> mshs;
    cout << endl;
    cout << "Vui long nhap tuoi cua hoc sinh: ";
    cin >> age;
    cout << endl;
    cout << "Vui long nhap diem mon Toan cua hoc sinh: ";
    cin >> toan;
    cout << endl;
    cout << "Vui long nhap diem mon Ly cua hoc sinh: ";
    cin >> ly;
    cout << endl;
    cout << "Vui long nhap diem mon Van cua hoc sinh: ";
    cin >> van;
    cout << endl;
    cout << "Vui long nhap diem mon Tieng Anh cua hoc sinh: ";
    cin >> tanh;
    cout << endl;
    cout << "Vui long nhap diem mon Hoa cua hoc sinh: ";
    cin >> hoa;
    cout << endl;
    cout << "---------------------------------" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    inp();
    HocSinh hs1(name, mshs, age, toan, ly, van, hoa, tanh);
    hs1.display();
    hs1.TBM();
}