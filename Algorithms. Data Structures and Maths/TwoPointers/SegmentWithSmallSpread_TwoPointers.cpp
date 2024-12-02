#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k, ans = 0;
	cin >> n >> k;
	int a[n];
	for (int& it : a) cin >> it;
	multiset<ll> ms;
	int l = 0, r;
	for (r = 0; r < n; r++) {
		ms.insert(a[r]);
		while (*ms.rbegin() - *ms.begin() > k) {
			auto it = ms.find(a[l]);
			ms.erase(it);
			++l;
		}
		ans += r - l + 1;
	}
	cout << ans;
	return 0;
}