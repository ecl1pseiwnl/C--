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

ll binpow(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(1ll*ans*a)%MOD;
        a=(1ll*a*a)%MOD;
        b>>=1;
    }
    return ans;
}
void prepare()
{
    f[0]=1;
    for(int i=1;i<N;i++)
    {
        f[i]=(1ll*f[i-1]*i)%MOD;
    }
    inv[N-1]=binpow(f[N-1],MOD-2);
    for(int i=N-2;i>=0;i--)
    {
        inv[i]=(1ll*inv[i+1]*(i+1))%MOD;
    }
}
ll C(ll k,ll n)
{
    if(k>n) return 0;
    return ((1ll*f[n]*inv[n-k])%MOD*inv[k])%MOD;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >>t;
    prepare();
    while(t--)
    {
        int n,m,k; cin >> n >> m >> k;
        vector<int>cnt(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int x; cin >> x;
            cnt[x]++;
        }
        vector<int>prf(n+3,0);
        for(int i=1;i<=n;i++)
        {
            prf[i]=prf[i-1]+cnt[i];
        }
        ll cmp=0;
        for(int mi=1;mi<=n;mi++)
        {
            long long ma=min(mi+k,n);
            ll nhan=prf[ma]-prf[mi-1];
            ll knhan=prf[ma]-prf[mi];
            cmp=(cmp+C(m,nhan)-C(m,knhan)+MOD)%MOD;

        }
        cout <<cmp<<endl;
    }
}
