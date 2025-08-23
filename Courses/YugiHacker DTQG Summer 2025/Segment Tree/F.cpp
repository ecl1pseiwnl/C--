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

#define int ll
const int N = 2e5+7;
int n,q;
ll t[4*N], v[N];
pair<ll,ll> lazy[4*N];

void build(int id, int l, int r) {
    if (l == r) {
        return t[id] = v[l], void();
    }
    int m = l+r>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    t[id] = t[id<<1] + t[id<<1|1];
}

void app(int id, int l, int r, ll a, ll b) {
    int len = r-l+1;
    // (a * (r + l) * (r - l + 1) / 2) + (b * (r - l + 1))
    t[id] += a*(r+l)*len/2+b*len;
    lazy[id].fi += a;
    lazy[id].se += b;
}

void push(int id, int l, int r) {
    if (lazy[id].fi != 0 || lazy[id].se != 0) {
        int m = l+r>>1;
        app(id<<1,l,m,lazy[id].fi,lazy[id].se);
        app(id<<1|1,m+1,r,lazy[id].fi,lazy[id].se);
        lazy[id] = {0,0};
    }
}

void update(int id, int l, int r, int x, int y, ll a, ll b) {
    if (y < l || x > r || l > r) return;
    if (l >= x && r <= y) {
        app(id,l,r,a,b);
        return;
    }
    push(id,l,r);
    int m = l+r>>1;
    update(id<<1,l,m,x,y,a,b);
    update(id<<1|1,m+1,r,x,y,a,b);
    t[id] = t[id<<1] + t[id<<1|1];
}

ll get(int id, int l, int r, int x, int y) {
    if (y < l || x > r || l > r) return 0;
    if (l >= x && r <= y) return t[id];
    push(id,l,r);
    int m = l+r>>1;
    return get(id<<1,l,m,x,y) + get(id<<1|1,m+1,r,x,y);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    FOR(i,1,n) {
        cin >> v[i];
    }
    build(1,1,n);
    cin >> q;
    while(q--) {
        int ty,l,r;
        cin >> ty >> l >> r;
        if (ty == 1) {
            update(1,1,n,l,r,1,1-l);
        } else cout << get(1,1,n,l,r) << endl;
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
