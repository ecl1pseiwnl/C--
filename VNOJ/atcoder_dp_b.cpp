#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
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
    int n,k;
    cin >> n >> k;
    vector<ll> a(n+1), dp(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[1] = dp[0] = 0;
    for (ll i = 2; i <= n; i++) {
        dp[i] = LLONG_MAX;
        for (ll j = i - 1; j >= max(1*1ll,i-k); j--) {
            dp[i] = min(dp[i],dp[j] + abs(a[j]-a[i]));
        }
    }
    cout << dp[n];
    return 0;
}
