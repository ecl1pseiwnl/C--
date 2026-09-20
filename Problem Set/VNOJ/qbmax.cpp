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

int n,m, a[105][105], dp[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int ans = -1e9;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        dp[0][i] = dp[n+1][i] = -1e9;
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = max(dp[i-1][j-1], max(dp[i][j-1], dp[i+1][j-1])) + a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = max(dp[i][m], ans);
    }
    cout << ans;
    return 0;
}
