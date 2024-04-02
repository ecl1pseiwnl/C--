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
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == s) {
            for (int j = 1; j <= m; j++) {
                cout << a[t][j] << " ";
            }
        }
        else if (i == t) {
            for (int j = 1; j <= m; j++) {
                cout << a[s][j] << " ";
            }
        }
        else {
            for (int j = 1; j <= m; j++) {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}