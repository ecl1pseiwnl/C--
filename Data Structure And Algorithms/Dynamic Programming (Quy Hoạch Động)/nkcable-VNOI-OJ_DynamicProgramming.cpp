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

const int N = 100010;
int n, f[N], a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}
	f[2] = a[1]; f[3] = a[1] + a[2];
	for (int i = 4; i <= n; i++) {
		f[i] = min(f[i - 2] + a[i - 1], f[i - 1] + a[i - 1]);
	}
	cout << f[n];
	return 0;
}