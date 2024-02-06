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

int n, m, x, y, a[1001][1001], dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 }, d[1001][1001], pos[1001];
vi v[1001]; vector<pair<int, int>> b[1001];

/*void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	a[x][y] = 0;
	d[x][y] = 0;
	while (!q.empty()) {
		pi c = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int i1 = c.first + dx[k], j1 = c.second + dy[y];
			if (i1 >= 0 && i1 <= n && j1 >= 0 && j1 <= m && a[i1][j1] != 1) {
				d[i1][j1] = d[c.first][c.second] + 1;
				q.push({ i1,j1 });
				a[i1][j1] = 1;
			}
		}
	}
}*/

void inp() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if ((i == 1 || i == n) && a[i][j] == 0) {
				
			}
		}
	}
	cin >> x >> y;
	
	if (!d[x][y]) {
		cout << "-1";
	}
	else {
		cout << d[x][y] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	return 0;
}