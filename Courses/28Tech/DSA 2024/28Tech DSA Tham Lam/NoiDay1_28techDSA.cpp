#include <bits/stdc++.h>
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
	int n;
	cin >> n;
	ll val, res = 0;
	priority_queue<ll, vector<ll>, greater<ll>> q;
	for (int i = 0; i < n; i++) {
		cin >> val;
		q.push(val);
	}

	while (q.size() > 1) {
		ll x = q.top(); q.pop();
		ll y = q.top(); q.pop();
		q.push(x + y);
		res += x + y;
	}
	cout << res;
	return 0;
}