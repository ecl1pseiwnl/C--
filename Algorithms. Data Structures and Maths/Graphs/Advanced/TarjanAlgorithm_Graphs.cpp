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
bool visited[1001];
stack<int> st;

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
	}
}

void dfs(int u) {
	num[u] = low[u] = ++cnt;
	st.push(u);
	for (int it : v[u]) {
		if (num[it]) {
                low[u] = min(low[u], num[it]);
		}
		else {
                dfs(it);
                low[u] = min(low[u], low[it]);
		}
	}
	if (low[u] == num[u]) {
		++scc;
        int k = 0;
        while (k != u) {
            cout << st.pop() << " ";
            st.pop();
        }
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
