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

struct canh {
	int x, y, z;
};

int n, m, d[1001], parent[1001];
vector<pi> adj[1001];
bool used[1001];

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].pb({ y,z });
		adj[y].pb({ x,z });
	}
	memset(used, false, sizeof(used));
	for (int i = 1; i <= n; i++) {
		d[i] = INT_MAX;
	}
}

void PRIM(int u) {
	priority_queue<pi, vector<pi>, greater<pi>> Q;
	vector<canh> MST;
	int res = 0;
	Q.push({ 0,u });
	while (!Q.empty()) {
		pi top = Q.top();
		Q.pop();
		int dinh = top.second, trongso = top.first;
		if (used[dinh]) continue;
		res += trongso;
		used[dinh] = true;
		if (u != dinh) {
			MST.pb({ dinh,parent[dinh],trongso });
		}
		for (auto it : adj[dinh]) {
			int y = it.first, w = it.second;
			if (!used[y] && w < d[y]) {
				Q.push({ w,y });
				d[y] = w;
				parent[y] = dinh;
			}
		}
	}
	cout << res << endl;
	for (canh it : MST) {
		cout << it.x << " " << it.y << " " << it.z << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	PRIM(1);
	return 0;
}