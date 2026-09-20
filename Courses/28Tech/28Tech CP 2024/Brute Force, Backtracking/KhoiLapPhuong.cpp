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
const int32_t INF32 = 0x3f3f3f3f;
const int64_t INF64 = 0x3f3f3f3f3f3f3f3f;

const int N = 1e6+10;
int n,k,s,ans, a[N], f[N];
unordered_map<int,ll> cnt[30];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    f[0] = 1;
    for (int i = 1; i < 19; i++) {
        f[i] = f[i-1] * i;
    }
    int n1 = n / 2;
    int n2 = n - n1;
    vector<pair<ll,int>> v;
    for (int mask = pow(3,n1)-1; mask >= 0; mask--) {
        ll sum = 0;
        int d = 0;
        for (int i = 0, x = mask; i < n1; x /= 3, i++) {
            int c = x % 3;
            if (c == 0) {
                continue;
            } else if (c == 1) {
                sum += a[i];
            } else if (c == 2) {
                if (a[i] > 18) {
                    sum = INF64;
                    break;
                }
                sum += f[a[i]];
                d++;
            }
        }
        if (sum <= s && d <= k) {
            v.emplace_back(sum,d);
        }
    }
    for (int mask = pow(3,n2)-1; mask >= 0; mask--) {
        ll sum = 0;
        int d = 0;
        for (int i = 0, x = mask; i < n2; x/=3,i++) {
            int c = x % 3;
            if (c == 0) {
                continue;
            } else if (c == 1) {
                sum += a[i+n1];
            } else if (c == 2) {
                if (a[i] > 18) {
                    sum = INF64;
                    break;
                }
                sum += f[a[i+n1]];
                d++;
            }
        }
        if (sum <= s && d <= k) {
            cnt[d][sum]++;
        }
    }
    for (auto [u,v] : v) {
        auto sdiff = s - u;
        auto kdiff = k - v;
        for (int i = 0; i <= kdiff; i++) {
            ans += cnt[i][sdiff];
        }
    }
    cout << ans << endl;
    return 0;
}
