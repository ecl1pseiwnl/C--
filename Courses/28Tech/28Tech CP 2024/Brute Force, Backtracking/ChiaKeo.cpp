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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& it: a) cin >> it;
    ll s = accumulate(all(a),0LL);
    int n1 = n / 2;
    int n2 = n - n1;
    vi u,v;
    for (int mask = 0; mask < (1 << n1); mask++) {
        ll s = 0;
        for (int i = 0; i < n1; i++) {
            if ((mask>>i) & 1) {
                s += a[i];
            }
        }
        u.ep(s);
    }
    for (int mask = 0; mask < (1 << n2); mask++) {
        ll s = 0;
        for (int i = 0; i < n2; i++) {
            if ((mask>>i) & 1) {
                s += a[i+n1];
            }
        }
        v.ep(s);
    }
    ll s2 = s/2, ans = 1e18, cnt = 0;
    sort(all(u));
    sort(all(v));
    int r = v.size() - 1;
    int l = v.size() - 1;
    for (auto& it : u) {
        if (it > s2) continue;
        while(r >= 0 && v[r] + it > s2) r--;
        while(l >= 0 && v[l] >= v[r]) l--;
        l++;
        if (ans > s - (it + v[r])* 2) {
            ans = s - (it + v[r]) * 2;
            cnt = r - l + 1;
        } else if (ans == s - (it + v[r])* 2) {
            cnt += r - l + 1;
        }
    }
    if (ans == 0) cnt /= 2;
    cout << ans << " " << cnt << endl;
    return 0;
}
