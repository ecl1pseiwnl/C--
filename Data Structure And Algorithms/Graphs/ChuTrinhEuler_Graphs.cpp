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

int n, m, degree[1005];
set<int> adj[1005];

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		//Vo huong
		adj[x].insert(y);
		adj[y].insert(x);
		degree[x]++;
		degree[y]++;
	}
}

void EulerCycle(int v) {
	stack<int> st;
	vi euler;
	st.push(v);
	while (!st.empty()) {
		auto x = st.top();
		if (adj[x].size() != 0) {
			auto y = *adj[x].begin();
			st.push(y);
			adj[x].erase(y);
			adj[y].erase(x);
		}
		else {
			st.pop();
			euler.pb(x);
		}
	}
	reverse(euler.begin(), euler.end());
	for (auto it : euler) cout << it << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	EulerCycle(1);
	return 0;
}