#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

int n, m, cnt = 0, num[1001], low[1001];
vi v[1001];
vector<pi> bridge;
bool visited[1001];

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int u, int par) {
	visited[u] = true;
	low[u] = num[u] = ++cnt;
	for (auto it : v[u]) {
		if (it == par) continue;
		if (!visited[it]) {
			dfs(it, u);
			low[u] = min(low[u], low[it]);
			if (num[u] < low[it]) {
				bridge.pb({ u,it });
			}
		}
		else {
			low[u] = min(low[u], num[it]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, -1);
		}
	}
	for (auto it : bridge) {
		res++;
		cout << it.first << " " << it.second << endl;
	}
	cout << res;
	return 0;
}