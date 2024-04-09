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
int n, m, u;
vi v[N];
bool used[N];

void inp() {
    cin >> n >> m >> u;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    memset(used, false, sizeof(used));
}

void dfs(int u) {
    used[u] = true;
    for (auto it : v[u]) {
        if (!used[it]) {
            cout << u << "->" << it << endl;
            dfs(it);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    dfs(u);
    return 0;
}
