#include <iostream>
using namespace std;

int a[101][101];
int main() {
	int n, m, s = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			s += a[i][j];
			if (a[i][j] > 0) {
				s1 += a[i][j];
			}
			if (a[i][j] < 0) {
				s2 += a[i][j];
			}
			if (a[i][j] % 2 == 0) {
				s3 += a[i][j];
			}
			if (a[i][j] % 2 == 1) {
				s4 += a[i][j];
			}
		}
	}
	cout << s << endl << s1 << endl << s2 << endl << s3 << endl << s4;
}