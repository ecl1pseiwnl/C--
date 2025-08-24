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
int n,q,w[N];
int node[N],pos[N],cnt,chain,h[N],sz[N],heavy[N],head[N],id[N],par[N];
int t[N<<2];
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
    node[cnt] = w[u];
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
        if (id[x] > id[y]) {
            x = par[head[id[x]]];
        } else {
            y = par[head[id[y]]];
        }
    }
    return (h[x] < h[y] ? x : y);
}

void build(int id, int l, int r) {
    if (l == r) return t[id] = node[l], void();
    int m = l+r>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    t[id] = max(t[id<<1],t[id<<1|1]);
}

void update(int id, int l, int r, int coord, int val) {
    if (coord < l || coord > r) return;
    if (l == r) return t[id] = val, void();
    int m = l+r>>1;
    update(id<<1,l,m,coord,val);
    update(id<<1|1,m+1,r,coord,val);
    t[id] = max(t[id<<1],t[id<<1|1]);
}

int get(int id, int l, int r, int x, int y) {
    if (l > y || r < x) return -IINF;
    if (l >= x && r <= y) return t[id];
    int m = l+r>>1;
    return max(get(id<<1,l,m,x,y),get(id<<1|1,m+1,r,x,y));
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    FOR(i,1,n) {
        cin >> w[i];
    }
    FOR(i,2,n) {
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    cnt = chain = 1;
    dfs(1,-1);
    hld(1,-1);
    build(1,1,cnt-1);
    while(q--) {
        int ty,x,y;
        cin >> ty >> x >> y;
        if (ty == 1) {
            update(1,1,cnt-1,pos[x],y);
            w[x] = y;
        } else {
            int root = lca(x,y);
            int ans = -IINF;
            while(id[x] != id[root]) {
                ans = max(ans,get(1,1,cnt-1,pos[head[id[x]]],pos[x]));
                x = par[head[id[x]]];
            }
            while(id[y] != id[root]) {
                ans = max(ans,get(1,1,cnt-1,pos[head[id[y]]],pos[y]));
                y = par[head[id[y]]];
            }
            if (h[x] < h[y]) {
                ans = max(ans,get(1,1,cnt-1,pos[x],pos[y]));
            } else ans = max(ans,get(1,1,cnt-1,pos[y],pos[x]));
            cout << ans << endl;
        }
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
