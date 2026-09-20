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

const int N = 1e3+10;
int cnt[N][N], ans;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x,y,u,v;
        cin >> x >> y >> u >> v;
        cnt[x][y]++;
        cnt[u][v]++;
        cnt[x][v]--;
        cnt[u][y]--;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            cnt[i][j] += cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
            ans += cnt[i][j] == m;
        }
    }
    cout << ans;
    return 0;
}
