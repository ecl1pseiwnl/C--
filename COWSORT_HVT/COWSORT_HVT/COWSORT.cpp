#include <iostream>
using namespace std;

int main() {
	int n, dem = 0;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		for (int j = i - 1; j < n; ++j) {
			if (a[j] < a[i]) {
				dem++;
				swap(a[i], a[j]);
			}
		}
	}
	cout << dem;
	return 0;
}