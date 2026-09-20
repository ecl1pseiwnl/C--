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

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vi v(n);
    for (auto &it : v) cin >> it;
    int maxv = *max_element(all(v));
    vi a(maxv+1);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= sqrt(v[i]); j++) {
            if (v[i] % j == 0) {
                a[j]++;
                if (j != v[i] / j) {
                    a[v[i]/j]++;
                }
            }
        }
    }
    for (int i = maxv; i >= 1; i--) {
        if (a[i] > 1) return cout << i, 0;
    }
}
