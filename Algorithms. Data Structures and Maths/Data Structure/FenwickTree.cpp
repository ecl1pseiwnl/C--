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

const int N = 1e5+7;
int n, a[N], bit[N];

void update(int pos, int val) {
    for (; pos <= n; pos += pos & (-pos)) {
        bit[pos] += val;
        /// max, min, gcd
        //bit[pos] = min(bit[pos], val);
    }
}

// Update on range, get value of a position
void updateRange(int l, int r, int val) {
	update(l, val);
	update(r + 1, -val);
}

int query(int pos) {
    int s = 0;
    for (; pos >= 1; pos -= pos & (-pos)) {
        s += bit[pos];
        /// max, min, gcd
        //s = min(s,bit[pos]);
    }
    return s;
}

// Update on range, get value on range
int bitAdd[N], bitMul[N];

void updateBIT(int bit[], int x, int val) {
	for (; x <= n; x += x & -x) bit[x] += val;
}

int getBIT(int bit[], int x) {
	int res = 0;
	for (; x >= 1; x &= x - 1) res += bit[x];
	return res;
}

void updateRange2(int l, int r, int val) {
    updateBIT(bitMul,l,val);
    updateBIT(bitMul,r+1,-val);
    updateBIT(bitAdd,l,-val*(l-1));
    updateBIT(bitAdd,r+1,val*r);
}

int getPre(int x) {
    return getBit(bitMul,x) * x + getBIT(bitAdd,x);
}

int getSum(int l, int r) {
    return getPre(r) - getPre(l-1);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i,a[i]);
    }
    cout << query(7);
    return 0;
}
