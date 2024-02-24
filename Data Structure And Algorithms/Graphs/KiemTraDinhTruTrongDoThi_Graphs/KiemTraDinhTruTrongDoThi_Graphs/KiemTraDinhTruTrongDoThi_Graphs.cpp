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

void dfs(int u) {
	visited[u] = true;
	for (auto x : adj[u]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
}

void DinhTru() {
	int ans = 0;
	int tplt = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			tplt++;
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				cnt++;
				dfs(j);
			}
		}
		if (cnt > tplt) {
			cout << i << " ";
			ans++;
		}
	}
	cout << "\n" << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	DinhTru();
	return 0;
}