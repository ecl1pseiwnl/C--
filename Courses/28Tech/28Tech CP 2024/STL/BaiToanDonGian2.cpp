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
int f(int n)
{
    if(n==0) return 0;
    if(n%2==0) return f(n/2);
    return f(n/2)+1;
}
int main() {
    #ifndef ONLINE_JUDGE

    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int>a(n);
    for(auto &x : a) cin >> x;
    vector<int>cnt(30,0);
    for(int i=0;i<n;i++)
    {
        cnt[f(a[i])]++;
    }
    long long ans=0;
    for(int i=0;i<30;i++)
    {
        ans+=(long long)cnt[i]*(cnt[i]-1)/2;
    }
    cout << ans;

    return 0;
}
