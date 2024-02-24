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
	ll n, k, sum = 0;
	cin >> n >> k;
	int a[n];
	for (int& it : a) cin >> it;
	int r = 0, l = 0, ans = 1e9;
	for (r = 0; r < n; r++) {
		sum += a[r];
		while (sum >= k) {
			ans = min(ans, r - l + 1);
			sum -= a[l];
			l++;
		}
	}
	if (ans == 1e9) {
		cout << "-1";
	}
	else {
		cout << ans;
	}
	return 0;
}