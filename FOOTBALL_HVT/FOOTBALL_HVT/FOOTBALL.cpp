#include <iostream>
using namespace std;
int a[102][102];

bool dgcheochinh(int a[102][102], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i][i] != 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	if (dgcheochinh(a, n) == true) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

			}
		}
	}
}