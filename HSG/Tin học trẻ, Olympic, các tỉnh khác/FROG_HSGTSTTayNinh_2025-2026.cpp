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

const int N = 20;

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
        for (int i = 0; i < x; i++) {
            for (int k = 0; k < z; k++) {
                for (int j = 0; j < y; j++) {
                    ans.a[i][k] = (ans.a[i][k] + 1ll * a[i][j] * d.a[j][k]) % MOD;
                }
            }
        }
        return ans;
    }
    mat operator ^ (long long k) const {
        mat ans(n, n);
        for (int i = 0; i < n; i++) ans.a[i][i] = 1;
        mat mul = *this;
        while (k > 0) {
            if (k & 1) ans = ans * mul;
            mul = mul * mul;
            k >>= 1;
        }
        return ans;
    }
};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("FROG.INP","r",stdin);
    freopen("FROG.OUT","w",stdout);
    ll n;
    cin >> n;
    if (n == 0) return cout << 1, 0;
    if (n == 1) return cout << 1, 0;
    if (n == 2) return cout << 1, 0;
    if (n == 3) return cout << 2, 0;
    if (n == 4) return cout << 3, 0;
    if (n == 5) return cout << 5, 0;
    mat v(5,5);
    v.a[0][0] = 1;
    v.a[0][1] = 0;
    v.a[0][2] = 1;
    v.a[0][3] = 0;
    v.a[0][4] = 1;
    v.a[1][0] = 1;
    v.a[1][1] = 0;
    v.a[1][2] = 0;
    v.a[1][3] = 0;
    v.a[1][4] = 0;
    v.a[2][0] = 0;
    v.a[2][1] = 1;
    v.a[2][2] = 0;
    v.a[2][3] = 0;
    v.a[2][4] = 0;
    v.a[3][0] = 0;
    v.a[3][1] = 0;
    v.a[3][2] = 1;
    v.a[3][3] = 0;
    v.a[3][4] = 0;
    v.a[4][0] = 0;
    v.a[4][1] = 0;
    v.a[4][2] = 0;
    v.a[4][3] = 1;
    v.a[4][4] = 0;
    mat u(1,5);
    u.a[0][0] = 5;
    u.a[0][1] = 3;
    u.a[0][2] = 2;
    u.a[0][3] = 1;
    u.a[0][4] = 1;
    mat ans = v^(n-5);
    ll res = 0;
    REP(i,5)
        res = (res + ans.a[0][i] * u.a[0][i]) % MOD;
    cout << res;
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}


