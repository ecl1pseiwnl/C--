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
    ll n, x;
    cin >> n >> x;
    vector<ll> f;
    f.ep(0);
    vector<bool> v(1<<n,false);
    v[0] = true;
    for (int i = 1; i < (1 << n); i++) {
        if ((i ^ x) < (1 << n) && v[i^x]) continue;
        f.ep(i);
        v[i] = true;
    }
    cout << f.size() - 1 << endl;
    for (int i = 1; i < f.size(); i++) {
        int a = f[i] ^ f[i-1];
        cout << a << " ";
    }
    return 0;
}
