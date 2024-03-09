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

int n, m;
vi v[10005], path;
bool visited[10005];

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

void dfs(int u) {
	visited[u] = true;
	for (auto it : v[u]) {
		if (!visited[it]) {
			dfs(it);
			path.pb(it);
		}
	}
}

void pathh() {
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cout << i << " ";
			dfs(i);
			sort(path.begin(), path.end());
			for (auto it : path) {
				cout << it << " ";
			}
			path.clear();
			cout << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	pathh();
	return 0;
}