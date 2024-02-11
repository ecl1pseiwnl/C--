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

int n, m, q;
vector<pi> adj[1001];
const int INF = 1e9;

void inp() {
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].pb({ y,z });
		adj[y].pb({ x,z });
	}
}

void dijkstra(int s, int e) {
	vector<ll> d(n + 1, INF);
	d[s] = 0;
	priority_queue<pi, vector<pi>, greater<pi>> Q;
	Q.push({ 0,s });
	while (!Q.empty()) {
		pi top = Q.top();
		Q.pop();
		int u = top.second, v = top.first;
		if (v > d[u]) {
			continue;
		}
		for (auto it : adj[u]) {
			int s1 = it.first, s2 = it.second;
			if (d[s1] > d[u] + s2) {
				d[s1] = d[u] + s2;
				Q.push({ d[s1],s1 });
			}
		}
	}
	if (d[e] != INF) {
		cout << d[e] << endl;
	}
	else {
		cout << "-1" << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	while (q--) {
		int x, y;
		cin >> x >> y;
		dijkstra(x, y);
	}
	return 0;
}