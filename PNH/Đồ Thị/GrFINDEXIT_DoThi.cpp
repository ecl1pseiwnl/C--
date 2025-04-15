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
const double PI = 3.141592653589793238463;
#define bmask(x,i) (((x) >> (i)) & 1)
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
ll __lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
const int EPS = -1e9;
constexpr int MOD = 1e9+7;
constexpr int32_t IINF = 0x3f3f3f3f;
constexpr int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e3+7;
int n,m,tf,dx[]={1,-1,0,0},dy[] ={0,0,1,-1};
pair<int,int> st,par[N][N];
vector<pair<int,int>> v;
char a[N][N];

void f(int i, int j) {
    vector<int> c;
    while(i != st.first || j != st.second) {
        v.push_back({i,j});
        auto p = par[i][j];
        i = p.first;
        j = p.second;
    }
    v.push_back({i,j});
    reverse(v.begin(),v.end());
}

void bfs(int i, int j) {
    queue<pair<int,int>> q;
    q.push({i,j});
    a[i][j] = 'X';
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        int x = it.first, y = it.second;
        if (x == 1 || x == n || y == 1 || y == m) {
            f(x,y);
            tf = 1;
            return void();
        }
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.') {
                par[nx][ny] = {x,y};
                a[nx][ny] = '#';
                q.push({nx,ny});
            }
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'E') st = {i,j};
        }
    }
    bfs(st.first,st.second);
    if (tf) {
        cout << "YES\n";
        for (auto it : v) cout << it.first << " " << it.second << endl;
    } else {
        cout << "NO\n";
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
