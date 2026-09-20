#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
const ll maxN = 1e8+1;
ll F[maxN];

int main() {
	ll l, r, s = 0;
	cin >> l >> r;
	for (int i = 0; i <= sqrt(maxN); i++) {
		if (i % 2 == 0) F[i] = F[i - 1] + i;
		else {
			F[i] = F[i - 1];
		}
	}
	if (l == 0) {
		cout << F[r];
	}
	else {
		cout << F[r] - F[l - 1];
	}
}