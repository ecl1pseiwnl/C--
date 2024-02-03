#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mp;
#define endl cout << "\n";
#define mp make_pair
#define pb push_back

struct tien {
	int a, b;
};

bool cmp(tien c, tien d) {
	if (c.a == d.a) {
		return c.a < d.a;
	}
	return c.b < d.b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	tien in[n];
	for (int i = 0; i < n; i++) {
		cin >> in[i].a >> in[i].b;
	}
	sort(in, in + n, cmp);
	for (auto x : in) {
		cout << x.a << " " << x.b; endl
	}
	return 0;
}

// Cach khac:
bool cmp(pi x, pi y) {
	if (y.second == x.second) return y.second > x.second;
	return x.first < y.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	pi p[n];
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		p[i] = make_pair(x, y);
	}
	sort(p, p + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << p[i].first << " " << p[i].second; endl
	}
	return 0;
}