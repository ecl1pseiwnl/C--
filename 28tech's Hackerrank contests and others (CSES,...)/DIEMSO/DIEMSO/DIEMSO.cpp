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

bool cmp(pi x, pi y) {
	return x.second > y.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, pos[101];
	string s[101];
	pi p[101];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> s[i] >> x >> y;
		p[i].first = i;
		p[i].second = x + y;
	}
	sort(p, p + n, cmp);
	int id = 1; pos[p[1].first] = 1;
	for (int i = 2; i <= n; i++) {
		if (p[i].second != p[i - 1].second) {
			id++;
		}
		pos[p[i].first] = id;
	}
	for (int i = 1; i <= n; i++) {
		cout << s[i] << " " << pos[i] << "\n";
	}
	return 0;
}