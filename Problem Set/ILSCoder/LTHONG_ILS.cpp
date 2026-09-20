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

int n, m, cnt = 0, ans = 0;
bool visited[1001];
vi v[1001], lt[1001];

void dfs(int u) {
	lt[ans].pb(u);
	visited[u] = true;
	for (auto x : v[u]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
}

void dem() {
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			ans++;
			dfs(i);
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dem();
	for (int i = 1; i <= ans; i++) {
		sort(lt[i].begin(), lt[i].end());
	}
	for (int i = 1; i <= ans; i++) {
		for (auto x : lt[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}