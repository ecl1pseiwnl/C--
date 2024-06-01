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
	vi t(n + 1), r(n + 1), dp(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> r[i];
	}
	dp[1] = t[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i - 1]);
	}
	cout << dp[n];
	return 0;
}