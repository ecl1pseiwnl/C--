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

#define int long long

const int N = 2e5+7;
int n,m,par[N], wei[N];
vector<pair<int,ll>> v[N];

void dijkstra() {
    vector<vector<ll>> d(n+1,vector<ll>(2,LLINF));
    d[1][0] = 0;
    priority_queue<pair<ll,pi>,vector<pair<ll,pi>>, greater<pair<ll,pi>>> q;
    q.push({0,{1,0}});
    while(!q.empty()) {
        auto it = q.top();
        q.pop();
        int len = it.fi, vert = it.sec.fi, cnt = it.sec.sec;
        if (len > d[vert][cnt]) continue;
        for (auto te : v[vert]) {
            int x = te.fi, w = te.sec;
            if (!cnt && d[x][cnt+1] > d[vert][cnt]) {
                d[x][cnt+1] = d[vert][cnt];
                q.push({d[x][cnt+1],{x,cnt+1}});
            }
            if (d[x][cnt] > d[vert][cnt] + w) {
                d[x][cnt] = d[vert][cnt] + w;
                q.push({d[x][cnt],{x,cnt}});
            }
        }
    }
    ll ans = LLINF;
    for (int i = 0; i <= 1; i++) ans = min(ans,d[n][i]);
    cout << (ans == LLINF ? -1 : ans);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0,x,y,z; i < m; i++) {
        cin >> x >> y >> z;
        v[x].pb({y,z});
        v[y].pb({x,z});
    }
    dijkstra();
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
