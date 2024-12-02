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
	int n, k, b;
	cin >> n >> k >> b;
	int a[10001] = { 0 };
	for (int i = 0; i < b; i++) {
		int x; cin >> x;
		a[x] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= k; i++) {
		if (a[i] == 1) cnt++;
	}
	int ans = cnt;
	for (int i = k + 1; i <= n; i++) {
		cnt = cnt - a[i - k] + a[i];
		ans = min(cnt, ans);
	}
	cout << ans << endl;
	return 0;
}