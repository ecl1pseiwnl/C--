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

struct canh {
	int x, y, w;
};

const int N = 1005;
int n, m, par[N], sz[N];
vector<canh> v;

void makeset() {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sz[i] = 1;
	}
}

int find(int u) {
	if (u == par[u]) return u;
	return par[u] = find(par[u]);
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (sz[a] < sz[b]) swap(a, b);
	par[b] = a;
	sz[a] + sz[b];
	return true;
}

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		canh e;
		e.x = x; 
		e.y = y;
		e.w = z;
		v.pb(e);
	}
}

bool cmp(canh a, canh b) {
	return a.w < b.w;
}

void kruskal() {
	vector<canh> mst;
	int d = 0;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < m; i++) {
		if (mst.size() == n - 1) break;
		canh e = v[i];
		if (Union(e.x, e.y)) {
			mst.pb(e);
			d += e.w;
		}
	}
	if (mst.size() != n - 1) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << d;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	makeset();
	kruskal();
	return 0;
}