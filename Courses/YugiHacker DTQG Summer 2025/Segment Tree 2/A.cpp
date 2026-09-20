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
ll t[4*N], lazy[4*N];

ll mul(ll x, ll y) {
    return (x%MOD*y%MOD)%MOD;
}

void push(int id, int l, int r) {
    if (lazy[id] != 1) {
        t[id] = mul(t[id],lazy[id]);
        if (l != r) {
            lazy[id<<1] = mul(lazy[id<<1],lazy[id]);
            lazy[id<<1|1] = mul(lazy[id<<1|1],lazy[id]);
        }
        lazy[id] = 1;
    }
}

void build(int id, int l, int r) {
    lazy[id] = 1;
    if (l == r) {
        t[id] = 1;
        return;
    }
    int m = l+r>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    t[id] = (t[id<<1] + t[id<<1|1]) % MOD;
}

void update(int id, int l, int r, int x, int y, ll w) {
    push(id,l,r);
    if (y < l || x > r || l > r) return;
    if (l >= x && r <= y) {
        lazy[id] = mul(lazy[id],w);
        push(id,l,r);
        return;
    }
    int m = l+r>>1;
    update(id<<1,l,m,x,y,w);
    update(id<<1|1,m+1,r,x,y,w);
    t[id] = (t[id<<1] + t[id<<1|1]) % MOD;
}

ll get(int id, int l, int r, int x, int y) {
    push(id,l,r);
    if (y < l || x > r || l > r) return 0;
    if (l >= x && r <= y) return t[id];
    int m = l+r>>1;
    return (get(id<<1,l,m,x,y)%MOD + get(id<<1|1,m+1,r,x,y)%MOD)%MOD;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    build(1,1,n);
    while(q--) {
        int ty,x,y;
        ll k;
        cin >> ty >> x >> y;
        if (ty == 1) {
            cin >> k;
            update(1,1,n,x,y,k);
        } else {
            cout << get(1,1,n,x,y) << endl;
        }
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
