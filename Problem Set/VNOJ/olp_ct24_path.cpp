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

const int N = 2e5+7;
int n,m,k;
pi p[N];
ll inv[N],fact[N],dp[N];

ll binpow(ll a, ll b) {
    ll ans = 1;
    a %= MOD;
    while(b) {
        if (b&1) ans = ans*a%MOD;
        a = a*a%MOD;
        b>>=1;
    }
    return ans;
}

void prep() {
    fact[0] = 1;
    FOR(i,1,N) {
        fact[i] = fact[i-1]*i%MOD;
    }
    inv[N-1] = binpow(fact[N-1],MOD-2);
    FORD(i,N-1,1) {
        inv[i-1] = inv[i] * i % MOD;
    }
}

ll C(ll n, ll k) {
    if (k > n) return 0;
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

ll calc(int x1, int y1, int x2, int y2) {
    return x1 > x2 || y1 > y2 ? 0 : C(x2-x1+y2-y1,x2-x1);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    prep();
    cin >> n >> m >> k;
    FOR(i,1,k) {
        cin >> p[i].fi >> p[i].se;
    }
    p[k+1] = {n,m};
    sort(p+1,p+k+2);
    FOR(i,1,k+1) {
        dp[i] = calc(1,1,p[i].fi,p[i].se);
        FOR(j,1,i-1) {
            if (p[j].fi <= p[i].fi && p[j].se <= p[i].se) {
                    dp[i] = (dp[i]%MOD - (dp[j] * calc(p[j].fi,p[j].se,p[i].fi,p[i].se)%MOD)%MOD+MOD)%MOD;
            }
        }
    }
    cout << dp[k+1];
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}

