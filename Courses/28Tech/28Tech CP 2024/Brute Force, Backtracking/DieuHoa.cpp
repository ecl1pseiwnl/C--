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

const int N = 25;
int n,m, l[N], r[N], t[N], x[N], y[N], p[N], c[N];

bool check(vi v) {
    for (int i = 1; i <= 100; i++) {
        int cnt = 0;
        for (auto &it : v) {
            if (x[it] <= i && i <= y[it]) {
                cnt += p[it];
            }
        }
        int cntt = 0;
        for (int j = 0; j < n; j++) {
            if (l[j] <= i && i <= r[j]) {
                cntt = t[j];
            }
        }
        if (cnt < cntt) return false;
    }
    return true;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> t[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i] >> p[i] >> c[i];
    }
    int res = INT_MAX;
    for (int mask = 0; mask < (1 << m); mask++) {
        int s = 0;
        vi v;
        for (int i = 0; i < m; i++) {
            if ((mask>>i) & 1) {
                v.ep(i);
                s += c[i];
            }
        }
        if (check(v)) {
            res = min(s,res);
        }
    }
    cout << res;
    return 0;
}
