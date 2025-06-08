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

const int N = 2*1e5+7;
int n,m, id[N], low[N], cnt;
vector<int> v[N], ans;

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x,y;
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
            } else {
                dfs(it, u);
                low[u] = min(low[it],low[u]);
                if (low[it] >= id[u]) {
                    node++;
                }
            }
        }
    }
    if (node >= 2) ans.pb(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    inp();
    for (int i = 1;i <= n; i++) {
        if (!id[i]) {
            dfs(i,0);
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans) cout << it << " ";
    return 0;
}
