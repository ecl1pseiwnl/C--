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

const int N = 1e6;
bool a[N];

void snt() {
	memset(a, true, sizeof(a));
	a[1] = a[0] = 0;
	for (int i = 2; i <= sqrt(N); i++) {
		if (a[i]) {
			for (int j = i * i; j <= N; j += i) {
				a[j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k, cnt = 0;
	cin >> n >> k;
	snt();
	for (ll i = 1; i < n; i++) {
		for (ll j = 1; j < n; j++) {
			if (a[i] == true && a[j] == true && j - i == k) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}