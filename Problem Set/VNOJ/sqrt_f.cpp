#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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

const int N = 2.5e5+7,bl = 505,maxv = 5e4+7;
int n,q,v[N];
ll bit[maxv],fen[bl][maxv],sz[bl],ans;

void updateb(int pos,ll val) {
    for (;pos<maxv;pos+=pos&-pos) bit[pos] += val;
}

ll getb(int pos) {
    ll ans = 0;
    for(;pos;pos-=pos&-pos) ans += bit[pos];
    return ans;
}

void updatef(int pos,int cur,ll val) {
    for (;pos<maxv;pos+=pos&-pos) fen[cur][pos] += val;
}

ll getf(int pos,int cur) {
    ll ans = 0;
    for(;pos;pos-=pos&-pos) ans += fen[cur][pos];
    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    REP(i,n) {
        cin >> v[i];
        sz[i/bl]++;
        updatef(v[i],i/bl,1);
        ans += getb(maxv-1)-getb(v[i]);
        updateb(v[i],1);
    }
    cin >> q;
    while(q--) {
        int pos,x;
        cin >> pos >> x;
        pos--;
        int curb = pos/bl;
        for (int i = curb*bl; i < pos; i++) ans -= v[i] > v[pos];
        for (int i = pos+1; i < min(n,(curb+1)*bl); i++) ans -= v[i] < v[pos];
        for(int i = 0; i < curb; i++) {
            if (sz[i]) ans -= sz[i] - getf(v[pos],i);
        }
        for(int i = curb+1; i < bl; i++) ans -= getf(v[pos]-1,i);
        updatef(v[pos],curb,-1);
        v[pos] = x;
        for (int i = curb*bl; i < pos; i++) ans += v[i] > v[pos];
        for (int i = pos+1; i < min(n,(curb+1)*bl); i++) ans += v[i] < v[pos];
        for(int i = 0; i < curb; i++) {
            if (sz[i]) ans += sz[i] - getf(v[pos],i);
        }
        for(int i = curb+1; i < bl; i++) ans += getf(v[pos]-1,i);
        updatef(v[pos],curb,1);
        cout << ans << endl;
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
