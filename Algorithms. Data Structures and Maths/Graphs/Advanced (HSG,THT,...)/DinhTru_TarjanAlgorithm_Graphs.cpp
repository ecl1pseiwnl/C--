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

int n, m, cnt = 0;
vi v[1001];
int num[1001], low[1001];
bool visited[1001], ap[1001];

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	memset(visited, false, sizeof(visited));
	memset(visited, false, sizeof(ap));
}

void dfs(int u, int par) {
	visited[u] = true;
	num[u] = low[u] = ++cnt;
	int child = 0;
	for (auto it : v[u]) {
		if (it == par) continue;
		if (!visited[it]) {
			dfs(it,u);
			++child;
			low[u] = min(low[u], low[it]);
			if (par != -1 && num[u] <= low[it]) {
				ap[u] = true;
			}
		}
		else {
			low[u] = min(low[u], num[it]);
		}
	}
	if (par == -1 && child > 1) {
		ap[u] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, -1);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ap[i]) {
			cout << i << " ";
			cnt++;
		}
	}
	cout << endl <<cnt;
	return 0;
}
