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

const int N = 1e6+7;
int n,q,v[N], mi[N<<2],cur;
ll t[N<<2];

void update(int id, int l, int r, int pos, int x) {
    if (pos < l || pos > r) return;
    if (l == r) {
        mi[id] = l;
        t[id] = v[l] = x;
        return void();
    }
    int m = l+r>>1;
    update(id<<1,l,m,pos,x);
    update(id<<1|1,m+1,r,pos,x);
    mi[id] = (v[mi[id<<1]] <= v[mi[id<<1|1]] ? mi[id<<1] : mi[id<<1|1]);
    t[id] = t[id<<1] + t[id<<1|1];
}

ll sum(int id, int l, int r, int x, int y) {
    if (l > y || r < x) return 0;
    if (l >= x && r <= y) return t[id];
    int m = l+r>>1;
    return sum(id<<1,l,m,x,y) + sum(id<<1|1,m+1,r,x,y);
}

int minv(int id, int l, int r, int x, int y) {
    if (l > y || r < x) return 0;
    if (l >= x && r <= y) return mi[id];
    int m = l+r>>1;
    int t1 = minv(id<<1,l,m,x,y);
    int t2 = minv(id<<1|1,m+1,r,x,y);
    return (v[t1] <= v[t2] ? t1 : t2);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    v[0] = 0x3f3f3f3f;
    cin >> n >> q;
    FOR(i,1,n) {
        cin >> v[i];
        update(1,1,n,i,v[i]);
    }
    while(q--) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int d;
            cin >> d;
            cur += d;
            if (cur > n) cur %= n;
        } else if (ty == 2) {
            int l,r,x;
            cin >> l >> r >> x;
            l -= cur;
            r -= cur;
            if (l <= 0) l += n;
            if (r <= 0) r += n;
            if (l <= r) {
                int k = minv(1,1,n,l,r);
                update(1,1,n,k,x);
            } else {
                int t1 = minv(1,1,n,l,n);
                int t2 = minv(1,1,n,1,r);
                if (v[t1] <= v[t2]) {
                    update(1,1,n,t1,x);
                } else update(1,1,n,t2,x);
            }
        } else if (ty == 3) {
            int l,r;
            cin >> l >> r;
            l -= cur;
            r -= cur;
            if (l <= 0) l += n;
            if (r <= 0) r += n;
            cout << (l <= r ? sum(1,1,n,l,r) : sum(1,1,n,l,n) + sum(1,1,n,1,r)) << endl;
        }
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
