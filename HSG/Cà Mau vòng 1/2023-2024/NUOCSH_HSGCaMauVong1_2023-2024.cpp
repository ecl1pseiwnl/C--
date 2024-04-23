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
	int n, cur = 0, cnt = 0, ans = INT_MIN, res = INT_MIN;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		cur += a[i];
		cnt++;
		if (cur < 0) {
			cur = 0;
			cnt = 0;
		}
		ans = max(ans, cur);
		res = max(res, cnt);
	}
	cout << ans << " " << res;
	return 0;
}