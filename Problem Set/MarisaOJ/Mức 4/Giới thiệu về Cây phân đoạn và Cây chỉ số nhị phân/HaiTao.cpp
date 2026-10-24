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
int n,q;
struct qu{
    int l, r; ll x;
};
bool cmp(qu a, qu b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}
qu Q[N];
vector<ll> t(4*N,LLINF), dp(N,LLINF);

void update(int id, int l, int r, int pos, ll val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        return t[id] = min(t[id],val), void();
    }
    int m = (l+r)/2;
    update(id<<1,l,m,pos,val);
    update(id<<1|1,m+1,r,pos,val);
    t[id] = min(t[id<<1],t[id<<1|1]);
}

ll get(int id, int l, int r, int x, int y) {
    if (l > r || y < l || x > r) return LLINF;
    if (x <= l && r <= y) return t[id];
    int m = (l+r)/2;
    return min(get(id<<1,l,m,x,y),get(id<<1|1,m+1,r,x,y));
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    FOR(i,1,q) {
        int x,y; ll val;
        cin >> x >> y >> val;
        Q[i].l = x;
        Q[i].r = y;
        Q[i].x = val;
    }
    sort(Q+1,Q+q+1,cmp);
    FOR(i,1,q) {
        int l = Q[i].l;
        int r = Q[i].r;
        ll x = Q[i].x;
        ll prev = l == 1 ? 0 : get(1,1,n,l-1,r-1); // dp[k] la chi phi tu 1 den k, ly do get tu l-1 den r-1 de tim mot k ma dp[k] ton tai
        if (prev != LLINF) {
            if (dp[r] > prev + x) {
                dp[r] = prev + x;
                update(1,1,n,r,dp[r]);
            }
        }
    }
    cout << (dp[n] >= LLINF ? -1 : dp[n]);
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
