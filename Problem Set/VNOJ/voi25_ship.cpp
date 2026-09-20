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

const int N = 2e5+7,lg = 20;
int n,q,par[N][lg],h[N],r[N],l[N];
ll maxv[N][lg],w[N],dp[N];
vi v[N];

void dfs(int u, int p) {
    for (auto it : v[u]) {
        if (it == p) continue;
        h[it] = h[u] + 1;
        par[it][0] = u;
        maxv[it][0] = w[it];
        FOR(i,1,lg-1) {
            par[it][i] = par[par[it][i-1]][i-1];
            maxv[it][i] = max(maxv[it][i-1],maxv[par[it][i-1]][i-1]);
        }
        dfs(it,u);
    }
}

ll lca(int x, int y) {
    ll mx = -LLINF;
    if (h[x] < h[y]) swap(x,y);
    int k = (h[y]-h[x]);
    ll cur = w[x];
    REP(i,lg) {
        if ((k>>i)&1) {
            cur = max(cur,maxv[x][i]);
            x = par[x][i];
        }
    }
    mx = max(mx,cur);
    if (x == y) return mx;
    FORD(i,lg-1,0) {
        if (par[x][i] != par[y][i]) {
            mx = max({maxv[x][i],maxv[y][i],mx});
            x = par[x][i];
            y = par[y][i];
        }
    }
    return max(maxv[x][0],mx);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("SHIP.INP","r",stdin);
    freopen("SHIP.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) {
        cin >> w[i];
    }
    FOR(i,2,n) {
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    cin >> q;
    FOR(i,1,q) {
        cin >> l[i] >> r[i];
    }
    ms(dp,-LLINF);
    maxv[1][0] = w[1];
    dp[1] = 0;
    dfs(1,0);
    ll ans = -LLINF;
    FOR(i,1,q) {
        if (dp[l[i]] == -LLINF) continue;
        dp[r[i]] = max(dp[r[i]],dp[l[i]] + lca(l[i],r[i]));
        ans = max(ans,dp[r[i]]);
    }
    cout << ans;
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}

