#include <iostream>
#include <cmath>
using namespace std;

int a[10001];

int main() {
	int n, s = 0, t;
	cin >> n;
	int m = n;
	for (int i = 1; i <= 9; i++) {
		a[i] = pow(i,3);
	}
	while (n != 0) {
		t = n % 10;
		cout << t << endl;
		s += a[t];
		n /= 10;
	}
	cout << s << endl;
	if (s == m) {
		cout << "1";
	}
	else cout << "0";
}