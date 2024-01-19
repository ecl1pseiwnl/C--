#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mp;
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, cnt = 0;
	cin >> n >> k;
	vi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vi dp(n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] + v[j] >= k) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	for (auto x : dp) {
		cout << x << ' ';
	}
	cout << endl;
	cout << *min_element(dp.begin(), dp.end());
}