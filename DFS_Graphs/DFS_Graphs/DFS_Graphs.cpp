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

int n, m, a[1001][1001];
vi v[1001];
bool visited[1001];

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x); //Neu do thi la do thi vo huong
	}
	memset(visited, false, sizeof(visited));
}

void DFS(int u) {
	cout << u << " ";
	visited[u] = true;
	for (int x : v[u]) {
		if (!visited[x]) {
			DFS(x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	DFS(1);
	return 0;
}