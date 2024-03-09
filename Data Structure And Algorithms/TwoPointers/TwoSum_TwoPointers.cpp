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
	ll n, x;
	cin >> n >> x;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	int l = 0, r = n - 1;
	while (l < r) {
		ll sum = v[l].first + v[r].first;
		if (sum == x) {
			cout << v[l].second + 1 << " " << v[r].second + 1;
			return 0;
		}
		else if (sum < x) {
			++l;
		}
		else --r;
	}
	cout << "IMPOSSIBLE";
	return 0;
}