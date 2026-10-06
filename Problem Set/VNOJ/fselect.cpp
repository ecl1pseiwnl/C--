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
#define BIT(x,i) (((x) >> (i)) & 1)
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
template <class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        }
        return false;
    }
template <class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        }
        return false;
    }
constexpr int MOD = 1e9+7;
constexpr int IINF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 2e5+7,lg = 24;
int n,k,dp[N][lg], high[N], root;
vi v[N];
vector<pi> depth[N];
pi order[N];

void dfs(int u, int par) {
    high[u] = high[par] + 1;
    dp[u][0] = par;
    FOR(i,1,lg-1) {
        dp[u][i] = dp[dp[u][i-1]][i-1];
    }
    for (auto it : v[u]) {
        if (it == par) continue;
        dfs(it,u);

    }
}

int lca(int x, int y) {
    if (high[x] < high[y]) swap(x,y);
    FORD(i,lg-1,0) {
        if (high[dp[x][i]] >= high[y]) {
            x = dp[x][i];
        }
    }
    if (x == y) return x;
    FORD(i,lg-1,0) {
        if (dp[x][i] != dp[y][i]) {
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return dp[x][0];
}

ll calc(int x, int y) {
    return 1ll* high[x] + high[y] - 2*high[lca(x,y)];
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    FOR(i,1,n) {
        int x,y;
        cin >> x >> y;
        if (y == 0) {
            root = i;
        } else {
            v[i].pb(y);
            v[y].pb(i);
        }
        order[i] = {x,i};
    }
    dfs(root,0);
    high[0] = -1;
    FOR(i,1,n) {
        depth[order[i].fi].pb({high[order[i].se],order[i].se});
    }
    FOR(i,1,k) {
        int x = max_element(all(depth[i])) - depth[i].begin();
        debug(x,y,depth[i][x].se,depth[i][y].se);
        cout << calc(depth[i][x].se,depth[i][y].se) << endl;
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
