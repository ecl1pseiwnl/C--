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
vi v[1001], rv[1001];
bool visited[1001];
stack<int> st;

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		rv[y].pb(x);
	}
}

void dfs1(int u) {
	visited[u] = true;
	for (auto it : v[u]) {
		if (!visited[it]) {
			dfs1(it);
		}
	}
	st.push(u);
}

void dfs2(int u) {
	visited[u] = true;
	for (auto it : rv[u]) {
		if (!visited[it]) {
			dfs2(it);
		}
	}
}

void SCC() {
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs1(i);
		}
	}
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	while (!st.empty()) {
		int u = st.top();
		st.pop();
		if (!visited[u]) {
			dfs2(u);
			cnt++;
		}
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	SCC();
	return 0;
}