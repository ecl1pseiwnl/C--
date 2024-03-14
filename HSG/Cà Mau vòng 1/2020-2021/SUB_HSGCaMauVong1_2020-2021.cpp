#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,minv = INT_MAX,i = 0;
    vi v;
    cin >> n;
    int a[n];
    for (int i =0; i < n; i++ ) cin >> a[i];
    while (i < n) {
        int sum = a[i];
        if (sum % 2021 == 0) {
            v.pb(sum);
        } else if (sum % 2021 != 0) {
            for (int j = i+1; j < n; j++) {
                sum += a[j];
                if (sum % 2021 == 0) {
                    v.pb(sum);
                    break;
                }
            }

        }
        i++;
    }
    for (auto it : v) {
        minv = min(it,minv);
    }
    cout << minv;
    return 0;
}
