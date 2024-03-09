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

int n, m, a[105][105], f[105][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	//danh dau de khong tinh sai ket qua
	for (int i = 0; i < m; i++) {
		f[0][i] = f[n + 1][i] = -1e9;
	}

	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			f[i][j] = max(f[i - 1][j - 1], max(f[i][j - 1], f[i + 1][j - 1])) + a[i][j];
		}
	}
	int ans = -1e9;
	for (int i = 1; i <= n; i++) ans = max(ans, f[i][m]);
	cout << ans;
	return 0;
}