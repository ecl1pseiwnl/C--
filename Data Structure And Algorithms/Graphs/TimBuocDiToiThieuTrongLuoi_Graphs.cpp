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

int n, m, s, t, u, v, dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 }, d[1001][1001];
char a[1001][1001];

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	a[i][j] = 'o';
	d[i][j] = 0;
	while (!q.empty()) {
		pair<int, int> top = q.front(); 
		q.pop();
		for (int k = 0; k < 4; k++) {
			int i1 = top.first + dx[k], j1 = top.second + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 'x') {
				d[i1][j1] = d[top.first][top.second] + 1;
				if (a[i1][j1] == 'B') return;
				q.push({ i1,j1 });
				a[i1][j1] = 'o';
			}
		}
	}
}
void inp() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'A') {
				s = i; t = j;
			}
			else if (a[i][j] == 'B') {
				u = i; v = j;
			}
		}
	}
	bfs(s, t);
	if (!d[u][v]) {
		cout << "-1";
	}
	else cout << d[u][v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	return 0;
}
