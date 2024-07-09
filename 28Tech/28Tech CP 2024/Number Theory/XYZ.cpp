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

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll x,y,z,n;
    cin >> x >> y >> z >> n;
    ll ans = 0, k = lcm(x,lcm(y,z));
    for (int i = 1; i <= n; i++) {
        ll l = (ll)pow(10,i-1), r = (ll)pow(10,i) - 1;
        ll res = (l+k-1)/k*k;
        if (res > r) res = -1;
        ans = (ans + res) % MOD;
        if (ans < 0) ans += MOD;
    }
    cout << ans;
    return 0;
}
