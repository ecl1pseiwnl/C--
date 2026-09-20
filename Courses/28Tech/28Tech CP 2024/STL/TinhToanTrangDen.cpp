#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 10000000007
#define endl "\n";
#define mp make_pair
#define pb push_back


int main() {
    #ifndef ONLINE_JUDGE

    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >>a[i][j];
        }
    }
    vector<long long> f(55,1);
    for(int i=1;i<55;i++)
    {
        f[i]=f[i-1]*2;
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==1)
            {
                cnt++;
            }
        }
        ans+=f[cnt]-1+f[m-cnt]-1;
    }

    for(int j=0;j<m;j++)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(a[i][j]==1)
            {
                cnt++;
            }
        }
        ans+=f[cnt]-1+f[n-cnt]-1;
    } cout << ans-n*m;
    return 0;
}
