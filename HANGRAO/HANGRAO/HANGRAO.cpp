#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mi = 1e7, t = 0, k = 1e7;
	ll cmp = 0;
	for (int i = 0; i < n; i++) {
		int dem = 0;
		for (int j = 0; j < n; j++) {
			dem += abs(a[i] - a[j]);
		}
		if (dem < k) {
			t = a[i];
			k = dem;
		}
	}
	for (int i = 0; i < n; i++) {
		cmp += abs(t - a[i]);
	}
	cout << t << endl << cmp;
}