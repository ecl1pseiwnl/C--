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

ll uoc(int n) {
    ll ans = 0;
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0) {
            ans += i;
        }
    }
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0 && n / i != i) {
            ans += n / i;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        ll b = uoc(a[i]);
        a[i] = b;
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
