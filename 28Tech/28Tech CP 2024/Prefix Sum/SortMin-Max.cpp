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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi v(n+1);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            v[i] = x;
        }
        int l = (n+1)/2, r = (n+2)/2;
        while(l >= 1 && r <= n && ((l == r) || (v[l] < v[l+1] && v[r] > v[r-1]))) {
            l--; r++;
        }
        cout << (n - (r - l - 1))/2 << endl;
    }
    return 0;
}
