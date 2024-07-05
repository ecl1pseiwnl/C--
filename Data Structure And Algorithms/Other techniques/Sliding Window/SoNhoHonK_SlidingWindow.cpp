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
	int n, k;
	cin >> n;
	int a[n], d = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] <= k) d++;
	}
	for (int i = 0; i < d; i++) {
		if (a[i] <= k) ++cnt;
	}
	int ans = cnt;
	for (int i = d; i < n; i++) {
		if (a[i - d] <= k) --cnt;
		if (a[i] <= k) ++cnt;
		ans = max(ans, cnt);
	}
	cout << d - ans;
	return 0;
}