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

const ll INF = 1e9;
int n, m, st, en;
vector<pair<int, int>> adj[1001];

void inp() {
	cin >> n >> m >> st >> en;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].pb({ y,z });
		adj[y].pb({ x,z });
	}
}

int pre[1001]; //su dung de tim duong di ngan nhat

void dijkstra(int s, int t) {
	// tao mang luu khoang cach
	vector<ll> d(n + 1, INF);
	d[s] = 0;
	priority_queue < pi, vector<pi>, greater<pi>> Q; //khoang cach, dinh
	Q.push({ 0,s });
	while (!Q.empty()) {
		pi top = Q.top();
		Q.pop();
		int u = top.second, len = top.first;
		if (len > d[u]) {
			continue;
		}
		// Relaxation: d[v] = d[u] + w
		for (auto it : adj[u]) {
			int v = it.first, w = it.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				Q.push({ d[v],v });
				pre[v] = u;
			}
		}
	}
	cout << d[t] << endl;
	vi path;
	while (1) {
		path.pb(t);
		if (t == s) break;
		t = pre[t];
	}
	reverse(path.begin(), path.end());
	for (auto x : path) {
		cout << x << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	dijkstra(st,en);
	return 0;
}
