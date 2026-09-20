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
template <class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        }
        return false;
    }
template <class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        }
        return false;
    }
constexpr int MOD = 1e9+7;
constexpr int IINF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 4e5+7;
ll bit[2*N];
int n,q;
vi v,compress;
vector<array<int,3>> qu;

void update(int pos, int val) {
    for (;pos<= N; pos += pos & (-pos)) {
        bit[pos] += val;
    }
}

ll get(int pos) {
    ll ans = 0;
    for (; pos; pos -= pos & (-pos)) {
        ans += bit[pos];
    }
    return ans;
}

void add(int a, int b) {
    int pos = upper_bound(all(compress),a) - compress.begin();
    update(pos,b);
}

ll calc(int x) {
    int pos = upper_bound(all(compress),x) - compress.begin();
    return get(pos);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    v.resize(n+2);
    FOR(i,1,n) {
        cin >> v[i];
    }
    compress = v;
    FOR(i,1,q) {
        char c;
        int a,b;
        cin >> c >> a >> b;
        qu.pb({c=='?',a,b});
        if (c == '!') compress.pb(b);
    }
    sort(all(compress));
    compress.erase(unique(all(compress)),compress.end());
    FOR(i,1,n) {
        add(v[i],1);
    }
    for (auto it : qu) {
        if (it[0] == 0) {
            add(v[it[1]],-1);
            v[it[1]] = it[2];
            add(v[it[1]],1);
        } else cout << calc(it[2]) - calc(it[1]-1) << endl;
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
