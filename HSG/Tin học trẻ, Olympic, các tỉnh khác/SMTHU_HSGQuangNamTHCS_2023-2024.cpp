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

ll sol(int u) {
    ll s = 0;
    for (int i = 1; i <= sqrt(u); i++) {
        if (u % i == 0) {
            s += i;
            if (u / i != i) s += u/i;
        }
    }
    return s;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vi v(n);
    for (auto &it : v) cin >> it;
    for (auto it : v) cout << sol(it) << " ";
    return 0;
}
