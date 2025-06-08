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

const int N = 2e6;
int f[N],inv[N];
ll binpow(ll a, ll b) {
    a %= MOD;
    ll ans = 1;
    while(b) {
        if (b&1) ans = ans * a % MOD;
        a = a*a % MOD;
        b /= 2;
    }
    return ans;
}

void prep() {
    f[0] = 1;
    for (int i = 1; i <= N; i++) {
        f[i] = (1LL * f[i-1] * i) % MOD;
    }
    inv[N] = binpow(f[N],MOD-2);
    for (int i = N-1; i >= 1; i--) {
        inv[i] = (1LL * inv[i+1] * (i+1)) % MOD;
    }
}

ll C(ll n, ll k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return (1LL * f[n] * inv[k] % MOD) * inv[n-k] % MOD;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    prep();
    ll n,k;
    cin >> n >> k;
    cout << C(n+k-1,n-1);
    return 0;
}
