#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mp;
#define endl cout << "\n";
#define mp make_pair
#define pb push_back

int n, m, a[1001][1001], dx[4] = { -1,0,0,1 }, dy[4] = { 0, -1, 1 , 0 };
bool visited[1001][1001];

void dfs(int i, int j) {
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 0 && !visited[i1][j1]) {
			dfs(i1, j1);
		}
	}
}

void inp() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 0 && !visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	return 0;
}