#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, maxv = INT_MIN;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int sum = a[i];
        for (int j = i + 1; j < n; j++) {
            sum += a[j];
            maxv = max(sum, maxv);
        }
    }
    cout << maxv;
    return 0;
}
