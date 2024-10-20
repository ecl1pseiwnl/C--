#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define ms(a,n) memset(a, n,sizeof(a))
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> t(n+1), r(n), dp(n+1,0);
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i < n; i++) cin >> r[i];
    dp[1] = t[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i-1] + t[i], dp[i-2]+ r[i-1]);
    }
    cout << dp[n];
    return 0;
}
