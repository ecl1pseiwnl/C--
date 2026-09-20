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

//O(2*V+E)
int n, m; // cnt neu de yeu cau dem so thanh phan lien thong manh
vi v[1001], rv[1001];
bool visited[1001];
stack<int> st;

void dfs1(int u) {
	visited[u] = true;
	for (auto x : v[u]) {
		if (!visited[x]) {
			dfs1(x);
		}
	}
	st.push(u);
}

void dfs2(int v) {
	visited[v] = true;
	cout << v << " ";
	for (auto x : rv[v]) {
		if (!visited[x]) {
			dfs2(x);
		}
	}
}

void SCC() {
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs1(i);
		}
	}
	memset(visited, false, sizeof(visited));
	//int cnt = 0;
	//vi a;  (Neu de yeu cau in ra cac thanh phan ko lien thong voi nhau)
	while (!st.empty()) {
		int u = st.top();
		st.pop();
		if (!visited[u]) {
			dfs2(u);
			//a.pb(u)
			cout << endl; //cnt++; neu de yeu cau dem SCC
		}
	}
	/*if (cnt == 1) cout <<"1";
	else {
		cout << "0";
		cout << endl << a[1] << " " << a[0];
	}
	*/
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		rv[y].pb(x);
	}
	SCC();
	return 0;
}