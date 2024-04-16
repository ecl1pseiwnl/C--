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
    int n;
    cin >> n;
    int a[n];
    vector<ll> v;
    for (auto& it : a) cin >> it;
    for (int i = 0; i < n; i++) {
        ll ans = a[i], cnt = 1;
        for (int j = i + 1; j < n; j++) {
            if (cnt % 3 == 0) {
                v.pb(ans);
            }
            ans += a[j];
            cnt++;
        }
    }
    cout << *max_element(v.begin(), v.end());
    return 0;
}
