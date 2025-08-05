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

const int N = 1e5+7, lg = 20;
int n,q,par[N][lg+1],root,dp[N];
vi v[N];

void dfs(int u, int p) {
    par[u][0] = p;
    dp[u] = dp[p] + 1;
    FOR(i,1,lg-1) {
        par[u][i] = par[par[u][i-1]][i-1];
    }
    for (auto it : v[u]) {
        if (it == p) continue;
        dfs(it,u);
    }
}

int lca(int x, int y) {
    if (dp[x] < dp[y]) swap(x,y);
    FORD(i,lg-1,0) {
        if (dp[par[x][i]] >= dp[y]) {
            x = par[x][i];
        }
    }
    if (x == y) return x;
    FORD(i,lg-1,0) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    while(cin >> n) {
        if (n == 0) break;
        FOR(i,1,n) if (v[i].size()) v[i].clear();
        ms(dp,0);
        ms(par,0);
        FOR(i,2,n) {
            int x,y;
            cin >> x >> y;
            v[x].pb(y);
            v[y].pb(x);
        }
        dfs(1,0);
        dp[0] = -1;
        root = 1;
        cin >> q;
        while(q--) {
            char c;
            cin >> c;
            if (c == '!') {
                int x;
                cin >> x;
                root = x;
            } else if (c == '?') {
                int x,y;
                cin >> x >> y;
                // To tien chung cua X va Y co dinh goc la Z
                // Thi phai kiem tra to tien co nam trong doan X->Z, Y->Z va X->Y
                int ntx = lca(root,x), nty = lca(root,y);
                int ans = (dp[ntx] >= dp[nty] ? ntx : nty);
                int xty = lca(x,y);
                ans = (dp[ans] >= dp[xty] ? ans : xty);
                cout << ans << endl;
            }
        }
    }

    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
