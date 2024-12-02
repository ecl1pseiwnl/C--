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

int n, m, s, t, dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
char a[1001][1001];
bool visited[1001][1001];

bool dfs(int i, int j) {
	if (a[i][j] == 'B') {
		return true;
	}
	a[i][j] = 'x';
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 0 && i1 <= n && j1 >= 0 && j1 <= m && a[i1][j1] != 'x') {
			if (dfs(i1, j1)) return true;
		}
	}
	return false;
}

void inp() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'A') {
				s = i; t = j;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	if (dfs(s, t)) {
		cout << "1";
	}
	else cout << "0";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	return 0;
}