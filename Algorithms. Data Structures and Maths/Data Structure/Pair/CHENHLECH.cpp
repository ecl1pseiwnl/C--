#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define endl cout << "\n";
#define mp make_pair
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	mii m;
	pi p[n];
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		p[i] = make_pair(x, y);
		m[abs(p[i].first - p[i].second)]++;
	}
	int minv, cnt = 0;
	for (auto x : m) {
		if (cnt < x.second) {
			minv = x.first;
			cnt = x.second;
		}
	}
	cout << minv; endl
	for (int i = 0; i < n; i++) {
		if (abs(p[i].first - p[i].second) == minv) {
			cout << p[i].first << " " << p[i].second; endl
		}
	}
	return 0;
} 