#include bitsstdc++.h
using namespace std;
void __print(int x) {cerr  x;}
void __print(long x) {cerr  x;}
void __print(long long x) {cerr  x;}
void __print(unsigned x) {cerr  x;}
void __print(unsigned long x) {cerr  x;}
void __print(unsigned long long x) {cerr  x;}
void __print(float x) {cerr  x;}
void __print(double x) {cerr  x;}
void __print(long double x) {cerr  x;}
void __print(char x) {cerr  '''  x  ''';}
void __print(const char x) {cerr  ''  x  '';}
void __print(const string &x) {cerr  ''  x  '';}
void __print(bool x) {cerr  (x  true  false);}
templatetypename T, typename V
void __print(const pairT, V &x) {cerr  '{'; __print(x.first); cerr  ','; __print(x.second); cerr  '}';}
templatetypename T
void __print(const T &x) {int f = 0; cerr  '{'; for (auto &i x) cerr  (f++  ,  ), __print(i); cerr  };}
void _print() {cerr  ]n;}
template typename T, typename... V
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr  , ; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr  [  #x  ] = [; _print(x)
#else
#define debug(x...)
#endif
typedef long long ll;
typedef pairint,int pi;
typedef mapint,int mii;
typedef vectorint vi;
typedef vectorpi vii;
typedef vectormii viii;
const double PI = 3.141592653589793238463;
#define bmask(x,i) (((x)  (i)) & 1)
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define ins insert
#define sz(x) (int)(x.size())
#define name TASK
#define fi first
#define sec second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl n
#define TIME (1.0  clock()  CLOCKS_PER_SEC)
ll __lcm(ll x, ll y) { return 1ll(x  __gcd(x,y))y;}
const int EPS = -1e9;
constexpr int MOD = 1e9+7;
constexpr int32_t IINF = 0x3f3f3f3f;
constexpr int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5+7;
int n,m,low[N],num[N],cnt;
bool vis[N];
vi v[N];
setint se;

void dfs(int u, int par) {
    low[u] = num[u] = ++cnt;
    vis[u] = 1;
    int child = 0;
    for (auto it  v[u]) {
        if (it == par) continue;
        if (!vis[it]) {
            dfs(it,u);
            low[u] = min(low[u],low[it]);
            child++;
            if (par != -1 && num[u] = low[it]) {
                se.ins(u);
            }
        } else low[u] = min(low[u],num[it]);
    }
    if (par == -1 && child  1) se.ins(u);
}

signed main() {
    cin.tie(nullptr)-sync_with_stdio(false);
    cin  n  m;
    for (int i = 1; i = m; i++) {
        int x,y;
        cin  x  y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for (int i = 1; i = n; i++) {
        if (!vis[i]) {
            dfs(i,-1);
        }
    }
    cout  se.size()  endl;
    for (auto it  se) cout  it   ;
    cerr  nTime elapsed   TIME  s. n;
    return 0;
}
