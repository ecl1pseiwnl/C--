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

int n, m, st, en;
int parent[1001];
vi adj[1001];
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
}

/* BFS:
bool bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()) {
		int c = q.front();
		q.pop();
		for (auto x : adj[c]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
				parent[x] = c;
			} else if (x != parent[v]) {
				st = v; en = x;
				return true;
			}
		}
	}
	return false;
}
*/

bool dfs(int u) { //DFS
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) {
			parent[v] = u;
			if (dfs(v)) return true;
		}
		else if (v != parent[u]) {
			st = v; en = u;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
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
