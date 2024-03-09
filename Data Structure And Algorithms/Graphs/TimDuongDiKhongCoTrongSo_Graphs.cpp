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

int n, m, s, t, parent[1001];
vi v[1001];
bool visited[1001];

void dfs(int u) {
	visited[u] = true;
	for (auto x : v[u]) {
		if (!visited[x]) {
			parent[x] = u;
			dfs(x);
		}
	}
}

void path(int s, int t) {
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	dfs(s);
	if (!visited[t]) {
		cout << "-1";
	}
	else {
		vi path;
		while (t != s) {
			path.pb(t);
			t = parent[t];

		}
		path.pb(s);
		reverse(path.begin(), path.end());
		for (int x : path) {
			cout << x << " ";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	cin >> s >> t;
	path(s, t);
	return 0;
}