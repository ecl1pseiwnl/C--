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

const int N = 1e6+7, base = 322;
int n,m,q;
ll pw[N],hS[N],hT[N];
string s,t;

ll calcS(int l, int r) {
    return (hS[r] - hS[l-1] * pw[r-l+1] % MOD + MOD) % MOD;
}

ll calcT(int l, int r) {
    return (hT[r] - hT[l-1] * pw[r-l+1] % MOD + MOD) % MOD;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    cin >> s;
    cin >> t;
    s = "#" + s;
    t = "#" + t;
    pw[0] = 1;
    FOR(i,1,max(n,m)) {
        pw[i] = pw[i-1] * base % MOD;
    }
    FOR(i,1,n) {
        hS[i] = (hS[i-1] * base + (s[i]-'a'+1))%MOD;
    }
    FOR(i,1,m) {
        hT[i] = (hT[i-1] * base + (t[i]-'a'+1))%MOD;
    }
    cin >> q;
    while(q--) {
        int l,r,x,y;
        cin >> l >> r >> x >> y;
        int sz = min(r-l+1,y-x+1), ll = 0, rr = sz, ans;
        // Chat np tim X de l+X ra 1 xau con S co ky tu khac xau con T
        while(ll <= rr) {
            int mi = (ll+rr)/2;
            if (calcS(l,l+mi-1) == calcT(x,x+mi-1)) {
                ans = mi;
                ll = mi+1;
            } else rr = mi-1;
        }
        if (ans == sz) {
            if (r-l+1 == y-x+1) {
                cout << "=";
            } else if (r-l+1 > y-x+1) {
                cout << ">";
            } else cout << "<";
        } else {
            if (s[l+ans] == t[x+ans]) {
                cout << "=";
            } else if (s[l+ans] > t[x+ans]) {
                cout << ">";
            } else cout << "<";
        }
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
