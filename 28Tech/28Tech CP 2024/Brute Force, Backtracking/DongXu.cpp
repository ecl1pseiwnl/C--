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

const int n = 32;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    vector<ll> c(n);
    c[0] = 2;
    c[1] = 3;
    c[2] = 5;
    for (int i = 3; i < n; i++) {
        c[i] = c[i-1] + c[i-2] + c[i-3];
    }
    vector<ll> a,b;
    for (int i = 0; i < n; i++) {
        if (i < n/2) a.pb(c[i]);
        else b.pb(c[i]);
    }
    vector<pair<ll,int>> u,v;
    int m = a.size();
    for (int mask = 0; mask < (1 << m); mask++) {
        ll s = 0;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if ((mask>>i) & 1) {
                cnt++;
                s += a[i];
            }
        }
        u.pb({s,cnt});
    }
    m = b.size();
    for (int mask = 0; mask < (1 << m); mask++) {
        ll s = 0;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if ((mask>>i) & 1) {
                cnt++;
                s += b[i];
            }
        }
        v.pb({s,cnt});
    }
    sort(all(u));
    sort(all(v));
    while(t--) {
        ll x;
        cin >> x;
        int ans = -1;
        for (const auto& [it,c] : u) {
            if (it > x) break;
            auto p = lower_bound(all(v),make_pair(x-it+1,0));
            if (p != v.begin()) {
                --p;
                if (p->first + it == x) {
                    ans = max(ans,p->second+c);
                }
            }
        }
        if (ans == -1) cout << "HETCUU\n";
        else cout << ans << endl;
    }
    return 0;
}
