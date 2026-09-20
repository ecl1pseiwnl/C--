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
//constexpr int MOD = 1e9+7;
constexpr int IINF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 20;
ll n,m,MOD;

ll binmul(ll a, ll b) {
    ll res = 0;
    while(b > 0) {
        if (b & 1) res = res+a%MOD;
        a = a*2%MOD;
        b >>= 1;
    }
    return res;
}

struct mat{
    int n,m;
    ll a[N][N];
    mat(int _n = 0, int _m = 0) {
        n = _n; m = _m;
        ms(a,0);
    }
    mat operator * (const mat &d) const {
        int x = n, y = m, z = d.m;
        mat ans(x,z);
        REP(i,x) {
            REP(k,z) {
                REP(j,y) {
                    ans.a[i][k] = (ans.a[i][k] + 1ll * binmul(a[i][j],d.a[j][k])) % MOD;
                }
            }
        }
        return ans;
    }

    mat operator ^ (ll k) {
        mat ans(n,n);
        REP(i,n) ans.a[i][i] = 1;
        mat mul = *this;
        while(k) {
            if (k&1) ans = ans * mul;
            mul = mul * mul;
            k>>=1;
        }
        return ans;
    }
};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> MOD;
    ll g = __gcd(n,m);
    mat v(1,2);
    v.a[0][0] = 0;
    v.a[0][1] = 1;
    mat u(2,2);
    u.a[0][0] = 0;
    u.a[0][1] = 1;
    u.a[1][0] = 1;
    u.a[1][1] = 1;
    mat ans = v * (u ^ g);
    cout << ans.a[0][0];
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
