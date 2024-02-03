#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mp;
#define endl cout << "\n";
#define mp make_pair
#define pb push_back

int n, m, ans = 0;
vi v[1001];
bool visited[1001];

void dfs(int u) { //Function DFS co ban
	visited[u] = true;
	for (int x : v[u]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
}

void checkLienThong() { // Check lien thong bang cach DFS/BFS tu 1 den n. Neu visited[i] chua duoc tham thi ans++
	int ans = 0;		// va ta se tim duoc 1 thanh phan lien thong
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			++ans;
			dfs(i); //bfs(i);
		}
	}
	cout << ans;
	endl
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	checkLienThong();
	return 0;
}