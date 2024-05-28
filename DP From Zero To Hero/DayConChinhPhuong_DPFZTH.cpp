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

bool check(int n) {
    int tmp = sqrt(n);
    if (tmp*tmp == n) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n+1), dp(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        dp[i] = 1;
        for (int j = min(i-10, INT_MAX); j < i; j++) {
            int ans = abs(v[i] - v[j]);
            if (check(ans) && ans != 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp.begin(),dp.end());
    return 0;
}
