#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
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
int f[N], inv[N];

ll binpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (1ll*ans*a) % MOD;
        a = (1ll*a*a) % MOD;
        b >>=1;
    }
    return ans;
}

void prep() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = (1ll*f[i-1] * i) % MOD;
    }
    inv[N-1] = binpow(f[N-1],MOD-2);
    for (int i = N-2; i >= 0; i--) {
        inv[i] = (1ll*inv[i+1]*(i+1)) % MOD;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    prep();
    string s;
    cin >> s;
    map<char,int> m;
    for (auto it : s) {
        m[it]++;
    }
    int sz = s.size();
    ll res = f[sz];
    for (auto [x,y] : m) {
        res = (1ll*res*inv[y]) % MOD;
    }
    cout << res;
    return 0;
}
