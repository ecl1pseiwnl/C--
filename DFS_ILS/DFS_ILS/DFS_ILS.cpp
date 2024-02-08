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

int n, m, s, t, parent[1001];
bool visited[1001];
vi adj[1001];

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	cin >> s >> t;
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));
}

void dfs(int u) {
	visited[u] = true;
	for (auto x : adj[u]) {
		if (!visited[x]) {
			dfs(x);
			parent[x] = u;
		}
	}
}

void path(int s, int t) {
	dfs(s);
	if (!visited[t]) {
		cout << "NO";
	}
	else {
		vi path;
		while (t != s) {
			path.pb(t);
			t = parent[t];
		}
		path.pb(s);
		reverse(path.begin(), path.end());
		for (auto x : path) cout << x << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	path(s, t);
	return 0;
} 