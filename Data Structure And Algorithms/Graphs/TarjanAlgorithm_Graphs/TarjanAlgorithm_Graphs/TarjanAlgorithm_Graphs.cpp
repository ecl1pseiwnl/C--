#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

int n, m, cnt = 0, scc = 0, low[1001], num[1001];
vi v[1001];
bool visited[1001], in_stack[1001];
stack<int> st;

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
	}
	memset(visited, false, sizeof(visited));
	memset(in_stack, false, sizeof(visited));
}

void dfs(int u) {
	visited[u] = true; in_stack[u] = true;
	num[u] = low[u] = ++cnt;
	st.push(u);
	for (int it : v[u]) {
		if (!visited[it]) {
			dfs(it);
			low[u] = min(low[u], low[it]);
		}
		else {
			low[u] = min(low[u], num[it]);
		}
	}
	if (low[u] == num[u]) {
		++scc;
		while (st.top() != u) {
			//cout << st.top() << " ";
			in_stack[st.top()] = false;
			st.pop();
		}
		//cout << st.top() << " ";
		//in_stack[st.top()] = false;
		//st.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	cout << scc;
	return 0;
}