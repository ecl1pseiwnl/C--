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
ll __lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
const int MOD = 1e9+7;
const int32_t IINF = 0x3f3f3f3f;
const int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5+7;
int n,m,par[N];
vector<pi> v[N];

void inp() {
    cin >> n >> m;
    for (int i = 0, x,y,z; i < m; i++) {
        cin >> x >> y >> z;
        v[x].pb({y,z});
        v[y].pb({x,z});
    }
}

void dij(int s, int t) {
    vector<ll> d(n+1,LLINF);
    d[s] = 0;
    par[s] = 1;
    priority_queue<pi,vector<pi>,greater<pi>> q;
    q.push({0,s});
    while(!q.empty()) {
        auto [i,j] = q.top();
        q.pop();
        if (i > d[j]) {
            continue;
        }
        for (auto [x,y] : v[j]) {
            if (d[x] > d[j] + y) {
                d[x] = d[j] + y;
                q.push({d[x],x});
                par[x] = j;
            }
        }
    }
    if (d[n] == LLINF) {
        cout << "-1";
    } else {
        vi ans;
        while(1) {
            ans.pb(t);
            if (t == 1) break;
            t = par[t];
        }
        reverse(all(ans));
        for (auto it : ans) cout << it << " ";
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(name ".inp", "r")) {
        freopen(name ".inp","r",stdin);
        freopen(name ".out","w",stdout);
    }
    inp();
    dij(1,n);
    return 0;
}

