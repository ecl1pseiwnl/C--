#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	int HangNghin = n / 1000, HangDonVi = n % 10;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	cout << sum << endl;
	cout << HangNghin << " " << HangDonVi;
}