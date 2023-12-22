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

}