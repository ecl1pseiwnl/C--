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

ll dp1[11],dp2[11];
int b[20];
vi v;

void bt(int pos, int ok, ll dp[]) {
    if (pos == v.size()) {
        int last = IINF;
        REP(i,v.size()) {
            if (b[i] != 0) {
                last = i;
                break;
            }
        }
        if (last == IINF) {
            dp[0]++;
        } else {
            FOR(i,last,v.size()-1) {
                dp[b[i]]++;
            }
        }
        return;
    }
    int lim = ok ? 9 : v[pos];
    FOR(c,0,lim) {
        b[pos] = c;
        bt(pos+1,ok|(c<v[pos]),dp);
    }
}

void calc(ll a, ll b) {
    if (a == 0) {
        dp1[0]++;
    } else {
        v.clear();
        while(a) {
            v.pb(a%10);
            a /= 10;
        }
        reverse(all(v));
        bt(0,0,dp1);
    }
    v.clear();
    while(b) {
        v.pb(b%10);
        b /= 10;
    }
    reverse(all(v));
    bt(0,0,dp2);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll a,b;
    while(cin >> a >> b) {
        if (a == 0 && b == 0) return 0;
        if (a > b) swap(a,b);
        FOR(i,0,10) {
            dp1[i] = dp2[i] = 0;
        }
        calc(a-1,b);
        FOR(i,0,9) {
            cout << dp2[i] - dp1[i] << " ";
        }
        cout << endl;
    }

    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
