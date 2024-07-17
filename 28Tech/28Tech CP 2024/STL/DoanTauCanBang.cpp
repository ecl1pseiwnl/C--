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
    int n; cin >> n;
    vector<int>a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(),a.end());
    int s=accumulate(a.begin(),a.end(),0);
    int x=n-(s%n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i<x)
        {
            ans+=abs(a[i]-(s/n));
        }

        else ans+=abs(a[i]-(s/n+1));
    }
    cout << ans/2;

    return 0;
}
