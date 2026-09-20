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
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }
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
constexpr int MOD = 1e9+7;
constexpr int IINF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;

ll inf = 1e18;
vector<ll> p;

ll binpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if (b&1) ans *=a;
        a*=a;
        b>>=1;
    }
    return ans;
}

bool check(int x, int y, int z) {
    ll res = 1;
    for (int i = 1; i <= x; i++) {
        res *= 2;
        if (res > inf) return 0;
    }
    for (int i = 1; i <= y; i++) {
        res *= 3;
        if (res > inf) return 0;
    }
    for (int i = 1; i <= z; i++) {
        res *= 5;
        if (res > inf) return 0;
    }
    return 1;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 0; i <= 80; i++) {
        for (int j = 0; j <= 80; j++) {
            for (int k = 0; k <= 80; k++) {
                if (check(i,j,k)) {
                    ll cur = binpow(2,i)*binpow(3,j)*binpow(5,k);
                    p.pb(cur);
                }
            }
        }
    }
    sort(all(p));
    int q;
    cin >> q;
    while(q--) {
        ll x;
        cin >> x;
        int pos = lower_bound(all(p),x)-p.begin();
        cout << (p[pos] == x ? pos+1 : -1) << endl;
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
