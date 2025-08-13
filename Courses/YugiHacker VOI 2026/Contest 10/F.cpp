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
ll hashS[N],hashT[N],pw[N],cur;
string s,t;
int n,ans1 = 1, ans2 = 1;

ll get(ll hs[],int l, int r) {
    return (hs[r]-hs[l-1]*pw[r-l+1]%MOD+MOD)%MOD;
}

bool check(int m) {
    FOR(i,1,n-m+1) {
        int l = i, r = i+m-1;
        if (get(hashS,l,r) == get(hashT,n-r+1,n-l+1)) {
            return 1;
        }
    }
    return 0;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    cin >> s;
    t = s;
    reverse(all(t));
    s = "#" + s;
    t = "#" + t;
    pw[0] = 1;
    FOR(i,1,n) pw[i] = (pw[i-1]*base)%MOD;
    FOR(i,1,n) {
        hashS[i] = (hashS[i-1]*base+s[i]-'a'+1)%MOD;
        hashT[i] = (hashT[i-1]*base+t[i]-'a'+1)%MOD;
    }
    int l = 1, r = n/2;
    while(l <= r) {
        int m = l+r>>1;
        if (check(2*m)) {
            ans1 = max(ans1,2*m);
            l = m + 1;
        } else r = m - 1;
    }
    l = 1, r = n/2;
    while(l <= r) {
        int m = l+r>>1;
        if (check(2*m+1)) {
            ans2 = max(ans2,2*m+1);
            l = m + 1;
        } else r = m - 1;
    }
    cout << max(ans1,ans2);

    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
