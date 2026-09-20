#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 10000000007
#define endl "\n";
#define mp make_pair
#define pb push_back

const int N = 1005;
int n, m, visited[N], par[N];
vector<int> v[N], rv[N];
stack<int> st;

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        rv[y].pb(x);
    }
}

void dfs(int u) {
    visited[u] = true;
    for (auto it : v[u]) {
        if (!visited[it]) {
            dfs(it);
        }
    }
    st.push(u);
}

void dfs2(int u) {
    visited[u] = true;
    for (auto it : rv[u]) {
        if (!visited[it]) {
            dfs2(it);
        }
    }
}

void SCC() {
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            dfs2(u);
            cnt++;
        }
    }
    if (cnt == 1) {
        cout << "1";
    }
    else cout << "0";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    SCC();
    return 0;
}
