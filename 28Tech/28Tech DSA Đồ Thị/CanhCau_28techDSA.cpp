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
int n, m, low[N], id[N], par[N], bridge, cnt;
vector<int> v[N];

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
}

void dfs(int u, int p) {
    id[u] = low[u] = ++cnt;
    int node = (p != 0);
    for (auto it : v[u]) {
        if (it != p) {
            if (id[it]) {
                low[u] = min(low[u], id[it]);
            }
            else {
                dfs(it, u);
                low[u] = min(low[u], low[it]);
                if (low[it] == id[it]) {
                    bridge++;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    for (int i = 1; i <= n; i++) {
        if (!id[i]) {
            dfs(i, 0);
        }
    }
    cout << bridge;
    return 0;
}
