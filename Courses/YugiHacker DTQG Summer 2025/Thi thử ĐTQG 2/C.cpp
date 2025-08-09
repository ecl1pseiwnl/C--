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
#define name "cpath"
ll __lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
constexpr int MOD = 1e9+7;
constexpr int IINF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5+7, lg = 21;
int n,q,c[N],pos[N],high[N],node[2*N],dp[2*N][lg+1],cnt;
vi v[N];

void dfs(int u, int p) {
    node[++cnt] = u;
    pos[u] = cnt;
    for (auto it : v[u]) {
        if (it == p) continue;
        high[it] = high[u] + 1;
        dfs(it,u);
        node[++cnt] = u;
    }
}

int cal(int x, int y) {
    return (high[x] < high[y] ? x : y);
}

int lca(int x, int y) {
    int nx = pos[x], ny = pos[y];
    if (nx > ny) swap(nx,ny);
    int k = 31 - __builtin_clz(ny-nx+1);
    return cal(dp[nx][k],dp[ny-(1<<k)+1][k]);
}

ll dist (int x, int y) {
    return 1ll * high[x] + high[y] - 2*high[lca(x,y)];
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> q;
    FOR(i,1,n) {
        cin >> c[i];
    }
    FOR(i,2,n) {
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    FOR(i,1,cnt) {
        dp[i][0] = node[i];
    }
    FOR(j,1,lg) {
        for (int i = 1; i+(1<<j)-1 <= cnt; i++) {
            dp[i][j] = cal(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
    while(q--) {
        int x,y,k;
        cin >> x >> y >> k;
        int root = lca(x,y);
        vi path;
        int nx = x;
        while(nx != root) {
            path.pb(c[nx]);
            nx = (pos[nx] > pos[root] ? node[pos[nx]-1] : -1);
        }
        path.pb(c[root]);
        nx = y;
        while(nx != root) {
            path.pb(c[nx]);
            nx = (pos[nx] > pos[root] ? node[pos[nx]-1] : -1);
        }
        cout << (binary_search(all(path),k) ? 1 : 0);
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
