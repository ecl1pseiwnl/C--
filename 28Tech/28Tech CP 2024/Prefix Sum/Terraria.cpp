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
#define int long long
const int N = 1e5+10;
int l[N], r[N];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        l[i] = max(0LL,a[i-1] - a[i]);
    }
    for (int i = n; i >= 1; i--) {
        r[i] = max(0LL,a[i+1] - a[i]);
    }
    for (int i = 1; i <= n; i++) {
        l[i] += l[i-1];
    }-
    for (int i = n; i >= 1; i--) {
        r[i] += r[i+1];
    }
    while(m--) {
        int s,t;
        cin >> s >> t;
        if (s>t) {
            cout << r[t] - r[s] << endl;
        } else cout << l[t] - l[s] << endl;
    }
    return 0;
}
