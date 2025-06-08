#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll n; cin >> n;
	ll tong = 0;
	for (int i = 1; i * i < n; i++) {
		if (n % i == 0) {
			tong += i + n / i;
		}
		if (i * i == n) {
			tong -= i;
		}
	}
	tong -= n;
	if (tong > n) {
		cout << "1";
	}
	else {
		cout << "0";
	}
	return 0;
}