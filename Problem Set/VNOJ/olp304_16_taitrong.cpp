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
const double PI = 3.141592653589793238463;
#define bmask(x,i) (((x) >> (i)) & 1)
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
ll __lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
const int EPS = -1e9;
constexpr int MOD = 1e9+7;
constexpr int32_t IINF = 0x3f3f3f3f;
constexpr int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5+7;
int n,m,s,t, par[N];
vector<pair<ll,ll>> v[N];
vector<ll> ans;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("TAITRONG.INP","r",stdin);
    freopen("TAITRONG.OUT","w",stdout);
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        v[x].pb({y,z});
        v[y].pb({x,z});
    }
    vector<ll> d(n+1, -LLINF);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,s});
    d[s] = LLINF;
    while(!q.empty()) {
        auto [len,vert] = q.top();
        q.pop();
        for (auto [x,w] : v[vert]) {
            ll dist = max(d[x],min(d[vert],w));
            if (dist > d[x]) {
                d[x] = dist;
                par[x] = vert;
                q.push({dist,x});
            }
        }
    }
    while(t != s) {
        ans.pb(d[t]);
        t = par[t];
    }
    ans.pb(d[t]);
    cout << *min_element(all(ans));
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
