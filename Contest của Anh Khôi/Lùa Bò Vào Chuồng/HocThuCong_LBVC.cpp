#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, x = 0, y = 0;
	cin >> n;
	unordered_map<ll,ll> m;
	while (n--) {
		int x;
		cin >> x;
		m[x]++;
	}
	for (auto it : m) {
		if (it.second >= 3) {
			x += (it.second / 3);
			it.second %= 3;
		}
		y += it.second;
	}
	cout << x << " " << y;
	return 0;
}