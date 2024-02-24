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

int n, m, st, en, parent[1001], color[1001], deg[1001];
vi adj[1001];

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		deg[y]++;
	}
	memset(color, false, sizeof(color));
}

/* BFS:
bool bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
	}
	int cnt = 0;
	while(!q.empty()) {
		int c = q.front();
		q.pop();
		cnt++;
		for (auto x : adj[c]) {
			deg[x]--;
			if(deg[x] == 0) q.push(x);
		}
	}
	return cnt == n;
}
*/

bool dfs(int u) { //DFS
	color[u] = 1;
	for (int v : adj[u]) {
		if (color[v] == 0) {
			parent[v] = u;
			if (dfs(v)) return true;
		}
		else if (color[v] == 1) {
			return true;
		}
	}
	color[u] = 2;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
			if (dfs(i)) {  //BFS thi chi nen su dung cho viec kiem tra co chu trinh hay khong,
				cout << "1\n"; //neu muon in ra chu trinh thi nen su dung DFS
				vi cycle;
				cycle.pb(st);
				while (en != st) {
					cycle.pb(en);
					en = parent[en];
				}
				cycle.pb(st);
				reverse(cycle.begin(), cycle.end());
				for (int v : cycle) {
					cout << v << " ";
				}
				return 0;
			}
		}
	}
	cout << "0\n";
	return 0;
}
