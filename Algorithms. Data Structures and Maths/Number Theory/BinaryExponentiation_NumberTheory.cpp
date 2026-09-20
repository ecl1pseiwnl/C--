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
const int MOD = 1e7;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;

ll binpow(ll a, ll b) {
    ll res = 1;
    while(b>0) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    cout << binpow(n,k) % MOD;
    return 0;
}
