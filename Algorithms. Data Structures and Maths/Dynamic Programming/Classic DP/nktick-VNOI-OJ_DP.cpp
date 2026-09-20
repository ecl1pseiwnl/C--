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
const int N = 60005;
int n, t[N], r[N], f[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 1; i < n; i++) cin >> r[i];
	f[1] = t[1];
	for (int i = 2; i <= n; i++) {
		f[i] = min(f[i - 1] + t[i], f[i - 2] + r[i - 1]);
		// so sánh nma lú vcl
	}
	cout << f[n];
	return 0;
}
