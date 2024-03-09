#include <iostream>
#include <cmath>
using namespace std;

int a[10];

int main() {
	int n, s = 0, t;
	cin >> n;
	int m = n;
	for (int i = 1; i <= 9; i++) {
		a[i] = pow(i, 3);
	}
	while (n != 0) {
		t = n % 10;
		s += a[t];
		n /= 10;
	}
	if (s == m) {
		cout << n << " la so Armstrong";
	}
	else cout << n << " khong la so Armstrong";
}