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
	int n, k;
	cin >> n >> k;
	vi a(n + 1, 0), dp(n + 1);
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		a[x] = 1;
	}
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == 1) continue;
		dp[i] = (dp[i - 1] + dp[i - 2]) % 14062008;
	}
	cout << dp[n];
	return 0;
}