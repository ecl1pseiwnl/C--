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
int n, m, par[N];
vi v[N];
bool visit[N];

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    memset(visit, false, sizeof(visit));
}

bool dfs(int u) {
    visit[u] = true;
    for (auto it : v[u]) {
        if (!visit[it]) {
            par[it] = u;
            if (dfs(it)) {
                return true;
            }
        }
        else if (it != par[u]) {
            return true;
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    if (m != n - 1) {
        cout << "0";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            if (dfs(i)) {
                cout << "0";
                return 0;
            }
        }
    }
    cout << "1";
    return 0;
}
