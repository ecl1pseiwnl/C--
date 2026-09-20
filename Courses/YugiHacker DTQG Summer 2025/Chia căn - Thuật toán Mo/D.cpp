#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
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

const int N = 25e4+7,maxb = 2005, bl = 205,maxv = 5e4+7;
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

ll calc(int l, int r) {
    if (l > r) return 0;
    return getb(r) - getb(l-1);
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
    cout.tie(nullptr);
    cin >> n;
    REP(i,n) {
        cin >> v[i];
        ans += calc(v[i]+1,maxv-1);
        sz[i/maxb]++;
        updatef(v[i],i/maxb,1);
        updateb(v[i],1);
    }
    cin >> q;
    while(q--) {
        int pos,x;
        cin >> pos >> x;
        pos--;
        int curb = pos/maxb;
        for (int i = curb*maxb; i < pos; i++) ans -= v[i] > v[pos];
        for (int i = pos+1; i < min(n,(curb+1)*maxb); i++) ans -= v[i] < v[pos];
        for(int i = 0; i < curb; i++) {
            if (sz[i]) ans -= sz[i] - getf(v[pos],i);
        }
        for(int i = curb+1; i < bl; i++) ans -= getf(v[pos]-1,i);
        updatef(v[pos],curb,-1);
        v[pos] = x;
        for (int i = curb*maxb; i < pos; i++) ans += v[i] > v[pos];
        for (int i = pos+1; i < min(n,(curb+1)*maxb); i++) ans += v[i] < v[pos];
        for(int i = 0; i < curb; i++) {
            if (sz[i]) ans += sz[i] - getf(v[pos],i);
        }
        for(int i = curb+1; i < bl; i++) ans += getf(v[pos]-1,i);
        updatef(v[pos],curb,1);
        cout << ans << "\n";
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
