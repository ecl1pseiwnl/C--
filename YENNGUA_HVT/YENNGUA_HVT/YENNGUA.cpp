#include <iostream>
using namespace std;
int a[102][102];

int dk1(int a[102][102], int n, int m) {
	for (int i = 0; i < n; i++) {
		int maxRow = a[i][0], minColIndex = 0;
		for (int j = 0; j < m; j++) {
			if (maxRow < a[i][j]) {
				maxRow = a[i][j];
				minColIndex = j;
			}
		}
		int k, dem = 0;
		for (k = 0; k < n; k++) {
			if (maxRow < a[k][minColIndex]) {
				++dem;
			}
		}
		if (dem == n - 1) {
			return maxRow;
		}
	}
}
int dk2(int a[102][102], int n, int m) {
	for (int i = 0; i < n; i++) {
		int maxCol = a[0][i], minRowIndex = 0;
		for (int j = 0; j < m; j++) {
			if (maxCol < a[i][j]) {
				maxCol = a[i][j];
				minRowIndex = j;
			}
		}
		int k, dem = 0;
		for (k = 0; k < n; k++) {
			if (maxCol < a[minRowIndex][k]) {
				++dem;
			}
		}
		if (dem == n - 1) {
			return maxCol;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dk1(a, n, m) == a[i][j]) {
				cout << i + 1 << " " << j + 1 << endl;
			}
			else if (dk2(a, n, m) == a[i][j]) {
				cout << i + 1 << " " << j + 1 << endl;
			}
		}
	}
}