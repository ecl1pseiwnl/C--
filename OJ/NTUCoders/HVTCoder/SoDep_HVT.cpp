#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int du = 0;
	bool tf = false;
	while (n != 0) {
		du = n % 10;
		if (du == 8 || du == 6) {
			tf = true;
		}
		else {
			tf = false;
			break;
		}
		n = n / 10;
	}
	if (tf == true) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}
