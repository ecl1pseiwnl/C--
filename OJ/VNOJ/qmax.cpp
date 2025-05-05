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
const double PI = 3.141592653589793238463;
#define bmask(x,i) (((x) >> (i)) & 1)
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
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
ll __lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
const int EPS = -1e9;
constexpr int MOD = 1e9+7;
constexpr int32_t IINF = 0x3f3f3f3f;
constexpr int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 5e4+7;
int n,m,k,t[4*N];
ll a[N];

void build(int id, int l, int r) {
	if (l == r) {
		return t[id] = a[l], void();
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	t[id] = max(t[id * 2], t[id * 2 + 1]);
}

int get(int id, int l, int r,int u, int v) {
	if (r < u || l > v) return 0;
	if (u <= l && r <= v) return t[id];
	int mid = (l + r) / 2;
	int t1 = get(id * 2, l, mid, u, v);
	int t2 = get(id * 2 + 1, mid + 1, r, u, v);
	return max(t1,t2);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        a[x] += z;
        a[y+1] -= z;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = a[i-1] + a[i];
    }
    build(1,1,n);
    cin >> k;
    while(k--) {
        int l,r;
        cin >> l >> r;
        cout << get(1,l,r,1,n) << endl;
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
