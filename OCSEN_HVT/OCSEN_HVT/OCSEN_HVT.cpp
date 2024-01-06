#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll a, b, v, cnt = 0, s = 0;
	cin >> a >> b >> v;
	while (v) {
		if (s < v) {
			s += a;
			cnt++;
			if (s == v) {
				cout << cnt;
				break;
			}
			s -= b;
		}
	}
}