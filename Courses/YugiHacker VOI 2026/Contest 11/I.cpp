#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define Mask(x,i) (((x) >> (i)) & 1)
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define ins insert
#define sz(x) (int)(x.size())
#define fi first
#define se second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define name "TASK"
ll __lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
constexpr int MOD = 1e9+7;
constexpr int IINF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5+7, lg = 22;
struct edge{
    int x,y,w;
};
int n,m,par[N],sz[N],last,dp[lg][N],mi[lg][N],h[N];
ll res;
vector<edge> v;
vector<pi> u[N];

int findset(int u) {
    if (u == par[u]) return u;
    return par[u] = findset(par[u]);
}

bool unite(int x, int y) {
    x = findset(x);
    y = findset(y);
    if (x == y) return 0;
    if (sz[x] < sz[y]) swap(x,y);
    sz[x] += sz[y];
    par[y] = x;
    return 1;
}

bool cmp(edge a, edge b) {
    return a.w > b.w;
}

void dfs(int cur, int p) {
    dp[0][cur] = p;
    FOR(i,1,lg-1) {
        dp[i][cur] = dp[i-1][dp[i-1][cur]];
        mi[i][cur] = min(mi[i-1][cur],mi[i-1][dp[i-1][cur]]);
    }
    for (auto it : u[cur]) {
        if (it.fi == p) continue;
        h[it.fi] = h[cur] + 1;
        mi[0][it.fi] = it.se;
        dfs(it.fi,cur);
    }
}

int lca(int x, int y) {
    int ans = IINF;
    if (h[x] < h[y]) swap(x,y);
    FORD(i,lg-1,0) {
        if (h[x] - (1<<i) >= h[y]) {
            ans = min(ans,mi[i][x]);
            x = dp[i][x];
        }
    }
    if (x == y) return ans;
    FORD(i,lg-1,0) {
        if (dp[i][x] != dp[i][y]) {
            ans = min({mi[i][x],mi[i][y],ans});
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return min({mi[0][x],mi[0][y],ans});
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    FOR(i,1,n) {
        sz[i] = 1;
        par[i] = i;
    }
    REP(i,m) {
        edge e;
        cin >> e.x >> e.y >> e.w;
        v.pb(e);
    }
    sort(all(v),cmp);
    int cnt = 0;
    REP(i,m) {
        edge e = v[i];
        if (cnt == n-1) break;
        if (unite(e.x,e.y)) {
            u[e.x].pb({e.y,e.w});
            u[e.y].pb({e.x,e.w});
            cnt++;
        }
    }
    ms(mi,IINF);
    dfs(1,-1);
    REP(i,m) {
        edge e = v[i];
        int r = lca(e.x,e.y);
        res += max(0,r-e.w);
    }
    cout << res;
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
