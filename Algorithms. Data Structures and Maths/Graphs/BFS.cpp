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

int n, m;
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

void BFS(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		cout << c << " ";
		for (int x : v[c]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	BFS(1);
}