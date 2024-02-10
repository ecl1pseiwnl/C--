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
vi v[1001], topo;
bool visited[1001];

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		v[x].pb(y);
	}
	memset(visited, false, sizeof(visited));

}

void dfs(int u) {
	visited[u] = true;
	for (auto x : v[u]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
	topo.pb(u);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	reverse(topo.begin(), topo.end());
	for (auto x : topo) {
		cout << x << " ";
	}
	return 0;
}