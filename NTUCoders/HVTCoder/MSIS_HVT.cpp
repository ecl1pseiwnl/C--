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
    int n, ans = INT_MIN;
    cin >> n;
    vector<int> a(n+1), dp(n+1,1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int tmp = a[i];
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                tmp += a[j];
            }
        }
        ans = max(tmp,ans);
    }
    cout << ans;
    return 0;
}
