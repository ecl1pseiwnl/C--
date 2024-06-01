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
    ll n, cur = 0,maxv = 0;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        cur += a[i];
        if (cur < 0) {
            cur = 0;
        }
        maxv = max(maxv, cur);
    }
    cout << maxv;
    return 0;
}



// Cach 2:
/*
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr); cout.tie(nullptr);
        ll n;
        cin >> n;
        ll a[n+1], dp[n+1];
        dp[0] = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            dp[i] = max(dp[i-1] + a[i], a[i]);
        }
        cout << *max_element(dp+1, dp+n+1);
        return 0;
    }
*/
