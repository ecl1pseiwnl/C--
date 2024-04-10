#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mii;
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> t;
    sort(v.begin(), v.end());
    while (t--) {
        int x;
        cin >> x;
        if (binary_search(v.begin(), v.end(), x)) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}
