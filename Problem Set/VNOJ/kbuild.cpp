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
constexpr int MOD = 1e9+7;
constexpr int IINF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 2e5+7;
int n,m,low[N],num[N],cnt,bridge;
struct edge {
    int x,y;
    bool used;
    int cmpr(int k) {return x^y^k;}
} E[N<<1];
vi v[N];

void dfs(int u) {
    low[u] = num[u] = ++cnt;
    for (auto k : v[u]) {
        edge &tmp = E[k];
        if (tmp.used) continue;
        tmp.used = 1;
        int it = tmp.cmpr(u);
        if (!num[it]) {
            dfs(it);
            low[u] = min(low[u],low[it]);
            if (num[u] < low[it]) bridge++;
        } else low[u] = min(low[u],num[it]);
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    FOR(i,1,n-1) {
        int x,y; cin >> x >> y;
        v[x].pb(i);
        v[y].pb(i);
        E[i] = {x,y};
    }
    cin >> m;
    m += n-1;
    FOR(i,n,m) {
        int x,y; cin >> x >> y;
        v[x].pb(i);
        v[y].pb(i);
        E[i] = {x,y};
    }
    dfs(1);
    cout << bridge << endl;
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
