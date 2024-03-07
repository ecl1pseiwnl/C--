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

int n, m, color[4005], parent[4005];
vi v[4005], temp;
set<int> s;

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
	}
	memset(color, 0, sizeof(color));
}

bool dfs(int u) {
	temp.pb(u);
	color[u] = 1;
	for (auto it : v[u]) {
		if (color[it] == 0) {
		
			if (dfs(it)) return true;
		}
		else if (color[it] == 1) {
			return true;
		}
	}
	color[u] = 2;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	int maxv = 0;
	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
			if (dfs(i)) {
				int check = temp.size();
				temp.clear();
				if (maxv < check) {
					maxv = check;
				}
			}
		}
	}
	cout << maxv;
	return 0;
}