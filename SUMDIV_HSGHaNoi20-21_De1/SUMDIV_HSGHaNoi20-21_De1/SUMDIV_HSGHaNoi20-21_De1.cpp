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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll l, r, s = 0;
	cin >> l >> r;
	set<ll> se;
	for (int i = l; i <= r; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				se.insert(j);
			}
		}
	}
	for (auto x : se) {
		s += x;
	}
	cout << s;
	return 0;
}