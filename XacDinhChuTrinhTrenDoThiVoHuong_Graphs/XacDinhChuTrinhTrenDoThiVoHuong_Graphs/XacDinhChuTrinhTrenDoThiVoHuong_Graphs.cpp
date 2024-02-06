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
vi v[1001];
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

bool dfs(int u, int par) {
	visited[u] = true;
	for (auto x : v[u]) {
		if (!visited[x]) {
			if (dfs(x,u)) return true;
		}
		else if (x != par) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	for (int i = 1; i <= n; i++) { //Check neu co nhieu thanh phan lien thong de print ra ket qua dung
		if (!visited[i]) {
			if (dfs(i, 0)) {
				cout << "1";
				return 0;
			}
		}
	}
	cout << "0";
	return 0;
}