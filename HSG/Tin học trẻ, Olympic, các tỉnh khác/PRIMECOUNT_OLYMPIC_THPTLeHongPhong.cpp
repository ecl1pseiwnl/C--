#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mp;
#define endl "\n"
#define mp make_pair
#define pb push_back
const int N = 1e7;
int a[N], F[N];

void sangsnt() {
	memset(a, 0, sizeof(a));
	a[1] = a[0] = 1;
	for (ll i = 2; i <= sqrt(N); i++) {
		if (a[i] == 0) {
			for (ll j = i * i; j <= N; j += i) {
				a[j] = 1;
			}
		}
	}
	F[1] = F[0] = 0;
	for (ll i = 2; i <= N; i++) {
		if (a[i] == 0) {
			F[i] = F[i - 1] + 1;
		}
		else {
			F[i] = F[i - 1];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t, l, r;
	cin >> t;
	sangsnt();
	while (t--) {
		cin >> l >> r;
		cout << F[r] - F[l - 1] << endl;
	}
}