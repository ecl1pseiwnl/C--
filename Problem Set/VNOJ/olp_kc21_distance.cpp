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

const int N = 1e5+7;
int n,m,q;
ll v[N],u[N],dp[22][N];

ll get(int l, int r) {
    int k = 31 - __builtin_clz(r-l+1);
    return min(dp[k][l], dp[k][r-(1<<k)+1]);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> q;
    FOR(i,1,n) cin >> v[i];
    FOR(i,1,m) cin >> u[i];
    sort(u+1,u+m+1);
    FOR(i,1,n) {
        ll cur = LLINF;
        int x = lower_bound(u+1,u+m+1,v[i]) - u;
        if (x <= m) cur = min(cur,abs(u[x]-v[i]));
        if (x > 1)  cur = min(cur,abs(u[x-1]-v[i]));
        dp[0][i] = cur;
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i+(1<<j)-1 <= n; i++) {
            dp[j][i] = min(dp[j-1][i], dp[j-1][i+(1<<(j-1))]);
        }
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << get(l,r) << endl;
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}

