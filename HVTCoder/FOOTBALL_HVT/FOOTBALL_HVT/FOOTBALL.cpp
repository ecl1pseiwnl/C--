#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[102][102];

bool check(int a[102][102], int i, int j) {
	if (a[i][i] == 0 && i == j) {
		return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int highestScore = 0;
	for (int i = 0; i < n; i++) {
		int TotalScore = 0;
		for (int j = 0; j < n; j++) {
			TotalScore += a[i][j];
		}
		v.push_back(TotalScore);
	}
	for (int i = 0; i < n; i++) {
		if (highestScore < v[i]) {
			highestScore = v[i];
		}
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += a[i][j];
		}
		if (sum == highestScore) {
			cout << i + 1 << ' ';
		}
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		int W = 0, L = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 3) {
				W++;
			}
			if (j != i && a[i][j] == 0) {
				L++;
			}
		}
		if (W > L) {
			cout << i + 1 << ' ';
		}
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		int L = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				L++;
			}
		}
		if (L - 1 == 0) {
			cout << i + 1 << ' ';
		}
	}
}