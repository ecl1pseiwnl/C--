#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

const int N = 500000;
int n, m, cmp;
bool visited[N];
vi adj[N], used[N], ds;

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u) {
    visited[u] = true;
    for (auto it : adj[u]) {
        if (!visited[it]) {
            used[cmp].pb(it);
            dfs(it);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inp();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cmp = i;
            used[cmp].pb(cmp);
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        int ans = INT_MAX;
        for (auto it : used[i]) {
            ans = min(it, ans);
        }
        if (ans != INT_MAX) {
            ds.pb(ans);
        }
    }
    cout << ds.size() - 1 << endl;
    int i = 1;
    while (i < ds.size()) {
        cout << ds[i - 1] << " " << ds[i] << endl;
        i++;
    }
    return 0;
}