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
    ll n; cin >> n;
    ll cmp = 0;
    for(ll i=1;i<=sqrt(n);i++) {
        cmp+=i*(n/i)%MOD;
        cmp%=MOD;
    }
    ll l=sqrt(n)+1;
    for(ll i=sqrt(n);i>=1;i--) {
        ll r=n/i;
        long long ans=((r+l)%MOD)*((r-l+1)%MOD)%MOD*((MOD+1)/2)%MOD;
        cmp+=ans*i%MOD;
        cmp%=MOD;
        l=r+1;
    }
    cout << cmp;
    return 0;
}
