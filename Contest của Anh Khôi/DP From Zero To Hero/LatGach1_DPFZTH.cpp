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

const int N = 1e6 + 7;
int dp[N];

void fibo() {
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fibo();
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		cout << dp[x] << endl;
	}
	return 0;
}