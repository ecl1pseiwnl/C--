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

const int N = 3e5+7;
int n,q;
int pos[N],cnt,chain,h[N],sz[N],heavy[N],head[N],id[N],par[N];
ll t[N<<2], lazy[N<<2];
vi v[N];

void dfs(int u, int p) {
    sz[u] = 1;
    for (auto it : v[u]) {
        if (it == p) continue;
        par[it] = u;
        h[it] = h[u] + 1;
        dfs(it,u);
        sz[u] += sz[it];
    }
}

void hld(int u, int p) {
    if (!head[chain]) head[chain] = u;
    id[u] = chain;
    pos[u] = cnt;
    cnt++;
    int nxt = 0;
    for (auto it : v[u]) {
        if (it == p) continue;
        if (!nxt || sz[it] > sz[nxt]) nxt = it;
    }
    if (nxt) hld(nxt,u);
    for (auto it : v[u]) {
        if (it == p || it == nxt) continue;
        chain++;
        hld(it,u);
    }
}

int lca(int x, int y) {
    while(id[x] != id[y]) {
        if (h[head[id[x]]] < h[head[id[y]]]) swap(x,y);
        x = par[head[id[x]]];
    }
    return (h[x] < h[y] ? x : y);
}

void push(int id, int l, int r) {
    if (lazy[id]) {
        t[id] += lazy[id];
        if (l != r) {
            lazy[id<<1] += lazy[id];
            lazy[id<<1|1] += lazy[id];
        }
        lazy[id] = 0;
    }
}

void update(int id, int l, int r, int x, int y, int val) {
    push(id,l,r);
    if (y < l || x > r) return;
    if (l >= x && r <= y) {
        lazy[id] += val;
        push(id,l,r);
        return;
    }
    int m = l+r>>1;
    update(id<<1,l,m,x,y,val);
    update(id<<1|1,m+1,r,x,y,val);
    t[id] = max(t[id<<1],t[id<<1|1]);
}

ll get(int id, int l, int r, int x, int y) {
    push(id,l,r);
    if (l > y || r < x) return -LLINF;
    if (l >= x && r <= y) return t[id];
    int m = l+r>>1;
    return max(get(id<<1,l,m,x,y),get(id<<1|1,m+1,r,x,y));
}

ll ma(int x, int y) {
    ll ans = -LLINF;
    while(id[x] != id[y]) {
        if (h[head[id[x]]] < h[head[id[y]]]) swap(x,y);
        ans = max(ans, get(1,1,n,pos[head[id[x]]],pos[x]));
        x = par[head[id[x]]];
    }
    if (h[x] > h[y]) swap(x,y);
    ans = max(ans,get(1,1,n,pos[x],pos[y]));
    return ans;
}

void up(int x, int y, ll val) {
    while(id[x] != id[y]) {
        if (h[head[id[x]]] < h[head[id[y]]]) swap(x,y);
        update(1,1,n,pos[head[id[x]]],pos[x],val);
        x = par[head[id[x]]];
    }
    if (h[x] > h[y]) swap(x,y);
    update(1,1,n,pos[x],pos[y],val);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    FOR(i,2,n) {
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    cnt = chain = 1;
    dfs(1,-1);
    hld(1,-1);
    while(q--) {
        int ty,x,y;
        ll val;
        cin >> ty;
        if (ty == 1) {
            cin >> x >> y >> val;
            up(x,y,val);
        } else if (ty == 2) {
            cin >> x >> val;
            update(1,1,n,pos[x],pos[x]+sz[x]-1,val);
        } else if (ty == 3) {
            cin >> x >> y;
            cout << ma(x,y) << endl;
        } else {
            cin >> x;
            cout << get(1,1,cnt-1,pos[x],pos[x]+sz[x]-1) << endl;
        }
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
