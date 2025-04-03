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

#define int long long

const int N = 105;
int n,m,x,y,u,v;
vector<pi> adj[N];
vector<ll> a,b;

void inp() {
    cin >> n >> m;
    cin >> x >> y >> u >> v;
    for (int i = 0; i < m; i++) {
        int t,s,w;
        cin >> t >> s >> w;
        adj[t].pb({s,w});
        adj[s].pb({t,w});
    }
}

void dijkstra(int x, bool tf) {
    priority_queue<pi,vector<pi>,greater<pi>> q;
    q.push({0,x});
    vector<ll> d(n+1, LLINF);
    d[x] = 0;
    while(!q.empty()) {
        auto [len,vert] = q.top();
        q.pop();
        if (len > d[vert]) continue;
        for (auto [z,w] : adj[vert]) {
            if (d[z] > d[vert] + w) {
                d[z] = d[vert] + w;
                q.push({d[z],z});
            }
        }
    }
    if (tf) {
        for (int i = 1; i <= n; i++) {
            a.pb(d[i]);
        }
    } else {
        for (int i = 1; i <= n; i++) {
            b.pb(d[i]);
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
    a.pb(LLINF);
    b.pb(LLINF);
    dijkstra(x,1);
    dijkstra(u,0);
    if (a[y] == LLINF || b[v] == LLINF) {
        return cout << -1, 0;
    }
    ll ans = LLINF;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) ans = min(a[i],ans);
    }
    cout << (ans == LLINF ? -1 : ans);
    cerr << "Time elapsed: " << TIME << "s. \n";
    return 0;
}

