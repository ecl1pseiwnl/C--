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
#define all(x) (x).begin(),(x).end
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

int n, k, a[1005], dp[1005];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    dp[1] = dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        a[x] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] == 1) continue;
        dp[i] = (dp[i-1] + dp[i-2]) % 13051984;
    }
    cout << dp[n];
    return 0;
}
