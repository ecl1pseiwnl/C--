#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
ll lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
const int MOD = 1e9+7;
const int32_t INF32 = 0x3f3f3f3f;
const int64_t INF64 = 0x3f3f3f3f3f3f3f3f;

const int N = 1000;
int n,m,ans,d[N], u[N], v[N];

void dfs(int i) {
    if (i > n) {
        vector<vi> visit(7,vector<int> (7,0));
        int cur = 0;
        for (int i = 1; i<=m; i++) {
            int a = d[u[i]], b = d[v[i]];
            if(!visit[a][b]) {
                cur++;
                visit[a][b] = visit[b][a] = true;
            }
        }
        ans = max(ans,cur);
        return;
    }
    for (int j = 1; j <= 6; j++) {
        d[i] = j;
        dfs(i+1);
        d[i] = 0;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    if (n <= 6) return cout << m, 0;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}
