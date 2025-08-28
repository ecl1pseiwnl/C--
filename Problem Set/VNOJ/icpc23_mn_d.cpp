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

const int N = 507;
int ty,n,k,v[N][N],dp[N][N], dx[] = {1,-1,0,0}, dy[] = {0,0,-1,1};

int bfs(int k) {
    ms(dp,-1);
    deque<pi> q;
    q.push_front({1,1});
    dp[1][1] = (v[1][1] < k ? 1 : 0);
    while(q.size()) {
        auto [x,y] = q.front();
        q.pop_front();
        REP(i,4) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx > 0 && nx <= n && ny > 0 && ny <= n && dp[nx][ny] == -1) {
                int w = (v[nx][ny] < k ? 1 : 0);
                dp[nx][ny] = dp[x][y] + w;
                if (w == 0) {
                    q.push_front({nx,ny});
                } else {
                    q.pb({nx,ny});
                }
            }
        }
    }
    return dp[n][n];
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> ty;
    if (ty == 1) {
        cin >> n >> k;
        FOR(i,1,n) {
            FOR(j,1,n) {
                cin >> v[i][j];
            }
        }
        cout << bfs(k) << endl;
    } else {
        cin >> n;
        FOR(i,1,n) {
            FOR(j,1,n) {
                cin >> v[i][j];
            }
        }
        int l = 0, r = 5000;
        while (r-l>1) {
            int m = (l+r)/2;
            if (bfs(m) == 0) {
                l = m;
            } else r = m;
        }
        cout << l << endl;
    }

    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
