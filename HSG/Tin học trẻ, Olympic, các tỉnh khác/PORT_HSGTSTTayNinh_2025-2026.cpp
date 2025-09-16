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

const int N = 1e5+7;
int n,m,p,k,s,t;
vector<pi> v[N];
vi u[N];

namespace sub1{
    bool check() {
        return p == 0 && k == 0;
    }
    void sol() {
        priority_queue<pi,vector<pi>,greater<pi>> q;
        q.push({0,s});
        vi d(n+1,IINF);
        d[s] = 0;
        while(q.size()) {
            auto [len,vert] = q.top(); q.pop();
            if (len > d[vert]) continue;
            for (auto [x,w] : v[vert]) {
                if (d[x] > d[vert] + w) {
                    d[x] = d[vert] + w;
                    q.push({d[x],x});
                }
            }
        }
        cout << (d[t] == IINF ? -1 : d[t]);
    }
}

namespace sub2 {
    bool check() {
        return k != 0 && p != 0;
    }
    void sol() {
        priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> q;
        q.push({0,{s,0}});
        vector<vi> d(n+1,vi(k+5,IINF));
        d[s][0] = 0;
        while(q.size()) {
            auto [len,tmp] = q.top(); q.pop();
            auto [vert,cnt] = tmp;
            if (len > d[vert][cnt]) continue;
            for (auto [x,w] : v[vert]) {
                if (d[x][cnt] > d[vert][cnt] + w) {
                    d[x][cnt] = d[vert][cnt] + w;
                    q.push({d[x][cnt],{x,cnt}});
                }
                if (cnt < k) {
                    for (auto it : u[x]) {
                        if (d[it][cnt+1] > d[vert][cnt]) {
                            d[it][cnt+1] = d[vert][cnt];
                            q.push({d[x][cnt+1],{it,cnt+1}});
                        }
                    }
                }
            }
        }
        int ans = IINF;
        FOR(i,0,k) {
            ans = min(ans,d[t][i]);
        }
        cout << (ans == IINF ? -1 : ans);
    }
}

signed main() {
    freopen("PORT.INP","r",stdin);
    freopen("PORT.OUT","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> p >> k >> s >> t;
    FOR(i,1,m) {
        int x,y,z;
        cin >> x >> y >> z;
        v[x].pb({y,z});
        v[y].pb({x,z});
    }
    while(p--) {
        int x,y;
        cin >> x >> y;
        u[x].pb(y);
    }
    if (sub1::check()) {
        sub1::sol();
    } else if (sub2::check()) {
        sub2::sol();
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}

