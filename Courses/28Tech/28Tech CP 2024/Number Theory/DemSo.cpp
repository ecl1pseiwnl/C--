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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k);
    for (auto &it:a) cin >> it;
    ll ans = 0;
    for (int mask = 1; mask < (1<<k); mask++) {
        ll res = 1, cnt = 0;
        for (int i = 0; i < k; i++) {
            if (mask & (1<<i)) {
                res*=a[i];
                ++cnt;
            }
        }
        if (cnt & 1) {
            ans += (n/res);
        } else ans -= (n/res);
    }
    cout << ans;
    return 0;
}
