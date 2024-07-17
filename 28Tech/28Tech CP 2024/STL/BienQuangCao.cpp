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
    vector<int> a(n);
    for(int i=1;i<=n;i++) cin >> a[i];
    stack<int> st;
    int right[n+1];
    int left[n+1];
    for(int i=1;i<=n;i++)
    {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(st.empty())
        {
            left[i]=0;
        }
        else
        {
            left[i]=st.top();
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n;i>=1;i--)
    {
        while(!st.empty() && a[st.top()]>=a[i]) st.pop();
        if(st.empty())
        {
            right[i]=n+1;
        }
        else
        {
            right[i]=st.top();
        }
        st.push(i);
    }

    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        int cmp=right[i]-left[i]-1;
        ans=max(ans,1ll*cmp*a[i]);
    }
    cout << ans;

    return 0;
}
