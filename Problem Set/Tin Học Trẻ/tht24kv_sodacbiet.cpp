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

ll bp(ll n) {
    return 1ll*2*((n*(n+1))/2);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n,m, ans = 0;
    cin >> n >> m;
    if (n <= 2) {
        ans += n;
    } else if (n > 2) {
        if (n % 2 == 0) {
            ans += bp(int(ceil(double(n)/2.0)))- int(ceil(double(n)/2.0));
        } else {
            ans += bp(int(ceil(double(n)/2.0)));
        }
    }
    debug(ans);
    if (m <= 2) {
        ans += m-1;
    }
    else if (m > 2) {
        ans++;
        ll k = m-2;
        if (k % 2 == 0) {
            ans += bp(int(ceil(double(k-1)/2.0)))- int(ceil(double(k)/2.0));
        } else ans += bp(int(ceil(double(k-1)/2.0)));

    }
    cout << ans;
    cerr << "Time elapsed: " << TIME << "s. \n";
    return 0;
}

/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9
1 2 4 6 9 12 16 20 25 30 36 42 49 56 64 72 81 90

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
0 1 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8
0 1 2 3 5 7 10 13 17 21 26 31 37 43 50 57 65 73 82 91
*/
