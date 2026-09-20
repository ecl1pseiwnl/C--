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

const int N = 30010;
int n, f[N];
vi a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		a[y].pb(x);
	}
	for (int i = 1; i <= N; i++) {
		f[i] = f[i - 1];
		for (int j = 0; j < a[i].size(); j++) {
			f[i] = max(f[i], f[a[i][j]] + i - a[i][j]);
		}
	}
	cout << f[N];
	return 0;
}