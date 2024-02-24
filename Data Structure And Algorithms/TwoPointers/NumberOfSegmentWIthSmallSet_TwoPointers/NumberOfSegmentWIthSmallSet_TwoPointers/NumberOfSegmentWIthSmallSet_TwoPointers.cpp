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
	int a[n], dem[100001] = { 0 }, cnt = 0;
	for (int& it : a) cin >> it;
	ll l = 0, r = 0;
	for (r = 0; r < n; r++) {
		dem[a[r]]++;
		if (dem[a[r]] == 1) {
			cnt++;
		}
		while (cnt > k) {
			if (dem[a[l]] == 1) --cnt;
			dem[a[l]]--;
			l++;
		}
		ans += r - l + 1;
	}
	cout << ans;
	return 0;
}