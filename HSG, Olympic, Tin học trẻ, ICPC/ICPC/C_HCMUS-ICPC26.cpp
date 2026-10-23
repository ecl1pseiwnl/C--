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
template <class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        }
        return false;
    }
template <class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        }
        return false;
    }
constexpr int MOD = 1e9+7;
constexpr int IINF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 2e5+7, M = 5;
int n,q,v[N];
struct Node{
    ll sum_id = 0;
    ll sum_f = 0;
    ll sum_nextf = 0;
};

struct mat{
    int n,m;
    ll a[M][M];
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
                    ans.a[i][k] = (ans.a[i][k] + 1ll * a[i][j] * d.a[j][k]) % MOD;
                }
            }
        }
        return ans;
    }
    mat operator ^ (long long k) const {
        mat ans(n, n);
        REP(i,n) ans.a[i][i] = 1;
        mat mul = *this;
        while (k > 0) {
            if (k & 1) ans = ans * mul;
            mul = mul * mul;
            k >>= 1;
        }
        return ans;
    }
};

mat calcmat(ll k) {
    mat cur(2,2);
    cur.a[0][0] = 1;
    cur.a[0][1] = 1;
    cur.a[1][0] = 1;
    cur.a[1][1] = 0;
    return cur ^ k;
}

ll fib(ll k) {
    return calcmat(k).a[1][0];
}

Node t[4*N];
mat lazy[4*N];
bool islazy[4*N];

Node Merge(Node a, Node b) {
    Node ans;
    ans.sum_id = a.sum_id + b.sum_id;
    ans.sum_f = (a.sum_f + b.sum_f) % MOD;
    ans.sum_nextf = (a.sum_nextf + b.sum_nextf) % MOD;
    return ans;
}

void apply(int id, mat& M) {
    ll nf  = (M.a[1][0] * t[id].sum_nextf + M.a[1][1] * t[id].sum_f) % MOD;
    ll n_nextf = (M.a[0][0] * t[id].sum_nextf + M.a[0][1] * t[id].sum_f) % MOD;
    t[id].sum_f  = nf;
    t[id].sum_nextf = n_nextf;
}

void build(int id, int l, int r) {
    lazy[id] = mat(2, 2);
    lazy[id].a[0][0] = lazy[id].a[1][1] = 1;
    islazy[id] = false;
    if (l == r) {
        t[id].sum_f  = fib(v[l]);
        t[id].sum_nextf = fib(v[l] + 1);
        return;
    }
    int m = (l+r)>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    t[id] = Merge(t[id<<1],t[id<<1|1]);
}

void push(int id) {
    if (!islazy[id]) return;
    apply(id<<1,lazy[id]);
    lazy[id<<1] = lazy[id]*lazy[id<<1];
    islazy[id<<1] = 1;
    apply(id <<1|1,lazy[id]);
    lazy[id<<1|1] = lazy[id]*lazy[id<<1|1];
    islazy[id<<1|1] = 1;
    lazy[id] = mat(2, 2);
    lazy[id].a[0][0] = lazy[id].a[1][1] = 1;
    islazy[id] = 0;
}

void update(int id, int l, int r, int x, int y, ll k) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        mat M = calcmat(k);
        apply(id,M);
        lazy[id] = M*lazy[id];
        islazy[id] = true;
        return;
    }
    push(id);
    int m = (l+r)>>1;
    update(id<<1,l,m,x,y,k);
    update(id<<1|1,m+1,r,x,y,k);
    t[id] = Merge(t[id<<1], t[id<<1|1]);
}

ll get(int id, int l, int r, int x, int y) {
    if (l > y || r < x) return 0;
    if (x <= l && r <= y) return t[id].sum_f;
    push(id);
    int m = (l+r)>>1;
    return (get(id<<1,l,m,x,y) + get(id<<1|1,m+1,r,x,y)) % MOD;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    FOR(i,1,n) {
        cin >> v[i];
    }
    build(1,1,n);
    while(q--) {
        int t,l,r,x;
        cin >> t >> l >> r;
        if (t == 1) {
            cin >> x;
            update(1,1,n,l,r,x);
        } else {
            cout << get(1,1,n,l,r) << endl;
        }
    }

    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}

