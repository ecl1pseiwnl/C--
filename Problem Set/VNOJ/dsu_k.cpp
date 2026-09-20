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

const int N = 1007;
struct edge{
    int x,y,w;
};
int n,m,par[N],sz[N],par1[N],sz1[N],m1,m2;
ll ans1,ans2;
vector<edge> v;

void makeset() {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
        par1[i] = i;
        sz1[i] = 1;
    }
}

int findset(int u) {
    if (u == par[u]) return u;
    return par[u] = findset(par[u]);
}

bool unite(int a, int b) {
    a = findset(a);
    b = findset(b);
    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    par[b] = a;
    return 1;
}

bool cmp(edge a, edge b) {
    return a.w > b.w;
}

int findset1(int u) {
    if (u == par1[u]) return u;
    return par1[u] = findset(par1[u]);
}

bool unite1(int a, int b) {
    a = findset1(a);
    b = findset1(b);
    if (a == b) return 0;
    if (sz1[a] < sz1[b]) swap(a,b);
    sz1[a] += sz1[b];
    par1[b] = a;
    return 1;
}

bool cmp1(edge a, edge b) {
    return a.w < b.w;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    makeset();
    REP(i,m) {
        edge e;
        cin >> e.x >> e.y >> e.w;
        v.pb(e);
    }
    sort(all(v),cmp);
    ll d = 0;
    vi mst;
    REP(i,m) {
        edge e = v[i];
        if (mst.size() == n-1) break;
        if (unite(e.x,e.y)) {
            mst.pb(e.w);
            d += e.w;
        }
    }
    m1 = mst.size();
    ans1 = *max_element(all(mst)) - *min_element(all(mst));
    d = 0;
    mst.clear();
    sort(all(v),cmp1);
    REP(i,m) {
        edge e = v[i];
        if (mst.size() == n-1) break;
        if (unite1(e.x,e.y)) {
            mst.pb(e.w);
            d += e.w;
        }
    }
    m2 = mst.size();
    ans2 = *max_element(all(mst)) - *min_element(all(mst));
    if (m1 != n-1 && m2 != n-1) {
        cout << "NOT FOUND";
    } else cout << min(ans1,ans2);
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}

