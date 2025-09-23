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
#define BIT(x,i) (((x) >> (i)) & 1)
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

const int N = 1e5+7, lg = 19;

namespace answer {
    int n;
    ll dp[lg][N], v[N], u[N];

    ll calc(int l, int r) {
        int k = 31 - __builtin_clz(r-l+1);
        return __gcd(dp[k][l],dp[k][r-(1<<k)+1]);
    }

    void sol() {
        cin >> n;
        FOR(i,1,n) {
            cin >> v[i];
        }
        FOR(i,1,n) {
            cin >> u[i];
            dp[0][i] = abs(v[i]-u[i]);
        }
        for (int j = 1; (1<<j) <= n; j++) {
            for (int i = 1; i+(1<<j)-1 <= n; i++) {
                dp[j][i] = __gcd(dp[j-1][i],dp[j-1][i+(1<<(j-1))]);
            }
        }
        int L = 0, R = 0; ll maxv = 0;
        FOR(i,1,n) {
            int j = i;
            FORD(k,lg,0) {
                if (j + (1<<k) <= n && calc(i,j+(1<<k)) >= 2) j += (1<<k);
                if (j-i+1 >= R-L+1 && maxv < calc(i,j) || j-i+1 > R-L+1) {
                    R = j; L = i;
                    maxv = calc(L,R);
                }
            }
        }
        if (maxv >= 2) {
            cout << R-L+1 <<" " << maxv << endl;
        } else if (maxv == 0) {
            cout << n << " " << 0 << endl;
        } else cout << -1 << endl;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        answer::sol();
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
