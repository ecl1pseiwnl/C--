#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define endl "\n";
#define mp make_pair
#define pb push_back

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n];
    vi v, z;
    for (auto& it : a) cin >> it;
    for (int i = 0; i < n; i++) {
        if (i < k - 1) {
            v.pb(a[i]);
        }
        if (i > k - 1) {
            z.pb(a[i]);
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    sort(z.begin(), z.end());
    for (auto it : v) cout << it << " ";
    cout << a[k - 1] << " ";
    for (auto it : z) cout << it << " ";
}
