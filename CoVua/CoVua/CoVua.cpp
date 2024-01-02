#include <iostream>
using namespace std;
int a[9][9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x1, x2, y1, y2;
	char c, d;
	cin >> c >> x2;
	int x1 = int(c) - 96, x2 = 9 - x2;
	cin >> d >> y2;
	int y1 = int(d) - 96, y2 = 9 - y2;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			a[i][j] = 0;
		}
	}
	a[x1][x2] = 1;
	a[y1][y2] = 1;
	for (int i = 0; i < 8; i++) {
		a[x1][i] = 1;
		a[i][x2] = 1;
	}
	for (int i = 0; i < 8; i++) {
		if (x2 + a[x1][i] >= 0 && y2 + a[i][y1] >= 0) {
			a[x2 + x1][y1 + y2] = 1;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (x1 + a[x1][i] >= 0 && y2 + a[i][y1] >= 0) {
			a[x1 + x2][y1 + y2] = 1;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (a[i][j] == 0) {
				cnt++;
			}
		}
	}
	cout << cnt;
}