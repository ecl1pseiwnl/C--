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
    int n,m,k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int l = 0, r = 0, ans = 0;
    while (l < n && r < m) {
        if (abs(a[l] - b[r]) <= k) {
            l++;
            ans++;
            r++;
        }
        else if (a[l] < b[r]) {
            l++;
        } else r++;
    }
    cout << ans;
    return 0;
}
