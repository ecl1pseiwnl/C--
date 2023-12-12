#include <iostream>
using namespace std;

int a[100][100];

int main() {
	int n, m, s = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[j][i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			s += a[j][i];
		}
		cout << s << " ";
		s = 0;
	}
	cout << endl;

}