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
ll lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
const int MOD = 1e9+7;
const int32_t IINF = 0x3f3f3f3f;
const int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(name ".inp", "r")) {
        freopen(name ".inp","r",stdin);
        freopen(name ".out","w",stdout);
    }
    int n,m;
    cin >> n >> m;
    vi a(n);
    for (auto& it : a) cin >> it;
    int n1 = n / 2;
    int n2 = n - n1;
    vi x,y;
    for (int mask = 0; mask < (1 << n1); mask++) {
        int s = 0;
        for (int i = 0; i < n1; i++) {
            if ((mask>>i) & 1) {
                s += a[i];
                s %= m;
            }
        }
        x.ep(s);
    }
    for (int mask = 0; mask < (1 << n2); mask++) {
        int s = 0;
        for (int i = 0; i < n2; i++) {
            if ((mask>>i) & 1) {
                s += a[i+n1];
                s %= m;
            }
        }
        y.ep(s);
    }
    sort(all(y));
    int ans = 0;
    for (auto& it : x) {
        ans = max(ans, (it + y.back())% m);
        auto t = lower_bound(y.begin(),y.end(),m-it);
        if (t == y.begin()) continue;
        t--;
        ans = max(ans,(it + *t) % m);
    }
    cout << ans;
    return 0;
}
