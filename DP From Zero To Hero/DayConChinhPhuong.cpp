#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef map<int,int> mii;
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

bool cp(ll n)
{
    ll h=sqrt(n);
    return h*h==n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n;
    cin >> n;
    ll a[n+1],b[n+1];
    for(ll i=1;i<=n;i++)
    {
        cin >> a[i];
        b[i]=1;
        for(ll j=max(i-10,1ll);j<i;j++)
        {
            ll ans=abs(a[j]-a[i]);
            if(cp(ans)&&ans!=0)
            {
                b[i]=max(b[i],b[j]+1);
            }
        }
    }
    cout << *max_element(b+1,b+1+n);
    return 0;
}
