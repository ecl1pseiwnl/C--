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
constexpr int MOD = 1e9+7;
constexpr int32_t IINF = 0x3f3f3f3f;
constexpr int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 4e4+7;
int n,m, par[N], sz[N];
struct edge{
    int x,y,z;
};
vector<edge> v;

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        edge e;
        cin >> e.x >> e.y >> e.z;
        v.pb(e);
    }
}

void makeset() {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int findset(int u) {
    if (u == par[u]) return u;
    return par[u] = findset(par[u]);
}

bool uni(int a, int b) {
    a = findset(a);
    b = findset(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a,b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}

bool cmp(edge a, edge b) {
    return a.z > b.z;
}

void kruskal() {
    vi ans;
    sort(all(v),cmp);
    for (int i = 0; i < m; i++) {
        if (ans.size() == n - 1) break;
        edge e = v[i];
        if (uni(e.x, e.y)) {
            ans.pb(e.z);
        }
    }
    cout << *min_element(all(ans));
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(name ".inp", "r")) {
        freopen(name ".inp","r",stdin);
        freopen(name ".out","w",stdout);
    }
    inp();
    makeset();
    kruskal();
    return 0;
}
