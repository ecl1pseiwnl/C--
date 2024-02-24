#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define endl "\n";
#define mp make_pair
#define pb push_back

struct edg {
	int x, y, z;
};

int n, m, par[1001], siz[1001];
vector<edg> adj;

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edg e;
		e.x = x;
		e.y = y;
		e.z = z;
		adj.pb(e);
	}
}

void makeset() {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		siz[i] = 1;
	}
}

int find(int v) {
	if (v == par[v]) return v;
	return par[v] = find(par[v]);
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (siz[a] < siz[b]) swap(a, b);
	par[b] = a;
	siz[a] + siz[b];
	return true;
}

bool cmp(edg a, edg b) {
	return a.z < b.z;
}

void kruskal() {
	vector<edg> mst; // tao cay khung cuc tieu (MST)
	int d = 0;
	sort(adj.begin(), adj.end(), cmp);
	for (int i = 0; i < m; i++) {
		if (mst.size() == n - 1) break;
		edg e = adj[i];
		if (Union(e.x, e.y)) {
			mst.pb(e);
			d += e.z;
		}
	}
	if (mst.size() != n - 1) {
		cout << "This graph is not MST";
	}
	else {
		cout << d << endl;
		for (auto x : mst) {
			cout << x.x << " " << x.y << " " << x.z << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	makeset();
	kruskal();
}