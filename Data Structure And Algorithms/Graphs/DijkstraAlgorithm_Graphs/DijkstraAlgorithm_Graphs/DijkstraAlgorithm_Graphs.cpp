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
int n, m, st;
vector<pair<int, int>> adj[1001];

void inp() {
	cin >> n >> m >> st;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].pb({ y,z });
		adj[y].pb({ x,z }); //Neu do thi la do thi vo huong
	}
}

void dijkstra(int s) {
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
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	dijkstra(st);
	return 0;
}