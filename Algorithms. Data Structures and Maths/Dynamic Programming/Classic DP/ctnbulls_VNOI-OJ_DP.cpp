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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vi dp(100005+1);
    dp[0] = 1;
    for (int i = 1; i <= k; i++) dp[i] = i+1;
    for (int i = k+1; i <= n; i++) dp[i] = (dp[i-1] + dp[i-k-1]) % 2111992;
    cout << dp[n];
    return 0;
}
