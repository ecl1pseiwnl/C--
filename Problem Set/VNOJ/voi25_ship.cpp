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

struct dt{
    int l,r;
};
const int N = 2e5+7,lg = 24;
int n,q,par[N][lg],maxv[N][lg],h[N];
ll w[N],dp[N];
vi v[N];
dt d[N];

void dfs(int u, int p) {
    par[u][0] = p;
    h[u] = h[p] + 1;
    maxv[u][0] = w[u];
    FOR(i,1,lg-1) {
        par[u][i] = par[par[u][i-1]][i-1];
        maxv[u][i] = max(maxv[u][i-1],maxv[par[u][i-1]][i-1]);
    }
    for (auto it : v[u]) {
        if (it == p) continue;
        dfs(it,u);
    }
}

int lca(int x, int y) {
    int mx = 0;
    if (h[x] < h[y]) swap(x,y);
    FORD(i,lg-1,0) {
        if (h[par[x][i]] >= h[y]) {
            mx = max(maxv[x][i],mx);
            x = par[x][i];
        }
    }
    if (x == y) return mx;
    FORD(i,lg-1,0) {
        if (par[x][i] != par[y][i]) {
            mx = max({maxv[x][i],maxv[y][i],mx});
            x = par[x][i];
            y = par[y][i];
        }
    }
    mx = max({maxv[x][0],maxv[y][0],mx});
    return mx;
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
    ms(maxv,-IINF);
    dfs(1,0);
    h[0] = -1;
    cin >> q;
    FOR(_,1,q) {
        int l,r;
        cin >> l >> r;
        d[_] = {l,r};
    }
    ll ans = 0;
    FOR(i,1,q) {
        if (dp[d[i].l] == 0 && d[i].l != 1) continue;
        /// Neu dinh hien tai co W = 0 va dinh do khong phai dinh 1 thi bo qua
        /// Ta se tinh duoc khi co Li = 1 thi moi K truy van tiep theo se tinh duoc
        /// thong qua truy van phia truoc
        dp[d[i].r] = max(dp[d[i].r],dp[d[i].l] + lca(d[i].l,d[i].r));
        ans = max(ans,dp[d[i].r]);
    }
    cout << ans;
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
