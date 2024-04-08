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
int n, m, x, y, par[N], color[N];
vector<int> v[N];
bool visited[N];

void inp() {
    cin >> n >> m >> x >> y;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }
}

void dfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        for (auto it : v[c]) {
            if (!visited[it]) {
                q.push(it);
                visited[it] = true;
                par[it] = c;
            }
        }
    }
}

void pathh(int x, int y) {
    memset(visited, false, sizeof(visited));
    memset(par, 0, sizeof(par));
    dfs(x);
    if (!visited[y]) {
        cout << "-1";
    }
    else {
        vi path;
        while (y != x) {
            path.pb(y);
            y = par[y];
        }
        path.pb(x);
        reverse(path.begin(), path.end());
        for (auto it : path) {
            cout << it << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    pathh(x, y);
    return 0;
}
