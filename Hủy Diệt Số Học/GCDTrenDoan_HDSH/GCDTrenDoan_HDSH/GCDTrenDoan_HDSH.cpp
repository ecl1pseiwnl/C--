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
	cin.tie(NULL);
    int n, k, maxv = 1, a[1010];
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n - k + 1; i++) {
        int gcd = a[i];
        for (int j = i + 1; j <= i + k - 1; j++) {
            gcd = __gcd(gcd, a[j]);
        }
        maxv = max(maxv, gcd);
    }
    cout << maxv;
    return 0;
}