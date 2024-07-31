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

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi v(n+2);
        for (int i = 1; i <= n; i++) cin >> v[i];
        vi f(n+2,-INF32), g(n+2,-INF32);
        for (int i = 1; i <= n; i++) {
            f[i] = max(f[i-1], v[i] + i);
        }
        for (int i = n; i >= 1; i--) {
            g[i] = max(g[i+1], v[i] - i);
        }
        int ans = -INF32;
        for (int i = 2; i <= n-1; i++) {
            ans = max(ans, v[i] + f[i-1] + g[i+1]);
        }
        cout << ans << endl;
    }
    return 0;
}
