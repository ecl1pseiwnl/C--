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

const int N = 100005;
int n, k, a[N], f[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int x; cin >> x;
		a[x] = 1;
	}
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == 1) continue;
		f[i] = (f[i - 1] + f[i - 2]) % 14062008;
	}
	cout << f[n];
	return 0;
}