#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll l, r, s = 0;
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		if (i % 2 == 0) {
			s += i;
		}
	}
	cout << s;
}