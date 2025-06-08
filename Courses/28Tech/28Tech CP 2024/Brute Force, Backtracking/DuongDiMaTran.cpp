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
#define pb push_back
#define endl "\n"
const int MOD = 1e9+7;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;

const int N = 21;
int a[N][N];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n,m,k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int temp = n+m/2;
    int sz = temp/2;
    map<ll, ll> cnt[N][N];
    for (int mask = 0; mask < (1 << sz); mask++) {
        int x = 1, y = 1;
        ll sum = a[x][y];
        for (int i = 0; i < sz; i++) {
            if ((mask>>i) & 1) y++;
            else x++;
            sum ^= a[x][y];
        }
        if (1 <= x && x <= n && 1 <= y && y <= m) cnt[x][y][sum]++;
    }
    sz = temp - sz;
    ll ans = 0;
    for (int mask = 0; mask < (1 << sz); mask++) {
        int x = n, y = m;
        ll sum = a[n][m];
        for (int i = 0; i < sz; i++) {
            if ((mask>>i) & 1) y--;
            else x--;
            sum ^= a[x][y];
        }
        if (1 <= x && x <= n && 1 <= y && y <= m) ans += cnt[x][y][k^sum^a[x][y]];
    }
    cout << ans;
    return 0;
}
