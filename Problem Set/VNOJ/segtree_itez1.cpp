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
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
constexpr int MOD = 1e9+7;
constexpr int32_t IINF = 0x3f3f3f3f;
constexpr int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

#define int long long
const int N = 1e5+7;
int n, q, a[N], ma[4*N];

void build(int id, int l, int r) {
    if (l == r) {
        ma[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    ma[id] = max(ma[id*2], ma[id*2+1]);
}

int get(int id, int l, int r,int u, int v) {
	if (r < u || l > v) return INT_MIN;
	if (u <= l && r <= v) return ma[id];
	int mid = (l + r) / 2;
	int t1 = get(id * 2, l, mid, u, v);
    int t2 = get(id * 2 + 1, mid + 1, r, u, v);
	return max(t1, t2);
}

void update(int id, int l, int r, int p, int val) {
	if (p < l || p > r) return;
	if (l == r) {
        ma[id] = val;
        return;
	}
	int mid = (l + r) / 2;
	update(id * 2, l, mid, p, val);
	update(id * 2 + 1, mid + 1, r, p, val);
	ma[id] = max(ma[id*2],ma[id*2+1]);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(name ".inp", "r")) {
        freopen(name ".inp","r",stdin);
        freopen(name ".out","w",stdout);
    }
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    cin >> q;
    while(q--) {
        int x,y,z;
        cin >> x >> y >> z;
        if (x == 2) {
            cout << get(1,1,n,y,z) << "\n";
        } else if (x == 1) {
            update(1,1,n,y,z);
        }
    }
    return 0;
}
