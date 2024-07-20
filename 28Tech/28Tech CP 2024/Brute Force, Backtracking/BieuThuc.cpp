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

int n,m,ans, a[10];

void dq(int i, ll s) {
    if (i == n - 1) {
        ans += s == 0;
        return;
    }
    dq(i+1,(s+a[i+1])%m);
    dq(i+1,(s-a[i+1])%m);
    dq(i+1,(s*a[i+1])%m);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        ans = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        dq(0,a[0]%m);
        cout << ans << endl;
    }
    return 0;
}
