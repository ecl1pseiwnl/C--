#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int Nam = 0;
	int Tuan = 0;
	int Ngay = 0;
	while (n >= 0) {
		if (n >= 365) {
			n = n - 365;
			Nam++;
		}
		else if (n >= 7) {
			n = n - 7;
			Tuan++;
		}
		else if (n < 7) {
			Ngay++;
		}
		else {
			Nam = 0;
			Tuan = 0;
			Ngay = 0;
		}
	}
	cout << Nam << " " << Tuan << " " << Ngay << " ";
}