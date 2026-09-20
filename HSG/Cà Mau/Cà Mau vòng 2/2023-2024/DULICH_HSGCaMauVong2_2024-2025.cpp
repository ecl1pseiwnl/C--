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
#define rand(l,r) uniform_int_distribution<ll> (l,r) (rng);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5+7;
int n,m,s,t,x,y,k;
vector<pi> v[N];

vector<ll> dijkstra(int u) {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    q.push({0,u});
    vector<ll> d(n+1,LLINF);
    d[u] = 0;
    while(q.size()) {
        auto tmp = q.top();
        q.pop();
        ll len = tmp.fi;
        int vert = tmp.se;
        if (len > d[vert]) continue;
        for (auto it : v[vert]) {
            if (d[it.fi] > d[vert] + it.se) {
                d[it.fi] = d[vert] + it.se;
                q.push({d[it.fi],it.fi});
            }
        }
    }
    return d;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    FOR(i,1,m) {
        int x,y,w;
        cin >> x >> y >> w;
        v[x].pb({y,w});
        v[y].pb({x,w});
    }
    cin >> s >> t >> k >> x >> y;
    vector<ll> ds = dijkstra(s), dt = dijkstra(t), dx = dijkstra(x), dy = dijkstra(y);
    ll st = ds[t], xy = dx[y];
    if (k == 1) {
        vi u;
        FOR(i,1,n) {
            if (ds[i] + dt[i] == st && dx[i] + dy[i] == xy) {
                u.pb(ds[i]);
            }
        }
        if (!u.size()) return cout << 0, 0;
        cout << *max_element(all(u)) - *min_element(all(u));
    } else {
        vi u;
        FOR(i,1,n) {
            if (ds[i] + dt[i] == st && dx[i] + dy[i] == xy) {
                u.pb(i);
            }
        }
        if (!u.size()) return cout << 0, 0;
        vi legit;
        for (auto it : u) {
            if (ds[it] == dx[it]) legit.pb(ds[it]);
        }
        if (!legit.size()) return cout << 0, 0;
        cout << *max_element(all(legit)) - *min_element(all(legit));
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
