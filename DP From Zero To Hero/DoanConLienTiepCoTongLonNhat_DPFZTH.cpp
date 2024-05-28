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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n+1), dp(n+1), len(n+1);
    dp[0] = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = dp[i-1] + a[i];
        len[i] = min(len[i-1], dp[i]);
    }
    ll ans = -1e18;
    for (ll i = k; i <= n; i++) {
        ans = max(ans,dp[i] - len[i-k]);
    }
    cout << ans;
    return 0;
}
