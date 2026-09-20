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

const int N = 5007;
int n,m,bit[N][N];

// Point Query
void add(int u, int v, int x){
    for(int i = u; i <= n; i += i&(-i)) {
        for(int j = v; j <= m; j += j&(-j)) {
            bit[i][j]+=x;
        }
    }
}

void rectAdd(int l, int r, int u, int v, int val){
    add(l, r, val);
    add(u+1, v+1, val);
    add(u+1, r, -val);
    add(l, v+1, -val);
}

int query(int u, int v){
    int sum = 0;
    for(int i = u; i > 0; i -= i&(-i)) {
        for(int j = v; j > 0; j -= j&(-j)) {
            sum += BIT[i][j];
        }
    }
    return sum;
}

// Rectangle Query
int BIT[4][N][M];

void add(int u, int v, int x){
    for(int i = u; i <= n; i += i&(-i)) {
        for(int j = v; j <= m; j += j&(-j)) {
            bit[0][i][j] += x;
            bit[1][i][j] += u*x;
            bit[2][i][j] += v*x;
            bit[3][i][j] += u*v*x;
        }
    }
}

void rectAdd(int l, int r, int u, int v, int val){
    add(l, r, val);
    add(u+1, v+1, val);
    add(u+1, r, -val);
    add(l, v+1, -val);
}

int query(int u, int v){
    int a[4] = {0,0,0,0};
    for(int k = 0; k < 4; k++){
        for(int i = x; i > 0; i -= i&(-i)){
            for(int j = y; j > 0; j -= j&(-j)){
                a[k] += BIT[k][i][j];
            }
        }
    }
    return a[0]*(u+1)*(v+1)-a[1]*(v+1)-a[2]*(u+1)+a[3];
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
