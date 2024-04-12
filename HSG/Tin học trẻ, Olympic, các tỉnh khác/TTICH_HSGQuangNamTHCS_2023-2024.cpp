#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 10000000007
#define endl "\n";
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        ll ans1 = 1, ans2 = 1;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 0; i < n; i++) {
            ans1 *= a[i];
        }
        for (int i = 0; i < m; i++) {
            ans2 *= b[i];
        }
        if (ans1 == ans2) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}
