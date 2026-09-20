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

#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> a,b;
    for (int i = 0; i < n; i++) {
        int w,v; cin >> w >> v;
        if (i < n / 2) a.pb({w,v});
        else b.pb({w,v});
    }
    vector<pair<ll,ll>> u,v;
    int m = a.size();
    for (int mask = 0; mask < (1<<m); mask++) {
        ll s = 0, val = 0;
        for (int i = 0; i < m; i++) {
            if((mask>>i) & 1) {
                s += a[i].fi;
                val += a[i].sec;
            }
        }
        if (s <= k) u.pb({s,val});
    }
    m = b.size();
    for (int mask = 0; mask < (1<<m); mask++) {
        ll s = 0, val = 0;
        for (int i = 0; i < m; i++) {
            if((mask>>i) & 1) {
                s += b[i].fi;
                val += b[i].sec;
            }
        }
        if (s <= k) v.pb({s,val});
    }
    sort(all(v));
    sort(all(u));
    int j = 0;
    ll ans = 0, maxv = 0;
    for (int i = (int)u.size() - 1; i >= 0; i--) {
        while((j < (int) v.size()) && (u[i].fi + v[j].fi <= k)) {
            maxv = max(maxv,1ll*v[j].sec);
            ++j;
        }
        ans = max(ans,u[i].sec + maxv);
    }
    cout << ans;
    return 0;
}
