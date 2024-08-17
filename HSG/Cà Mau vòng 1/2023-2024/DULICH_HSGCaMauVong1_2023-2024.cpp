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
ll __lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
const int MOD = 1e9+7;
const int32_t IINF = 0x3f3f3f3f;
const int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

struct edge{
    int x,y;
};

const int N = 1e5+7;
int n,m,q, par[N], sz[N], visited[N];
vector<edge> v;
vi ans;

void makeset() {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find_set(int u) {
    if (u == par[u]) return u;
    int p = find_set(par[u]);
    return p;
}

void Union(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        edge e;
        e.x = x;
        e.y = y;
        v.ep(e);
    }
    makeset();
    for (int i = 0; i < m; i++) {
        edge e = v[i];
        Union(e.x,e.y);
    }
    for (int i = 1; i <= n; i++) {
        int x = find_set(i);
        if(!visited[x]) {
            visited[x] = 1;
            ans.ep(sz[x]);
        }
    }
    sort(all(ans),greater<int>());
    while(q--) {
        int x, i = 0; cin >> x;
        ll s = 0;
        for (auto it : ans) {
            s += it;
            if (s >= x) {
                cout << i << " ";
                break;
            }
            i++;
        }
    }
    return 0;
}

