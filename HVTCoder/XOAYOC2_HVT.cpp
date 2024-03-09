#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[102][102];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int m, n;
	cin >> m >> n;
	vector<int> v;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			v.push_back(a[i][j]);
		}
	}
	sort(v.begin(), v.end());
	int k = 0, p = 0, col = n, row = m;
	while (k + 1 <= m * n) {
		for (int i = p; i < col; i++) {
			a[p][i] = v[k++];
		}
		for (int j = p + 1; j < row; j++) {
			a[j][col - 1] = v[k++];
		}
		if (p != row - 1) {
			for (int i = col - 2; i >= p; i--) {
				a[row - 1][i] = v[k++];
			}
		}
		if (p != col - 1) {
			for (int i = row - 2; i > p; i--) {
				a[i][p] = v[k++];
			}
		}
		p++; row--; col--;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}