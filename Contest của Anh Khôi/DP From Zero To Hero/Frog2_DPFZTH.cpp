#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    ll a[n + 1], dp[n + 1];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = dp[1] = 0;
    for (ll i = 2; i <= n; i++) {
        dp[i] = LLONG_MAX;
        for (ll j = i - 1; j >= max(1 * 1ll, i - k); j--) {
            dp[i] = min(dp[i], dp[j] + abs(a[j] - a[i]));
        }
    }
    cout << dp[n];
    return 0;
}
