#include <iostream>

using namespace std;
typedef long long ll;
int snt(ll n) {
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	ll l, r, cnt = 0;
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		if (snt(i) == 1 && snt(i + 2) == 1 && i + 2 <= r) {
			cnt++;
		}
	}
	cout << cnt;
}