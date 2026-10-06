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

const int N = 1e5 + 7;
int n, q, par[N];
vi v[N];
bool visited[N];

void inp() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
}

void dfs(int u) {
    visited[u] = true;
    for (auto it : v[u]) {
        if (!visited[it]) {
            par[it] = u;
            dfs(it);
        }
    }
}

void pathh(int x, int y) {
    memset(visited, false, sizeof(visited));
    memset(par, 0, sizeof(par));
    dfs(x);
    if (!visited[y]) {
        cout << "0" << endl;
    }
    else {
        ll cnt = 0;
        while (y != x) {
            cnt += y;
            y = par[y];
        }
        cnt += y;
        cout << cnt << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    while (q--) {
        int x, y;
        cin >> x >> y;
        pathh(x, y);
    }
    return 0;
}