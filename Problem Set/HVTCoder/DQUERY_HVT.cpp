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

const int INF = 1e9;
int n, k;
vector<pi> adj[80001];

void inp() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].pb({ y,z });
		adj[y].pb({ x,z });
	}	
}

void dijkstra(int s,int t) {
	vector<ll> d(n + 1, INF);
	d[s] = 0;
	priority_queue <pi, vector<pi>, greater<pi>> Q;
	Q.push({ 0,s });
	while (!Q.empty()) {
		pi top = Q.top();
		Q.pop();
		int v = top.first, u = top.second;
		if (v > d[u]) {
			continue;
		}
		for (auto it : adj[u]) {
			int x = it.first, y = it.second;
			if (d[x] > d[u] + y) {
				d[x] = d[u] + y;
				Q.push({ d[x],x });
			}
		}
	}
	cout << d[t] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	cin >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		dijkstra(x,y);
	}
	return 0;
}