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
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int& it : a) cin >> it;
    for (int& it : b) cin >> it;
    int i = 0, j = 0;
    ll ans = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            i++;
            continue;
        }
        else if (a[i] > b[j]) {
            j++;
            continue;
        }
        int cnt1 = 0, cnt2 = 0;
        while (i < n && (a[i] == b[j])) {
            ++cnt1;
            i++;
        }
        int tmp = a[i - 1];
        while (j < m && (tmp == b[j])) {
            ++cnt2;
            j++;
        }
        ans += 1ll * cnt1 * cnt2;
    }
    cout << ans;
    return 0;
}