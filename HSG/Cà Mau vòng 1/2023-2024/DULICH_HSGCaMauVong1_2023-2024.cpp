#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

const int N = 1e5 + 7;
int n, m, q, cmp, id, maxv = INT_MIN;
vi v[N], tmp[N];
bool visit[N];

void inp() {
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	memset(visit, false, sizeof(visit));
}

void dfs(int u) {
	visit[u] = true;
	for (auto it : v[u]) {
		if (!visit[it]) {
			tmp[cmp].pb(it);
			dfs(it);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			cmp = i;
			tmp[i].pb(i);
			dfs(i);
		}
		int temp = tmp[i].size();
		if (maxv < temp) {
			maxv = max(maxv, temp);
			id = i;
		}
	}
	cout << maxv << endl;
	while (q--) {
		int x, s = maxv, cnt = 0;
		cin >> x;
		if (x == s) {
			cnt = 0;
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (i == id) continue;
				if (s < x && tmp[i].size() > 0) {
					s += tmp[i].size();
					cnt++;
				}
				else if (s >= x) {
					break;
				}
			}
		}
		cout << cnt << ' ';
	}
	return 0;
}