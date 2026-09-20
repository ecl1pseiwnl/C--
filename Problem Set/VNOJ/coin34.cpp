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

const int n = 34;
vector<ll> a, b;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<ll> c(n+1);
    c[1] = 2;
    c[2] = 3;
    c[3] = 5;
    for (int i = 4; i <= n; i++) {
        c[i] = (c[i-1] + c[i-2] + c[i-3]);
    }
    for (int i = 1; i <= n; i++) {
        if (i <= n/2) {
            a.ep(c[i]);
        } else {
            b.ep(c[i]);
        }
    }
    int m = a.size();
    vector<pair<ll,int>> l, r;
    for (int mask = 0; mask < (1<<m); mask++) {
        ll s = 0;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                cnt++;
                s += a[i];
            }
        }
        l.pb({s,cnt});
    }
    m = b.size();
    for (int mask = 0; mask < (1<<m); mask++) {
        ll s = 0;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                cnt++;
                s += b[i];
            }
        }
        r.pb({s,cnt});
    }
    sort(all(l));
    sort(all(r));
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        ll x;
        cin >> x;
        ll ans = -1;
        for (auto it : l) {
            ll val = it.fi, c = it.sec;
            if (val > x) break;
            auto t = lower_bound(all(r),make_pair(x-val,0));
            if (t != l.begin()) {
                if (t->fi + val == x) {
                    ans = max(ans,t->sec + c);
                }
            }
        }
        cout << "Case #" << k << ": " << (ans == -1 ? -1 : ans) << endl;
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
