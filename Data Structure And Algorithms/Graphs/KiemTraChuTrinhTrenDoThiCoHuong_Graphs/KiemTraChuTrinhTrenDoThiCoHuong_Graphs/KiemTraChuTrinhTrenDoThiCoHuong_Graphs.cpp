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

int n, m, color[1001], parent[1001], deg[1001];
vi adj[1001];
// 0: chua tham; 1: dang tham; 2: da tham
//DFS:
bool dfs(int u) {
	color[u] = 1;
	for (auto x : adj[u]) {
		if (color[x] == 0) {
			parent[x] = u;
			if (dfs(x)) return true;
		}
		else if (color[x] == 1) return true;
	}
	color[u] = 2;
	return false;
}

/*BFS:
bool bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		++cnt;
		for (auto x : adj[c]) {
			deg[x]--;
			if (deg[x] == 0) {
				q.push(x);
			}
		}
	}
	return cnt == n;
}
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		//deg[y]++; Neu su dung bfs (kahn)
	}
	memset(color, 0, sizeof(color));
	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
			if (dfs(i)) { // if(bfs()) 
				cout << "1";
				return 0;
			}
		}
	}
	cout << "0";
	return 0;
}
