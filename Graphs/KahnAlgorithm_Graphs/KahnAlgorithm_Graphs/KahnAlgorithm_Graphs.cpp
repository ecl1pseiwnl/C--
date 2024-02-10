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

int n, m, in[1001];
vi v[1001], topo;
bool visited[1001];

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		v[x].pb(y);
		in[y]++;
	}
	memset(visited, false, sizeof(visited));
}

void Kahn() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		topo.pb(c);
		for (auto u : v[c]) {
			in[u]--;
			if (in[u] == 0) {
				q.push(u);
			}
		}
	}
	for (auto x : topo) {
		cout << x << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	Kahn();
	return 0;
}