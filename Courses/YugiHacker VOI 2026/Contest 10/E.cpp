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
#define Mask(x,i) (((x) >> (i)) & 1)
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

const int base = 322, N = 1e5+7;
ll hashS[N], pw[N];
int n,k;
string s;

ll get(int l, int r) {
    return 1ll* (hashS[r] - hashS[l-1] * pw[r-l+1] % MOD + MOD)%MOD;
}

bool check(int m) {
    unordered_map<ll,int> ans;
    FOR(i,1,n-m+1) {
        ll cur = get(i,i+m-1);
        ans[cur]++;
    }
    for (auto it : ans) {
        if (it.se >= k) return 1;
    }
    return 0;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    n = s.size();
    s = "#" + s;
    pw[0] = 1;
    FOR(i,1,n) pw[i] = 1ll*(pw[i-1]*base)%MOD;
    FOR(i,1,n) hashS[i] = 1ll*(hashS[i-1]*base+s[i]-'a'+1)%MOD;
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int m = l+r>>1;
        if (check(m)) {
            ans = m;
            l = m + 1;
        } else r = m - 1;
    }
    cout << ans;
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
