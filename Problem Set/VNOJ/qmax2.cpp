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
int n,q,t[4*N],lazy[4*N];

void update(int id, int l, int r, int x, int y, int val) {
    if (l > r || x < l || r < y) return;
    if (l == x && r == y) {
        t[id] += val;
        lazy[id] += val;
        return;
    }
    int m = (l+r)/2;
    if (lazy[id]) {
        t[2*id] += lazy[id];
        t[2*id+1] += lazy[id];
        lazy[2*id] += lazy[id];
        lazy[2*id+1] += lazy[id];
        lazy[id] = 0;
    }
    update(2*id,l,m,x,y,val);
    update(2*id+1,m+1,r,x,y,val);
    t[id] = max(t[2*id],t[2*id+1]);
}

int get(int id, int l, int r, int x, int y) {
    if (x < l || r < y || l > r) return 0;
    if (l == x && r == y) return t[id];
    int m = (l+r)/2;
    if (lazy[id]) {
        t[2*id] += lazy[id];
        t[2*id+1] += lazy[id];
        lazy[2*id] += lazy[id];
        lazy[2*id+1] += lazy[id];
        lazy[id] = 0;
    }
    return max(get(2*id,l,m,x,y),get(2*id+1,m+1,r,x,y));
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    while(q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int x,y,z;
            cin >> x >> y >> z;
            update(1,1,n,x,y,z);
        } else {
            int x,y;
            cin >> x >> y;
            cout << get(1,1,n,x,y) << " ";
        }
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
