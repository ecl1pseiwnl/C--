#include <iostream>
#include <cmath>
using namespace std;

int a[100][100];

int snt(int a) {
	if (a < 2) return 0;
	for (int i = 0; i * i <= a; i++) {
		if (a % i == 0) {
			return 0;
		}
	}
	return 1;
}
int ktTG(int a[100][100], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > a[i+1][j]) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	int n, m, d = 0;
	int maxval = INT_MIN;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	if (ktTG(a,n, m) == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (snt(a[i][j] == 1)) {
					d++;
					if (a[i][j] > maxval) {
						maxval = a[i][j];
					}
				}
			}
		}
		if (d < 1) {
			cout << "-1";
		}
		else {
			cout << "YES" << endl << maxval;
		}
	}
	else {
		cout << "NO";
	}
}