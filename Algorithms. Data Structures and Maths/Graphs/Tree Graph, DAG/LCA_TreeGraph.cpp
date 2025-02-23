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
ll __lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
const double PI = 3.141592653589793238463;
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
constexpr int MOD = 1e9+7;
constexpr int32_t IINF = 0x3f3f3f3f;
constexpr int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 3e5+7;
int n;
vi v[N];
int par[N][lg+1], high[N];

void inp() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
}

void dfs(int u) {
    for (auto it : v[u]) {
        if (it != par[u][0]) {
            par[it][0] = u;
            high[it] = high[u] + 1;
            dfs(it);
        }
    }
}

int lca (int u, int v) {
    if (high[v] > high[u]) return lca(v,u);
    // binary lift do sau cua 2 diem
    int k = __lg(high[u] - high[y]);
    for (int i = k; i >= 0; i--) {
        if (high[par[u][i]] >= high[v]) {
            u = par[u][i];
        }
    }
    if (u == v) return u;
    // cung di len toi to tien gan nhat
    int t = __lg(high[u]);
    for (int i = t; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
	}
	return par[u][0];
}

int dist(int u, int y) {
    return 1ll* d[u] + d[y] - 2 * d[lca(u,y)];
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(name ".inp", "r")) {
        freopen(name ".inp","r",stdin);
        freopen(name ".out","w",stdout);
    }
    inp();
    dfs(1);
    for (int j = 1; j <= lg; j++) {
        for (int i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    high[0] = -1;
    int x,y;
    cin >> x >> y;
    cout << lca(x,y);
    cerr << "Time elapsed: " << TIME << "s. \n";
    return 0;
}
