#include <iostream>
using namespace std;
int a[102][102];

bool yenngua(int a[102][102], int r, int c, int n, int m) {
	int maxRow = a[r][0];
	for (int i = 0; i < m; i++) {
		if (maxRow < a[r][i]) {
			maxRow = a[r][i];
		}
	}

	int minCol = a[0][c];
	for (int i = 0; i < n; i++) {
		if (minCol > a[i][c]) {
			minCol = a[i][c];
		}
	}
	int minRow = a[r][0];
	for (int i = 0; i < m; i++) {
		if (minRow > a[r][i]) {
			minRow = a[r][i];
		}
	}
	int maxCol = a[0][c];
	for (int i = 0; i < n; i++) {
		if (maxCol < a[i][c]) {
			maxCol = a[i][c];
		}
	}

	return (a[r][c] == maxRow && a[r][c] == minCol) || (a[r][c] == minRow && a[r][c] == maxCol);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (yenngua(a, i, j, n, m)) {
				cout << i+1 << " " << j+1 << endl;
			}
		}
	}
}