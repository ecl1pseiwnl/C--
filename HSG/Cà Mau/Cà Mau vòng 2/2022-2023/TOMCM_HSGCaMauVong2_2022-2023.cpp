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
constexpr int MOD = 1e9+7;
constexpr int32_t IINF = 0x3f3f3f3f;
constexpr int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 2e4+7;
int n,m,s,t,par1[N],par2[N];
vector<pi> v[N];

void dijkstra() {
    vi d1(n+1,IINF),d2(n+1,IINF);
    d1[s] = 0;
    priority_queue<pi,vector<pi>,greater<pi>> q;
    q.push({0,s});
    while(!q.empty()) {
        auto [len,vert] = q.top();
        q.pop();
        if (len > d2[vert]) continue;
        for (auto [x,w] : v[vert]) {
            int k = len + w;
            if (d1[x] > k) {
                d2[x] = d1[x];
                par1[x] = vert;
                d1[x] = k;
                q.push({d1[x],x});
            } else if (d1[x] < k && d2[x] > k) {
                par2[x] = vert;
                d2[x] = k;
                q.push({d2[x],x});
            }
        }
    }
    cout << (d1[t] == IINF ? -1 : d1[t]) << " ";
    cout << (d2[t] == IINF ? -1 : d2[t]) << endl;
    if (d1[t] != IINF) {
        int p = t;
        vi path;
        while(p != s) {
            path.pb(p);
            p = par1[p];
        }
        path.pb(s);
        reverse(all(path));
        for (auto it : path) cout << it << " ";
        cout << endl;
    }
    /*if (d2[t] != IINF) {
        int p = t;
        vi path;
        while(p != s) {
            path.pb(p);
            p = par2[p];
        }
        path.pb(s);
        reverse(all(path));
        for (auto it : path) cout << it << " ";
        cout << endl;
    }*/
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        v[x].pb({y,z});
        v[y].pb({x,z});
    }
    dijkstra();
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
/*
5 7 1 5
1 2 3
1 4 8
2 3 5
2 4 4
3 5 5
4 3 8
4 5 3
*/
