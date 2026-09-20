#include <iostream>
#include <cmath>
using namespace std;

int a[102][102];
int maxsnt = INT_MIN;

int snt(int n) {
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, dem = 0;
	bool truefalse;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		bool tf = true;
		for (int j = 0; j < m - 1; ++j) {
			if (a[i][j] > a[i][j + 1]) {
				tf = false;
				break;
			}
		}
		if (tf == true) {
			truefalse = true;
			break;
		}
	}
	if (truefalse == false) {
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maxsnt < a[i][j] && snt(a[i][j])) {
				maxsnt = a[i][j];
			}
		}
	}
	if (maxsnt > 0) {
		cout << maxsnt;
	}
	else {
		cout << "-1";
	}
}
