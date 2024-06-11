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

int n, m;
vi adj[1001], l;
bool visited[1001];

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	memset(visited, false, sizeof(visited));
	visited[1] = true;
}

void dfs(int u) {
	visited[u] = true;
	for (auto x : adj[u]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	dfs(1);
	for (int i = 2; i <= n; i++) {
		if (!visited[i]) {
			l.pb(i);
		}
	}
	if (!l.empty()) {
		for (auto x : l) {
			cout << x << endl;
		}
	}
	else {
		cout << 0;
	}
	return 0;
}