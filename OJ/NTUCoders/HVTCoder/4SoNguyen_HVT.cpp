#include <iostream>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int sum = a + b + c + d;
	int HangChuc = (sum / 10)%10, HangDonVi = sum % 10;
	cout << sum << endl << HangChuc << " " << HangDonVi;
}