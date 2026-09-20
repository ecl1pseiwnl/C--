#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define ms(a,n) memset(a, n,sizeof(a))
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

const int N = 1e5+7;
int n,m;
vector<int> v[N], rv[N];
bool visited[N];
stack<int> st;

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        rv[y].pb(x);
    }
    ms(visited,false);
}

void dfs1(int u) {
    visited[u] = true;
    for (int it : v[u]) {
        if (!visited[it]) {
            dfs1(it);
        }
    }
    st.push(u);
}

void dfs2(int u) {
    visited[u] = true;
    for (int it : rv[u]) {
        if (!visited[it]) {
            dfs2(it);
        }
    }
}

void SCC() {
    ms(visited,false);
    for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs1(i);
		}
	}
	ms(visited,false);
	int cnt = 0;
	while(!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            dfs2(u);
            cnt++;
        }
	}
	cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    inp();
    SCC();
    return 0;
}
