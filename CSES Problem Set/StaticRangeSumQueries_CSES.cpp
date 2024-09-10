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

#define int long long

const int N = 2e5+7;
int n,q, a[N], t[4*N];

void build(int id, int l, int r) {
    if (l == r) return t[id] = a[l], void();
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id] = t[id*2] + t[id*2+1];
}

ll get(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return t[id];
    int mid = (l+r)/2;
    ll t1 = get(id*2,l,mid,u,v);
    ll t2 = get(id*2+1,mid+1,r,u,v);
    return t1+t2;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(name ".inp", "r")) {
        freopen(name ".inp","r",stdin);
        freopen(name ".out","w",stdout);
    }
    cin >> n >> q;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1,1,n);
    while(q--) {
        int x,y;
        cin >> x >> y;
        cout << get(1,1,n,x,y) << endl;
    }
    return 0;
}
