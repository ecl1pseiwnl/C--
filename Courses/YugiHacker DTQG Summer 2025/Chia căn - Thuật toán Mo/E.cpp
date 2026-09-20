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

struct Q{
    int l,r,id;
};
const int N = 1e5+7,sz = 322;
int n,w[N],st[N],en[N],d[2*N],cnt,cur[N],ans;
Q qu[N];
vi v[N],res(N,0);

void dfs(int u, int par) {
    st[u] = ++cnt;
    d[cnt] = w[u];
    for (auto it : v[u]) {
        if (it == par) continue;
        dfs(it,u);
    }
    en[u] = cnt;
}

bool cmp(const Q &a, const Q &b) {
    if (a.l/sz == b.l/sz) {
        if ((a.l/sz)&1) {
            return a.r < b.r;
        } else return a.r > b.r;
    }
    return a.l < b.l;
}

void del(int x) {
    if (--cur[x] == 0) ans--;
}

void add(int x) {
    if (cur[x]++ == 0) ans++;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    FOR(i,2,n) {
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    FOR(i,1,n) {
        cin >> w[i];
    }
    dfs(1,-1);
    FOR(i,1,n) {
        qu[i].l = st[i];
        qu[i].r = en[i];
        qu[i].id = i;
    }
    sort(qu+1,qu+n+1,cmp);
    int l = 1, r = 0;
    FOR(i,1,n) {
        while(l < qu[i].l) del(d[l++]);
        while(l > qu[i].l) add(d[--l]);
        while(r > qu[i].r) del(d[r--]);
        while(r < qu[i].r) add(d[++r]);
        res[qu[i].id] = ans - (cur[0] > 0 ? cur[0] : 0);
    }
    FOR(i,1,n) {
        cout << res[i] << "\n";
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
