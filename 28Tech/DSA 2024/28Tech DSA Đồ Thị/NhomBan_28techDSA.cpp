#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mii;
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

const int N = 1005;
int n, m, maxv = INT_MIN;
vi v[N], path;
bool visit[N];

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
}

void dfs(int u) {
    visit[u] = true;
    for (auto it : v[u]) {
        if (!visit[it]) {
            dfs(it);
            path.pb(it);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            dfs(i);
            path.pb(i);
            int sz = path.size();
            maxv = max(maxv, sz);
            path.clear();
        }
    }
    cout << maxv;
    return 0;
}
