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

const int N = 1e6+5;
int f[N];

ll binpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if (b&1) ans = (1ll * ans * a) % MOD;
        a = (1ll*a*a) % MOD;
        b >>=1;
    }
    return ans;
}

ll C(ll n, ll k) {
    return f[n] * binpow(f[k],MOD-2) % MOD * binpow(f[n-k], MOD-2) % MOD;
}

void prep() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = (1ll*f[i-1]*i) % MOD;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    prep();
    ll n,k;
    cin >> n >> k;
    cout << C(k+n-1,n-1);
    return 0;
}
