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
	vi a(n + 1), dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1] = 0;
	dp[2] = abs(a[1] - a[2]);
	for (int i = 3; i <= n; i++) {
		dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
	}
	cout << dp[n];
	return 0;
}