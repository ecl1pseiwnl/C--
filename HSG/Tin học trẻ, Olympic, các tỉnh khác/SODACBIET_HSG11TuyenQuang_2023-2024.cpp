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
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int tmp = a[i] % 10;
        if (tmp == 6 || tmp == 8) {
            sum += a[i];
        }
    }
    cout << sum;
    return 0;
}