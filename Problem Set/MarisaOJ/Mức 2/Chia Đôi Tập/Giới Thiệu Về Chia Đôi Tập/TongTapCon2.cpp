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
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define ins insert
#define sz(x) (int)(x.size())
#define name "data"
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

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(name ".INP", "r")) {
        freopen(name ".INP","r",stdin);
        //freopen(name ".OUT","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    vector<ll> l,r, u,v;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        if (i <= n/2) {
            l.pb(x);
        } else r.pb(x);
    }
    ll m = n/2;
    for (ll mask = 0; mask < (1 << m); mask++) {
        ll s = 0;
        for (ll i = 0; i < m; i++) {
            if ((mask>>i) & 1) s += l[i];
        }
        u.pb(s);
    }
    m = n - m;
    for (ll mask = 0; mask < (1 << m); mask++) {
        ll s = 0;
        for (ll i = 0; i < m; i++) {
            if ((mask>>i) & 1) s += r[i];
        }
        v.pb(s);
    }
    bool tf = 0;
    sort(all(v));
    sort(all(u));
    for (auto it : u) {
        ll x = (ll)(lower_bound(all(v),k-it) - v.begin());
        ll y = (ll)(upper_bound(all(v),k-it) - v.begin());
        if ((y-x) > 0) tf = 1;
    }
    cout << (tf ? "YES" : "NO");
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
