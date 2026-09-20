#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define endl cout << "\n";
#define mp make_pair
#define pb push_back

int n, m, x, y, a[1001][1001], d[1001][1001], dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }, check = 1;
pair<int, int> parent[1001][1001];

void findpath(int i, int j) {
	vector<pair<int,int>> path;
	while (i != x || j != y) {
		path.pb({ i,j });
		auto p = parent[i][j];
		i = p.first;
		j = p.second;
	}
	cout << path.size() << "\n";
	reverse(path.begin(), path.end());
	for (auto it : path) {
		cout << it.first << " " << it.second << "\n";
	}
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({ x, y });
	a[x][y] = 1;
	d[x][y] = 0;
	while (!q.empty()) {
		auto c = q.front();
		int i = c.first, j = c.second;
		q.pop();
		if (i == 1 || i == n || j == 1 || j == m) {
			findpath(i,j);
			check = 0;
			return;
		}
		for (int k = 0; k < 4; k++) {
			int i1 = i + dx[k], j1 = j + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !a[i1][j1]) {
				q.push({ i1,j1 });
				parent[i1][j1] = { i,j };
				a[i1][j1] = 1;
				d[i1][j1] = d[i][j] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> x >> y;
	if (x == 1 || x == n || y == 1 || y == m) {
		cout << "0";
		return 0;
	}
	bfs();
	if (check) {
		cout << "-1";
	}
	return 0;
}