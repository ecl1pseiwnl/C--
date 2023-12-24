#include <iostream>
using namespace std;
typedef long long ll;
const ll maxN = 1e7+1;
ll a[maxN];
ll F[maxN];

int main() {
	ll l, r, s = 0;
	cin >> l >> r;
	for (int i = 0; i < maxN; i++) {
		if (i % 2 == 0) {
			a[i] = i;
		}
		else {
			a[i] = 0;
		}
	}
	cout << a[r] + a[l-1];
}