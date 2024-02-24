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

int n, m, color[1001];
vi adj[1001];

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	memset(color, -1, sizeof(color));
}

bool bfs(int u) {
	queue<int> q;
	q.push(u);
	color[u] = 0; // red
	while(!q.empty()) {
		int c = q.front(); q.pop();
		for (auto x : adj[u]) {
			if (color[x] == -1) {
				color[x] = 1 - color[c];
				q.push(x);
			}
			else if (color[x] == color[c]) {
				return false;
			}
		}
	}
	return true;
}

bool dfs(int u, int parent) {
	color[u] = 1 - color[parent];
	for (auto x : adj[u]) {
		if (color[x] == -1) {
			if (!dfs(x, u)) return false;
		}
		else if (color[x] == color[u]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	bool check = 1;
	//color[0] = 1 neu su dung dfs
	for (int i = 1; i <= n; i++) {
		if (color[i] == -1) {
			if (!bfs(i)) { //dfs(i,0)
				check = false;
				break;
			}
		}
	}
	if (check) cout << "1";
	else cout << "0";
	return 0;
}