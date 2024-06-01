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

int n, m, b, e, check = 0, parent[1005];
vi v[1005];
bool visited[1005];

void inp() {
    cin >> n >> m >> b >> e;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }
}

void dfs(int u) {
    if (u == e) {
        check = 1;
        return;
    }
    visited[u] = true;
    for (auto it : v[u]) {
        if (!visited[it]) {
            parent[it] = u;
            dfs(it);
        }
    }
}

void path(int n) {
    vi pathh;
    while (n != b) {
        pathh.pb(n);
        auto x = parent[n];
        n = x;
    }
    if (n == b) pathh.pb(n);
    reverse(pathh.begin(), pathh.end());
    for (auto it : pathh) {
        cout << it << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inp();
    dfs(b);
    if (check == 1) {
        path(e);
    }
    else if (check == 0) {
        cout << "-1";
    }
    return 0;
}