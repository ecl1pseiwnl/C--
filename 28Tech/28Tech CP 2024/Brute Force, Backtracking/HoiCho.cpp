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
    ll n,t;
    cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int minv = *min_element(a,a+n);
    ll res = 0;
    while(t >= minv) {
        ll cnt = 0, s = 0;
        for (int i = 0; i < n; i++) {
            if (t >= a[i] + s) {
                s += a[i];
                cnt++;
            }
        }
        if (s != 0) {
            res += (t / s) * cnt;
            t %= s;
        }
    }
    cout << res;
    return 0;
}
