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

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a,b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (i < n / 2) a.pb(x);
        else b.pb(x);
    }
    int m = n / 2;
    vector<ll> u,v;
    for (int mask = 0; mask < (1<<m); mask++) {
        ll s = 0;
        for (int i = 0; i < m; i++) {
            if ((mask>>i) & 1) s +=a[i];
        }
        u.pb(s);
    }
    m = n - m;
    for (int mask = 0; mask < (1<<m); mask++) {
        ll s = 0;
        for (int i = 0; i < m; i++) {
            if ((mask>>i) & 1) s +=b[i];
        }
        v.pb(s);
    }
    ll ans = 0;
    sort(all(u));
    sort(all(v));
    for (ll it : u) {
        int l = (int)(lower_bound(all(v),k-it) - v.begin());
        int r = (int)(upper_bound(all(v),k-it) - v.begin());
        ans += (r-l);
    }
    cout << ans;
    return 0;
}
