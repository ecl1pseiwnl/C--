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

const ll N = 2e5+7;
ll n,q, t[N*4], v[N];

void build(ll id, ll l, ll r) {
    if (l == r) {
        return t[id] = v[l], void();
    }
    ll m = (l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id] = t[id*2] + t[id*2+1];
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    if (r < u || l > v) return 0;
    if (u <= l && r <= v ) return t[id];
    ll m = (l+r)/2;
    ll t1 = get(id*2,l,m,u,v);
    ll t2 = get(id*2+1,m+1,r,u,v);
    return t1+t2;
}

void update(ll id, ll l, ll r, ll k, ll p) {
    if (k < l || k > r) return;
    if (l == r) {
        t[id] = p;
        v[l] = p;
        return;
    }
    ll m = (l+r)/2;
    update(id*2,l,m,k,p);
    update(id*2+1,m+1,r,k,p);
    t[id] = t[id*2] + t[id*2+1];
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(name ".inp", "r")) {
        freopen(name ".inp","r",stdin);
        freopen(name ".out","w",stdout);
    }
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    build(1,1,n);
    while(q--) {
        ll t,a,b;
        cin >> t >> a >> b;
        if (t == 1) {
            update(1,1,n,a,b);
        } else if (t == 2) {
            cout << get(1,1,n,a,b) << endl;
        }
    }
    return 0;
}
