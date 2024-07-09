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

ll binpower(ll a, ll b, ll m) {
    ll ans = 1;
    for (;b>0;b/=2) {
        if(b&1) ans = ans * a % m;
        a = a * a % m;
    }
    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        ll a,b,c;
        cin >> a >> b >> c;
        ll k = binpower(b,c,MOD-1);
        cout << binpower(a,k,MOD) << "\n";
    }
    return 0;
}
