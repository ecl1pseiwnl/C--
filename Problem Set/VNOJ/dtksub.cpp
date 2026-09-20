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

const int base = 256, N = 5e4+7;
ll hashS[N],pw[N],n,k,ans;
string s;

ll cal(int l, int r) {
    return 1ll*(hashS[r] - hashS[l-1] * pw[r-l+1] % MOD + MOD) % MOD;
}

bool check(int m) {
    vector<ll> v;
    for (int i = 1; i <= n-m+1; i++) {
        ll cur = cal(i,i+m-1);
        v.pb(cur);
    }
    sort(all(v));
    int cnt = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i-1]) {
            cnt++;
        } else cnt = 1;
        if (cnt >= k) {
            return 1;
        }
    }
    return 0;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    s = "#" + s;
    if (k == 1) return cout << n, 0;
    pw[0] = 1;
    for (int i = 1; i <= n; i++) pw[i] = (1ll*pw[i-1] * base)%MOD;
    for (int i = 1; i <= n; i++) hashS[i] = (hashS[i-1] * base + s[i] - 'a' + 1) % MOD;
    int l = 0, r = n;
    while (l <= r) {
        int m = (l+r)/2;
        if (check(m)) {
            ans = m;
            l = m+1;
        } else r = m-1;
    }
    cout << ans;
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
