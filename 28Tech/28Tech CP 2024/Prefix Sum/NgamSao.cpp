#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
ll lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
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
const int32_t INF32 = 0x3f3f3f3f;
const int64_t INF64 = 0x3f3f3f3f3f3f3f3f;

const int N = 1e6+5, M = 1e2+10;
int n,q,c,x[N],y[N],s[N], f[20][M][M];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q >> c;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> s[i];
        f[s[i]][x[i]][y[i]]++;
    }
    for (int i = 0; i <= c; i++) {
        for (int j = 1; j < M; j++) {
            for (int k = 1; k < M; k++) {
                f[i][j][k] = f[i][j][k-1] + f[i][j-1][k] + f[i][j][k] - f[i][j-1][k-1];
            }
        }
    }
    while(q--) {
        int t,x1,x2,y1,y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int cur = 0;
        for (int i = 0; i <= c; i++) {
            int nc = (i+t) % (c+1);
            int cnt = f[i][x2][y2] - f[i][x2][y1-1] - f[i][x1-1][y2] + f[i][x1-1][y1-1];
            cur += nc * cnt;
        }
        cout << cur << endl;
    }
    return 0;
}
