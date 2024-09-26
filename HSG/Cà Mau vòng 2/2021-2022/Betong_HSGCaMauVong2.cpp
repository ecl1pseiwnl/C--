#include bitsstdc++.h
using namespace std;
void __print(int x) {cerr  x;}
void __print(long x) {cerr  x;}
void __print(long long x) {cerr  x;}
void __print(unsigned x) {cerr  x;}
void __print(unsigned long x) {cerr  x;}
void __print(unsigned long long x) {cerr  x;}
void __print(float x) {cerr  x;}
void __print(double x) {cerr  x;}
void __print(long double x) {cerr  x;}
void __print(char x) {cerr  '''  x  ''';}
void __print(const char x) {cerr  ''  x  '';}
void __print(const string &x) {cerr  ''  x  '';}
void __print(bool x) {cerr  (x  true  false);}
templatetypename T, typename V
void __print(const pairT, V &x) {cerr  '{'; __print(x.first); cerr  ','; __print(x.second); cerr  '}';}
templatetypename T
void __print(const T &x) {int f = 0; cerr  '{'; for (auto &i x) cerr  (f++  ,  ), __print(i); cerr  };}
void _print() {cerr  ]n;}
template typename T, typename... V
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr  , ; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr  [  #x  ] = [; _print(x)
#else
#define debug(x...)
#endif
typedef long long ll;
typedef pairint,int pi;
typedef mapint,int mii;
typedef vectorint vi;
typedef vectorpi vii;
typedef vectormii viii;
ll __lcm(ll x, ll y) { return 1ll(x  __gcd(x,y))y;}
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define ins insert
#define sz(x) (int)(x.size())
#define name TASK
#define fi first
#define sec second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl n
const int MOD = 1e9+7;
const int32_t IINF = 0x3f3f3f3f;
const int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

signed main() {
    cin.tie(NULL)-sync_with_stdio(false);
    if (fopen(name .inp, r)) {
        freopen(name .inp,r,stdin);
        freopen(name .out,w,stdout);
    }
    int n, ans = -IINF;
    cin  n;
    vi v(n);
    for (auto &it  v) cin  it;
    setint s(all(v));
    for (auto it  s) {
        bool tf = false;
        int cnt = 0;
        for (auto x  v) {
            if (x  it) {
                if (!tf) {
                    tf = true;
                    cnt++;
                }
            } else {
                tf = false;
            }
        }
        ans = max(ans,cnt);
    }
    cout  ans;
    return 0;
}
