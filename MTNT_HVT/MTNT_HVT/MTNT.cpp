#include <iostream>
#include <cmath>
using namespace std;

int a[102][102];
int maxsnt = INT_MIN;

int KtraTgGi(int a[102][102], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] < a[i][j + 1]) {
				return 1;
			}
		}
	}
	return 0;
}

int snt(int n) {
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	int n, m, dem = 0;
	bool tf;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (snt(a[i][j]) == 1) {
				dem = 1;
			}
			if (maxsnt < a[i][j] && snt(a[i][j])) {
				maxsnt = a[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (KtraTgGi(a, n, m) == 1) {
				tf = true;
			}
			else {
				tf = false;
				break;
			}
		}
	}
	if (dem == 0) {
		cout << "-1";
	}
	else if (maxsnt == 0) {
		cout << "-1";
	}
	else if (dem > 0 && maxsnt > 0 && tf == true) {
		cout << "YES" << endl << maxsnt;
	}
	else {
		cout << "NO";
	}
}
