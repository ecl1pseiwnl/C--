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
int n,k;
ll v[N],t[N<<2];
vector<ll> dp(N,-LLINF);

void update(int id, int l, int r, int pos, ll x) {
    if (pos < l || pos > r) return;
    if (l == r) return t[id] = x, void();
    int m = l+r>>1;
    update(id<<1,l,m,pos,x);
    update(id<<1|1,m+1,r,pos,x);
    t[id] = max(t[id<<1],t[id<<1|1]);
}

ll get(int id, int l, int r, int x, int y) {
    if (l > y || r < x) return -LLINF;
    if (l >= x && r <= y) return t[id];
    int m = l+r>>1;
    return max(get(id<<1,l,m,x,y),get(id<<1|1,m+1,r,x,y));
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("kbox.inp","r",stdin);
    freopen("kbox.out","w",stdout);
    cin >> n >> k;
    FOR(i,1,n) {
        cin >> v[i];
    }
    dp[1] = v[1];
    update(1,1,n,1,dp[1]);
    FOR(i,2,n) {
        if (i-k >= 1) {
            dp[i] = max(0ll,get(1,1,n,i-k,i-1)) + v[i];
            update(1,1,n,i,dp[i]);
        } else {
            dp[i] = max(0ll,get(1,1,n,1,i-1)) + v[i];
            update(1,1,n,i,dp[i]);
        }
    }
    cout << max(0ll,get(1,1,n,1,n));
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
