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

int n, m, f[1005][1005], a[1005][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		a[n + 1][i] = a[i][m + 1] = 1e9;
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			f[i][j] = min(f[i + 1][j + 1], min(f[i][j + 1], f[i + 1][j])) + a[i][j];
		}
	}
	int ans = 1e9;
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (f[i][j] != -1) {
				ans = min(ans, f[i][j]);
			}
		}
	}
	cout << ans;
	return 0;
}