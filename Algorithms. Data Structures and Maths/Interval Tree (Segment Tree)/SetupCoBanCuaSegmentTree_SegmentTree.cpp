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

int n,a[1000], t[4 * 10];

void build(int id, int l, int r) {
	if (l == r) {
		return t[id] = a[l], void();
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	t[id] = t[id * 2] + t[id * 2 + 1];
}

int get(int id, int l, int r,int u, int v) {
	if (r < u || l > v) return 0;
	if (u <= l && r <= v) return t[id];
	int mid = (l + r) / 2;
	int t1 = get(id * 2, l, mid, u, v);
	int t2 = get(id * 2 + 1, mid + 1, r, u, v);
	return t1 + t2;
}

void update(int id, int l, int r, int p) {
	if (p < l || p > r) return;
	if (l == r) return t[id] = a[p], void();
	int mid = (l + r) / 2;
	update(id * 2, l, mid, p);
	update(id * 2 + 1, mid + 1, r, p);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p, v;
	cin >> n >> p >> v;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[p] = v;
	build(1, 1, n);
	update(1, 1, n, p);
	return 0;
}
