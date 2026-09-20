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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int k, minn = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (i != 0)
        {
            k = a[i] - a[i - 1];
            minn = min(minn, k);
        }
    }
    cout << minn;
    return 0;
}
