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

const int N = 1e6+7;
int f[N];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(name ".inp", "r")) {
        freopen(name ".inp","r",stdin);
        freopen(name ".out","w",stdout);
    }
    int n;
    cin >> n;
    vi a(n+1),b(1,0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]] = 1;
    }
    for (int i = 1; i <= 2*n; i++) {
        if (!f[i]) {
            b.ep(i);
        }
    }
    set<int> x,y;
    for (int i = 1; i <= n; i++) {
        if (i <= n / 2) {
            y.emplace(b[i]);
        } else {
            x.emplace(b[i]);
        }
    }
    sort(a.begin()+1,a.begin()+n/2+1);
    sort(a.begin()+n/2+1,a.end(),greater<int>());
    int ans = 0;
    for (int i = 1; i <= n/2; i++) {
        auto it = x.lower_bound(a[i]);
        if (it != x.end()) {
            ans++;
            x.erase(it);
        }
    }
    for (int i = n/2+1; i <= n; i++) {
        auto it = y.lower_bound(a[i]);
        if (it != y.begin()) {
            ans++;
            y.erase(prev(it));
        }
    }
    cout << ans;
    return 0;
}
