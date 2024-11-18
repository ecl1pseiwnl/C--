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
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
constexpr int MOD = 1e9+7;
constexpr int32_t IINF = 0x3f3f3f3f;
constexpr int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

struct edge{
    int x,y,z;
};

const int N = 2e4+7;
int n,m;
ll res = LLINF, d[N],dn[N];
vector<pi> v[N],rev[N];
bool vis[N];
edge e[N];

void inp() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        e[i].x = x; e[i].y = y; e[i].z = z;
        v[x].pb({y,z});
        rev[y].pb({x,z});
    }
}

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        d[i] = LLINF;
        dn[i] = LLINF;
    }
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    q.push({0,1});
    d[1] = 0; dn[n] = 0;
    while(!q.empty()) {
        auto [x,y] = q.top();
        q.pop();
        if (vis[y]) continue;
        vis[y]=1;
        for (auto [t,w] : v[y]) {
            if (d[t] > d[y] + w) {
                d[t] = d[y] + w;
                q.push({d[t],t});
            }
        }
    }
    for (int i = 1; i <= n; i++) vis[i] = 0;
    while(!q.empty()) q.pop();
    q.push({0,n});
    while(!q.empty()) {
        auto [x,y] = q.top();
        q.pop();
        if (vis[y]) continue;
        vis[y]=1;
        for (auto [t,w] : rev[y]) {
            if (dn[t] > dn[y] + w) {
                dn[t] = dn[y] + w;
                q.push({dn[t],t});
            }
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(name ".inp", "r")) {
        freopen(name ".inp","r",stdin);
        freopen(name ".out","w",stdout);
    }
    inp();
    dijkstra();
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " " << dn[i] << "\n";
    }
    for (int i = 1; i <= m;i++) {
        int x,y,z;
        x = e[i].x; y = e[i].y; z = e[i].z;
        if (d[x]+dn[y]+z > d[n]) {
            res = min(res,d[x]+dn[y]+z);
        }
    }
    if (res == LLINF) {
        cout << -1;
    } else {
        cout << res;
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
