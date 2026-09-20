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

int n, dp[25005], a[25005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}
	dp[2] = a[1];
	dp[3] = a[1] + a[2];
	for (int i = 4; i <= n; i++) {
		dp[i] = min(dp[i - 2] + a[i - 1], dp[i - 1] + a[i - 1]);
	}
	cout << dp[n];
	return 0;
}