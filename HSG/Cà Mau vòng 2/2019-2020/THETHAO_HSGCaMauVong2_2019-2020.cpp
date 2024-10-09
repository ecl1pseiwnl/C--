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

const int N = 1e3+7, INF = 1e9;
int n,m,x,y;
vector<pi> v[N];
vector<int> a,b;

void inp() {
    cin >> n >> m >> x >> y;
    for (int i = 0; i < m; i++) {
        int u,t,z;
        cin >> u >> t >> z;
        v[u].pb({t,z});
        v[t].pb({u,z});
    }
}

void dijkstra(int u, bool check) {
    vector<ll> d(n+1, INF);
    d[u] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0,u});
    while(!q.empty()) {
        auto [len,vert] = q.top();
        q.pop();
        if (len > d[vert]) continue;
        for (auto it : v[vert]) {
            int x = it.first, w = it.second;
            if (d[x] > d[vert] + w) {
                d[x] = d[vert] + w;
                q.push({d[x],x});
            }
        }
    }
    if (check) {
        for (int i = 1; i <= n; i++) {
            a.ep(d[i]);
        }
    } else {
        for (int i = 1; i <= n; i++) {
            b.ep(d[i]);
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
    a.ep(0);
    b.ep(0);
    dijkstra(x,true);
    dijkstra(y,false);
    ll minT = INF, ans = -1;
    for (int i = 1; i <= n; i++) {
        ll cur = max(a[i],b[i]);
        if (cur < minT && cur != 0) {
            minT = cur;
            ans = i;
        }
    }
    cout << ans << " " << minT;
    return 0;
}
