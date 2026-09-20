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
#define all(x) (x).begin(),(x).end
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

void solve() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            v.emplace_back(i);
            v.emplace_back(n/i);
        }
    }
    for (auto x : v) {
        for (auto y : v) {
            int z = n / x / y;
            if (x != y && y != z && x != z && x > 1 && y > 1 && z > 1 && x*y*z == n) {
                cout << "YES\n" << x << " " << y << " " << z << "\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
