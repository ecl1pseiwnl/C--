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

ll binmul(ll a, ll b, ll MOD) {
    ll res = 0;
    while(b > 0) {
        if (b & 1) res = (res+a)%MOD;
        a = a*2%MOD;
        b >>= 1;
    }
    return res;
}

ll binpow(ll a, ll b, ll MOD) {
    ll ans = 1;
    while(b>0) {
        if (b & 1) ans = binmul(ans,a,MOD);
        a = binmul(a,a,MOD);
        b >>= 1;
    }
    return ans;
}

bool check(ll a, ll s, ll n) {
    ll x = binpow(a,s,n);
    if (x == 1 || x == n-1) return 1;
    while (s < n-1) {
        x = binmul(x,x,n);
        if (x == n-1) return 1;
        s *= 2;
    }
    return 0;
}

bool MR(ll n) {
    vi v = {2,3,5,7,11,13,17,19,23};
    if (n < 2) return 0;
    ll s = (n-1);
    while (s % 2 == 0) s >>= 1;
    for (int i = 0; i < v.size(); i++) {
        if (n == v[i]) return 1;
        if (!check(v[i],s,n)) return 0;
    }
    return 1;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("divisors.inp","r",stdin);
    freopen("divisors.out","w",stdout);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans = 1;
        for (ll i = 2; i <= 1e6+2; i++) {
            if (n % i == 0) {
                ll cnt = 0;
                while(n % i == 0) {
                    n /= i;
                    cnt++;
                }
                ans = ans * (cnt+1);
            }
        }
        if (n > 1) {
            if (MR(n)) {
                ans *= 2;
            } else {
                ll k = sqrt(n);
                if (k*k == n) {
                    ans *= 3;
                } else ans *=4;
            }
        }
        cout << ans <<endl;
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
