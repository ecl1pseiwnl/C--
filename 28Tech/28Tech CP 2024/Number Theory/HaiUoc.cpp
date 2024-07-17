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

const int N=1e7+2;

int pac[N];
void prepare()
{
    for(int i=1;i=N;i++)
    {
        pac[i]=i;
    }
    for(int i=2;i=sqrt(N);i++)
    {
        if(pac[i]==i)
        {
            for(int j=i2;j=N;j+=i)
            {
                pac[j]=i;
            }
        }
    }

}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    prepare();
    int n; cin  n;
    vectorinta(n);
    for(int &x  a) cin  x;
    vectorpairint,int kq(n);
    for(int i=0;in;i++)
    {
        mapint,int mp;
        int x=a[i];
        while(x!=1)
        {
            mp[pac[x]]++;
            x=pac[x];
        }
        if(mp.size()==1)
        {
            kq[i]={-1,-1};
            continue;
        }
        kq[i].first=1;
        auto [p,q]=mp.begin();
        for(int j=1;j=q;j++)
        {
            kq[i].first=p;
        }
        kq[i].second=a[i]kq[i].first;
    }
    for(int i=0;in;i++)
    {
        cout kq[i].first n[i == n-1];
    }
      for(int i=0;in;i++)
    {
        cout kq[i].second n[i == n-1];
    }

    return 0;
}
