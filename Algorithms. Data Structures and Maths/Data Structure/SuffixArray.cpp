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
#define BIT(x,i) (((x) >> (i)) & 1)
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

const int N = 1e5+7, lg = 22;
int n, suf[N],p[lg][N],pw[lg];
// suf: mang Suffix Array luu chi so hau to sau khi sort tang
// p[k][i] la thu hang hau to thu i sau sort tang theo prefix co do dai 2^k
// pw[i] luu 2^i
string s;

struct suffix {
    // pos: vi tri cua hau to
    // ft: vi tri dau tien cua hau to
    // nt: vi tri thu 2^k-1 ki tu tiep theo ngay sau prefix co do dai 2^k-1
    int pos, ft, nt;
    bool operator < (suffix const& x) const {
        if (ft != x.ft) return ft < x.ft;
        return nt < x.nt;
    }
    bool operator == (suffix const& x) const {
        if (ft != x.ft) return 0;
        return nt == x.nt;
    }
} l[N];

// Cho S gom cac chu cai in thuong co do dai khong qua 10^5. Hay tim mang hau to tuong ung cua S.

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    pw[0] = 1;
    for (int i = 1; i <= lg; i++) pw[i] = (1<<i);
    cin >> s;
    n = s.size();
    REP(i,n) {
        p[0][i] = s[i]-'a';
    }
    for (int j = 1; pw[j] < n; j++) {
        REP(i,n) {
            l[i].ft = p[j-1][i];
            l[i].nt = (i + pw[j-1] < n ? p[j-1][i+pw[j-1]] : -1);
            l[i].pos = i;
        }
        sort(l,l+n);
        REP(i,n) {
            p[j][l[i].pos] = (i > 0 && l[i-1] == l[i] ? p[j][l[i-1].pos] : i);
        }
    }
    REP(i,n)
        cout << l[i].pos << " ";
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
