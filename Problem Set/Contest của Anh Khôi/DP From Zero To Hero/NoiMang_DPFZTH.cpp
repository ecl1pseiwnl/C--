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
    int n;
    cin >> n;
    vector<int> a(n+1), dp(n+1);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    dp[2] = a[1];
    dp[3] = dp[2] + a[2];
    for (int i = 4; i <= n; i++) {
        dp[i] = min(dp[i-1] + a[i-1], dp[i-2] + a[i-1]);
    }
    cout << dp[n];
    return 0;
}
