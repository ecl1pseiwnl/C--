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

int f[1005], a[1005], ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) {
				if (f[j]+1 > f[i]) f[i] = max(f[i],f[j] + 1);
			}
		}
		f[i] = max(f[i], f[i - 1]);
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] > ans) ans = f[i];
	}
	cout << endl << ans;
	return 0;
}