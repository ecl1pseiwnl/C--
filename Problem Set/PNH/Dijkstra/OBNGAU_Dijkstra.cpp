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

const int N = 1e5+7, INF = INT_MAX;
int n,m,s,t;
vector<pi> v[N];
vector<ll> a,b;

void inp() {
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        v[x].pb({y,z});
        v[y].pb({x,z});
    }
}

void dijkstra(int s, bool tf) {
    vector<ll> d(n+1,LLINF);
    d[s] = 0;
    priority_queue<pi,vector<pi>,greater<pi>> q;
    q.push({0,s});
    while(!q.empty()) {
        pi top = q.top();
        q.pop();
        int vert = top.second, length = top.first;
        if (d[vert] < length) continue;
        for (auto it : v[vert]) {
            int x = it.first, y = it.second;
            if (d[x] > d[vert] + y) {
                d[x] = d[vert] + y;
                q.push({d[x],x});
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
    dijkstra(s,1);
    dijkstra(t,0);
    debug(a,b);
    ll minv = LLINF, ans = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i] && a[i] < minv) {
            minv = a[i];
            ans = i;
        }
    }
    if (ans == -1) {
        cout << "CRY";
    } else cout << ans;
    cerr << "Time elapsed: " << TIME << "s. \n";
    return 0;
}
