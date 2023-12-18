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
	cout << endl;
	for (int i = 0; i < n;i++) {
		int minCol = INT_MAX, maxCol = INT_MIN, minY = 0, maxY = 0;
		for (int j = 0; j < m;j++) {
			if (minCol > a[j][i]) {
				minCol = a[j][i];
				minY = j + 1;
			}
			if (maxCol < a[j][i]) {
				maxCol = a[j][i];
				maxY = j + 1;
			}
		}
		cout << minCol << " " << minY << " " << maxCol << " " << maxY << endl;
	}
}