#include <iostream>

using namespace std;
int a[102][102];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m;) {
		int minRow = INT_MAX, maxRow = INT_MIN, minX = 0, maxX = 0;
		for (int j = 0; j < n;j++) {
			if (minRow > a[i][j]) {
				minRow = a[i][j];
				minX = j + 1;
			}
			if (maxRow < a[i][j]) {
				maxRow = a[i][j];
				maxX = j + 1;
			}
		}
		cout << minRow << " " << minX << " " << maxRow << " " << maxX << endl;
		i++;
	}
}