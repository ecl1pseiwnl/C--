#include <iostream>
using namespace std;

int giaithua(int n) {
	int s = 1;
	if (n == 0) {
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		s *= i;
	}
	return s;
}

int factorial(int n) {
	if (n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

int main() {
	int n, s = 0, t;
	cin >> n;
	int m = n;
	while (n != 0) {
		t = n % 10;
		s += giaithua(t);
		n /= 10;
	}
	if (s == m) {
		cout << "1";
	}
	else cout << "0";
}