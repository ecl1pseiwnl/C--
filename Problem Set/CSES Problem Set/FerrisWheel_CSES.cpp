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
    int n, k, ans = 0;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    int l = 0, r = n-1;
    while(l <= r) {
        if (a[l] + a[r] <= k) {
            ans++;
            l++;
            r--;
        }
        else {
            ans++;
            r--;
        }
    }
    cout << ans;
    return 0;
}
