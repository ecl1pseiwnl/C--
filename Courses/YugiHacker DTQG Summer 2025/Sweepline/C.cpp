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
constexpr double EPS = 1e-9;

const int N = 3e5+7;
int n,ans,bit[N];
struct point {
    double x;
    int t,y1,y2;
};
bool cmp(point a, point b) {
    return a.x < b.x;
}
double fx1[N],fx2[N],fy[N],sy1[N],sy2[N],sx[N];
vector<double> u;
vector<point> v;



void update(int pos, int val) {
    for(;pos<=N;pos+=pos&-pos) bit[pos] += val;
}

int get(int pos) {
    int ans = 0;
    for(;pos>=1;pos-=pos&-pos) ans += bit[pos];
    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    FOR(i,1,n) {
        cin >> fx1[i] >> fx2[i] >> fy[i];
        if (fx1[i] > fx2[i]) swap(fx1[i],fx2[i]);
        u.pb(fy[i]);
    }
    FOR(i,1,n) {
        cin >> sy1[i] >> sy2[i] >> sx[i];
        if (sy1[i] > sy2[i]) swap(sy1[i],sy2[i]);
        u.pb(sy1[i]);
        u.pb(sy2[i]);
    }
    sort(all(u));
    u.resize(unique(all(u))-u.begin());
    FOR(i,1,n) {
        int y = lower_bound(all(u),fy[i])-u.begin()+1;
        v.pb({fx1[i]-EPS,1,y,0});
        v.pb({fx2[i]+EPS,3,y,0});
    }
    FOR(i,1,n) {
        int y1 = lower_bound(all(u),sy1[i])-u.begin()+1;
        int y2 = lower_bound(all(u),sy2[i])-u.begin()+1;
        v.pb({sx[i],2,y1,y2});
    }
    sort(all(v),cmp);
    for (auto it : v) {
        if (it.t == 1) {
            update(it.y1,1);
        } else if (it.t == 3) {
            update(it.y1,-1);
        } else ans += get(it.y2) - get(it.y1-1);
    }
    cout << ans;
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
