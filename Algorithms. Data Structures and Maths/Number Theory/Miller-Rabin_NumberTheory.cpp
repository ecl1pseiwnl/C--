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

/// Theo Fermat nhỏ, ta có:
/// a^p-1 đồng dư cho 1 (mod p) nếu p là snt <=> gcd(a,p) = 1.
/// p nguyên tố => a^p-1 đồng dư 1 (mod p).
/// a^p-1 không đồng dư 1 (mod p) => p không nguyên tố.
/// a^p-1 đồng dư 1 (mod p) -> có khả năng p là nguyên tố.

/// Thuật toán kiểm tra nguyên tố Miller Rabin:
/// Kiểm tra số n có snt hay không bằng cách áp dụng theo Fermat nhỏ
/// ta sẽ thử kiểm tra nhiều số a bất kì với a < n sẽ có hai TH:
/// (1) a^n-1 đồng dư cho 1 (mod n) => snt (nhưng có xác suất sai nhỏ)
/// (2) a^n-1 không đồng dư cho 1 (mod n) => hợp số

/// Ta có a^2s đồng dư 1 (mod n) <=> a^2s - 1 đồng dư 0 (mod n)
/// và rồi ta sẽ chia nhỏ ra thành:
///    (a^s - 1)(a^s + 1)
/// => (a^s/2 - 1)(a^s/2 + 1)(a^s + 1)
/// => ...
/// VD: (a^100 - 1) => (a^50 - 1)(a^50 + 1) => (a^25 - 1)(a^25 + 1)(a^50 + 1).
/// Đến khi nào mà cụm trên chia hết cho n thì đó chính là snt với xác suất sai nhỏ.


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

bool MillerRabin(ll n) {
    vi a = {2,3,5,7,11};
    if (n < 2) return 0;
    ll s = (n-1);
    while (s % 2 == 0) s >>= 1;
    for (int i = 0; i < a.size(); i++) {
        if (n == a[i]) return 1;
        if (!check(a[i],s,n)) return 0;
    }
    return 1;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n;
    cin >> n;
    if (MillerRabin(n)) {
        cout << "YES\n";
    } else cout << "NO\n";
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
